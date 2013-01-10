/* Programa: huffman.c (Codificação de Huffman)      */
/* Autor: Alexandre N. de Medeiros       RA115966    */
/* Disciplina: MC602                     Turma E     */
/* Data: 30/out/2011                                 */
/* Revisado: 10/jan/2013                             */
/*       Implementação com bits verdadeiros.         */

/* 
 * huffman.c - Implementação do algoritmo de Huffman. Caso a constante
 *             PSEUDO_BITS esteja definida no arquivo "huffman.h", o
 *             teste será feito com caracteres '0's e '1's.
 */

#include <string.h>
#include <stdio.h>
#include "huffman.h"

/* Constante */
#define NUM_FOLHAS 256

/* Máscaras Binárias*/
#define b0 1
#define b1 2
#define b2 4
#define b3 8
#define b4 16
#define b5 32
#define b6 64
#define b7 128

typedef struct RegArvHuf *ArvHuf;

typedef enum TipoFilho { FilhoEsq = 0, FilhoDir = 1, Indeterminado } TipoFilho;

typedef struct RegArvHuf {
    int peso;                      /* peso da árvore */
    char letra;                    /* somente no caso de folha */
    TipoFilho tipoFilho;           /* indica a relação com o pai */
    ArvHuf esq,dir,pai;            /* subárvores e pai */
} RegArvHuf;

ArvHuf Arvore;   /*  As funções abaixo construirão e utilizarão a
                  *  árvore que será apontada por esta variável
                  */

ArvHuf Folhas[NUM_FOLHAS];   /* Apontadores para as folhas da
                              * árvore 'Arvore'
                              */


/* --------------------------------------------------------- */
/* Funções auxiliares sugeridas para este módulo             */
/* --------------------------------------------------------- */

ArvHuf CriaFolha(char letra, int peso)
{
    /* Cria uma folha da árvore; devolve NULL se não há mais memória. */

    ArvHuf f = NULL;

    f = MALLOC(sizeof(RegArvHuf));

    /* Se foi possivel fazer a alocação, inicializa a folha. */
    if(f != NULL) {
        f->peso = peso;
        f->letra = letra;
        f->tipoFilho = Indeterminado;
        f->esq = f->dir = f->pai = NULL;
    }

    return f;

} /* CriaFolha */

ArvHuf CombinaArvs(ArvHuf esq, ArvHuf dir)
{
    /* Combina duas subárvores numa única árvore cujo peso é a soma dos
     * pesos das subárvores; devolve NULL se não há mais memória.
     */

    ArvHuf no = NULL;

    no = MALLOC(sizeof(RegArvHuf));

    /* Se foi possivel fazer a alocação, inicializa o nó. */
    if(no != NULL) {
        no->peso = esq->peso + dir->peso;
        no->letra = 0;
        no->tipoFilho = Indeterminado;
        no->esq = esq;
        no->dir = dir;
        no->pai = NULL;

        dir->tipoFilho = FilhoDir;
        dir->pai = no;

        esq->tipoFilho = FilhoEsq;
        esq->pai = no;

    }

    return no;

} /* CombinaArvs */

void DesceHeap(ArvHuf fl[], int n)
{
    /* Desce o elemento da raiz fl[0] para dentro da fila de prioridade de
     * 'n' elementos.
     */

    ArvHuf x = fl[0];
    int m = 0, k = 2 * m + 1;

    while (k < n) {
        if ((k < n - 1) && (fl[k]->peso > fl[k + 1]->peso))
            k++;
        if (x->peso > fl[k]->peso) {
            fl[m] = fl[k];
            m = k;
            k = 2 * k + 1;
        } else
            break; /* while */
    }

    fl[m] = x;

    return;
} /* DesceHeap */

void SobeHeap(ArvHuf fl[], int m)
{
    /* Sobe o último elemento fl[m] para dentro da fila de prioridade */

    ArvHuf x = fl[m];
    int j = (m - 1)/2;

    while ((m > 0) && (fl[j]->peso > x->peso)) {
        fl[m] = fl[j];
        m = j;
        j = (j - 1)/2;
    }

    fl[m] = x;

    return;
} /* SobeHeap */

void ConstroiHeap(ArvHuf fl[], int n)
{
    /* Transforma o vetor 'fl' de 'n' elementos numa fila de
     * prioridades, com peso mínimo na raiz.
     */

    int i;

    for (i = 1; i < n; i++)
        SobeHeap(fl, i);

    return;
} /* ConstroiHeap */

ArvHuf Minimo(ArvHuf fl[], int *n)
{
    /* Devolve o elemento mínimo da fila de prioridade fl' (raiz) e o
     * elimina da estrutura; acerta o valor de 'n'.
     */

    ArvHuf x = fl[0];
    (*n)--;
    fl[0] = fl[*n];

    DesceHeap(fl, *n);

    return x;
} /* Minimo */

void LiberaArvoreAux(ArvHuf p)
{
    /* Libera a memória dinâmica ocupada pela árvore 'p'. */

    if(p == NULL)
        return;

    /* Percuso pos-ordem. */
    LiberaArvoreAux(p->esq);
    LiberaArvoreAux(p->dir);
    FREE(p);

    return;

} /* LiberaArvoreAux */

/* --------------------------------------------------------- */
/*  Outras funções auxiliares podem ser definidas aqui       */
/* --------------------------------------------------------- */

void InitVetFreq(int *freq)
{
    /* Inicializa o vetor frequência com '0' em todas suas posições. */

    int i;

    for (i = 0; i < NUM_FOLHAS; i++)
        freq[i] = 0;

    return;
} /* InitVetFreq */

void ConstroiVetFreq(int *freq, unsigned char txt[], int lim)
{
    /* Apartir do texto, cria o vetor de frequencias. */

    int i;

    for (i = 0; i < lim; i++)
        freq[txt[i]]++;

    return;
} /* ConstroiVetFreq */

void InitFolhas(int *freq)
{
    /* Inicializa o vetor 'Folhas' com base no vetor de frequências,
     * elementos de frequência '0' são inicializados como apontador
     * para 'NULL'.
     */

    int i;

    for (i = 0; i < NUM_FOLHAS; i++)
        if (freq[i])
            Folhas[i] = CriaFolha((char) i, freq[i]);
        else
            Folhas[i] = NULL;

    return;
} /* InitFolhas */

int InitHeap(ArvHuf *heap, int *freq)
{
    /* Insere todos elementos no vetor 'heap', sem organizá-lo com um heap,
     * retornando o número de elementos no mesmo.
     */

    int i, num_elems = 0;

    for (i = 0; i < NUM_FOLHAS; i++)
        if(freq[i]) {
            heap[num_elems] = Folhas[i];
            num_elems++;
        }

    return num_elems;
} /* InitHeap */

void InsereHeap(ArvHuf *heap, int *tam, ArvHuf x)
{
    /* Insere o elemento 'x' na fila de prioridade 'heap'; Acerta o valor
     * do tamanho.
     */

    heap[*tam] = x;
    SobeHeap(heap, *tam); 
    (*tam)++;

    return;
} /* InsereHeap */

void InitBits(unsigned char *bits, int lim)
{
    /* Inicializa o vetor 'bits' colocando '0' em todas suas posições. */

    int i;

    for (i = 0; i < lim; i++)
        bits[i] = 0;

    return;
} /* InitBits */

unsigned char Mascara(int pos)
{
    /* Escolhe a máscara de acordo com a posição. */

    unsigned char masc;

    switch (pos % 8) {
        case 0:
            masc = b7;
            break; /* switch */
        case 1:
            masc = b6;
            break; /* switch */
        case 2:
            masc = b5;
            break; /* switch */
        case 3:
            masc = b4;
            break; /* switch */
        case 4:
            masc = b3;
            break; /* switch */
        case 5:
            masc = b2;
            break; /* switch */
        case 6:
            masc = b1;
            break; /* switch */
        case 7:
            masc = b0;
            break; /* switch */
    }

    return masc;
} /* Mascara */

int EscreveLetra(ArvHuf no, int pos, unsigned char *bits)
{
    /* Escreve o codigo do caminho da raiz até 'no' no vetor de bits. */

    int res_aux;
    unsigned char masc;

    if (no->pai == NULL)
        return 0;
    else
        res_aux = EscreveLetra(no->pai, pos, bits);

    masc = Mascara(pos + res_aux);

    /* Verifica a relação com o pai, caso seja filho direito
     * insere 1 como bit, caso contrário insere 0.
     * Indeterminado não acontece, pois apenas a raiz o é e não
     * a consideramos para montar a codificação.
     */
    if (no->tipoFilho == FilhoDir)
        bits[(pos + res_aux) / 8] = masc | bits [(pos + res_aux) / 8];

    return 1 + res_aux;

} /* EscreveLetra */

int ComprimeAux(unsigned char *txt, int lim, unsigned char *bits)
{
    /* Comprime o texto no vetor 'bits' e retorna o números de bits do 
     * texto comprimido.
     */

    int i, num_bits = 0;

    InitBits(bits, lim);

    for (i = 0; i < lim; i++)
        num_bits += EscreveLetra(Folhas[txt[i]], num_bits, bits);

    return num_bits;

} /* ComprimeAux */

char DecodificaLetra(ArvHuf no, int *pos, unsigned char *bits, int lim)
{
    /* Decodifica uma letra do vetor 'bits', retornado-a; Acerta o
     * valor da posição.
     */

    unsigned char masc;

    /* Na Arvore de Huffman, os nós tem 2 filhos ou nenhum. */ 
    if (no->dir == NULL)
        return no->letra;

    masc = Mascara(*pos);

    (*pos)++;

    if (*pos > lim) {
        *pos = -1;
        return 0;
    }

    if (masc & bits[(*pos - 1) / 8])
        return DecodificaLetra(no->dir, pos, bits, lim);
    else
        return DecodificaLetra(no->esq, pos, bits, lim);

} /* DecodificaLetra */

/* --------------------------------------------------------- */
/* Funções da interface                                      */
/* --------------------------------------------------------- */

Boolean ConstroiHuffman(char txt[], int n)
{
    /* A partir do texto 'txt' de 'n' caracteres, constrói a árvore de
     * Huffman para compressão deste texto e a guarda numa variável local
     * do módulo 'huffman.c'.  Numa outra variável local guarda um vetor
     * de apontadores para as folhas da árvore. Devolve 'true' se a
     * construção teve sucesso; 'false' caso contrário.
     */

    ArvHuf heap[NUM_FOLHAS], aux_dir, aux_esq, aux;
    int freq[NUM_FOLHAS], num_elems;

    /* Inicializa a Arvore de Huffman. */
    Arvore = NULL;

    /* Cria vetor de frequências. */
    InitVetFreq(freq);
    ConstroiVetFreq(freq, (unsigned char*) txt, n);

    /* Inicializa o Vetor de folhas e constroi o heap. */
    InitFolhas(freq);
    num_elems = InitHeap(heap, freq);
    ConstroiHeap(heap, num_elems);

    /* Constroi a árvore de Huffman. */
    while (num_elems > 1) {
        aux_esq = Minimo(heap, &num_elems);
        aux_dir = Minimo(heap, &num_elems);
        aux = CombinaArvs(aux_esq, aux_dir);

        InsereHeap(heap, &num_elems, aux);
    }

    Arvore = heap[0];

    return true;

} /* ConstroiHuffman */

void LiberaHuffman()
{
    /* Libera a memória dinâmica ocupada pelas estruturas criadas por
     * 'ConstroiHuffman'.
     */

    LiberaArvoreAux(Arvore);

    return;

} /* LiberaHuffman */

Boolean Comprime(char *txt, int n, char *bits, int *numBits, int numBitsMax)
{
    /* Comprime os 'n' caracteres do texto 'txt' usando as estruturas já
     * construídas, e deixa o resultado como uma seqüência de pseudo-bits
     * (ou bits verdadeiros) na área apontada por 'bits'. Devolve em
     * 'numBits' o número total de bits gerado. Em caso de sucesso devolve
     * 'true'; se houver mais de 'numBitsMax' bits, devolve 'false'.
     */

    *numBits = ComprimeAux((unsigned char*) txt, n, (unsigned char*) bits);

    if (*numBits > numBitsMax)
        return false;
    else
        return true;

} /* Comprime */


Boolean Descomprime(char *txt, int *n, char *bits, int numBits, int tamMaxTxt)
{
    /* Descomprime a cadeia de pseudo-bits (ou bits verdadeiros) na área
     * apontada por 'bits', de comprimento 'numBits' seguindo a árvore de
     * Huffman já construída.  Em caso de sucesso devolve 'true'; se
     * aparecer uma codificação incompatível com a árvore, ou se houver
     * mais caracteres que 'tamMaxTxt' devolve 'false'.
     */

    int num_char = 0, pos = 0;

    while (numBits > pos) {
        txt[num_char] = DecodificaLetra(Arvore, &pos, (unsigned char*) bits, numBits);
        num_char++;

        /* Verifica Erro. */
        if (pos == -1)
            return false;
    }

    *n = num_char;
    if (num_char > tamMaxTxt)
        return false;
    else
        return true;

} /* Descomprime */

/* --------------------------------------------------------- */
/* Funções auxiliares para os testes pelo programa principal */
/* --------------------------------------------------------- */

#define DESLOCA 5

char buf[10];  /* O buffer de impressão será fixo de até 9 caracteres e \0 */
/* Assim não é necessário prover a função de liberação (usa NULL) */

ArvHuf esq(ArvHuf p, int nivel) { return p->esq; }
ArvHuf dir(ArvHuf p, int nivel) { return p->dir; }

char *info(ArvHuf p, int nivel) { 
    if ((p->esq==NULL)&&(p->dir==NULL))  /* folha */
        sprintf(buf,"%4d:%c",p->peso,p->letra);
    else  /* nó interno */
        sprintf(buf,"%4d",p->peso);
    return buf;
} /* info */

void ImprimeHuffman()
    /* Imprime a árvore de Huffman num formato legível */
{

    ImprimeArvore(Arvore,(subarvfunc*)esq,(subarvfunc*)dir,(infofunc*)info,NULL,DESLOCA,"Árvore vazia");


} /* ImprimeHuffman */
