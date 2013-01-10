/* Programa: huffman.c (Codifica��o de Huffman)      */
/* Autor: Alexandre N. de Medeiros       RA115966    */
/* Disciplina: MC602                     Turma E     */
/* Data: 30/out/2011                                 */
/* Revisado: 10/jan/2013                             */
/*       Implementa��o com bits verdadeiros.         */

/* 
 * huffman.c - Implementa��o do algoritmo de Huffman. Caso a constante
 *             PSEUDO_BITS esteja definida no arquivo "huffman.h", o
 *             teste ser� feito com caracteres '0's e '1's.
 */

#include <string.h>
#include <stdio.h>
#include "huffman.h"

/* Constante */
#define NUM_FOLHAS 256

/* M�scaras Bin�rias*/
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
    int peso;                      /* peso da �rvore */
    char letra;                    /* somente no caso de folha */
    TipoFilho tipoFilho;           /* indica a rela��o com o pai */
    ArvHuf esq,dir,pai;            /* sub�rvores e pai */
} RegArvHuf;

ArvHuf Arvore;   /*  As fun��es abaixo construir�o e utilizar�o a
                  *  �rvore que ser� apontada por esta vari�vel
                  */

ArvHuf Folhas[NUM_FOLHAS];   /* Apontadores para as folhas da
                              * �rvore 'Arvore'
                              */


/* --------------------------------------------------------- */
/* Fun��es auxiliares sugeridas para este m�dulo             */
/* --------------------------------------------------------- */

ArvHuf CriaFolha(char letra, int peso)
{
    /* Cria uma folha da �rvore; devolve NULL se n�o h� mais mem�ria. */

    ArvHuf f = NULL;

    f = MALLOC(sizeof(RegArvHuf));

    /* Se foi possivel fazer a aloca��o, inicializa a folha. */
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
    /* Combina duas sub�rvores numa �nica �rvore cujo peso � a soma dos
     * pesos das sub�rvores; devolve NULL se n�o h� mais mem�ria.
     */

    ArvHuf no = NULL;

    no = MALLOC(sizeof(RegArvHuf));

    /* Se foi possivel fazer a aloca��o, inicializa o n�. */
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
    /* Sobe o �ltimo elemento fl[m] para dentro da fila de prioridade */

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
     * prioridades, com peso m�nimo na raiz.
     */

    int i;

    for (i = 1; i < n; i++)
        SobeHeap(fl, i);

    return;
} /* ConstroiHeap */

ArvHuf Minimo(ArvHuf fl[], int *n)
{
    /* Devolve o elemento m�nimo da fila de prioridade fl' (raiz) e o
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
    /* Libera a mem�ria din�mica ocupada pela �rvore 'p'. */

    if(p == NULL)
        return;

    /* Percuso pos-ordem. */
    LiberaArvoreAux(p->esq);
    LiberaArvoreAux(p->dir);
    FREE(p);

    return;

} /* LiberaArvoreAux */

/* --------------------------------------------------------- */
/*  Outras fun��es auxiliares podem ser definidas aqui       */
/* --------------------------------------------------------- */

void InitVetFreq(int *freq)
{
    /* Inicializa o vetor frequ�ncia com '0' em todas suas posi��es. */

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
    /* Inicializa o vetor 'Folhas' com base no vetor de frequ�ncias,
     * elementos de frequ�ncia '0' s�o inicializados como apontador
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
    /* Insere todos elementos no vetor 'heap', sem organiz�-lo com um heap,
     * retornando o n�mero de elementos no mesmo.
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
    /* Inicializa o vetor 'bits' colocando '0' em todas suas posi��es. */

    int i;

    for (i = 0; i < lim; i++)
        bits[i] = 0;

    return;
} /* InitBits */

unsigned char Mascara(int pos)
{
    /* Escolhe a m�scara de acordo com a posi��o. */

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
    /* Escreve o codigo do caminho da raiz at� 'no' no vetor de bits. */

    int res_aux;
    unsigned char masc;

    if (no->pai == NULL)
        return 0;
    else
        res_aux = EscreveLetra(no->pai, pos, bits);

    masc = Mascara(pos + res_aux);

    /* Verifica a rela��o com o pai, caso seja filho direito
     * insere 1 como bit, caso contr�rio insere 0.
     * Indeterminado n�o acontece, pois apenas a raiz o � e n�o
     * a consideramos para montar a codifica��o.
     */
    if (no->tipoFilho == FilhoDir)
        bits[(pos + res_aux) / 8] = masc | bits [(pos + res_aux) / 8];

    return 1 + res_aux;

} /* EscreveLetra */

int ComprimeAux(unsigned char *txt, int lim, unsigned char *bits)
{
    /* Comprime o texto no vetor 'bits' e retorna o n�meros de bits do 
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
     * valor da posi��o.
     */

    unsigned char masc;

    /* Na Arvore de Huffman, os n�s tem 2 filhos ou nenhum. */ 
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
/* Fun��es da interface                                      */
/* --------------------------------------------------------- */

Boolean ConstroiHuffman(char txt[], int n)
{
    /* A partir do texto 'txt' de 'n' caracteres, constr�i a �rvore de
     * Huffman para compress�o deste texto e a guarda numa vari�vel local
     * do m�dulo 'huffman.c'.  Numa outra vari�vel local guarda um vetor
     * de apontadores para as folhas da �rvore. Devolve 'true' se a
     * constru��o teve sucesso; 'false' caso contr�rio.
     */

    ArvHuf heap[NUM_FOLHAS], aux_dir, aux_esq, aux;
    int freq[NUM_FOLHAS], num_elems;

    /* Inicializa a Arvore de Huffman. */
    Arvore = NULL;

    /* Cria vetor de frequ�ncias. */
    InitVetFreq(freq);
    ConstroiVetFreq(freq, (unsigned char*) txt, n);

    /* Inicializa o Vetor de folhas e constroi o heap. */
    InitFolhas(freq);
    num_elems = InitHeap(heap, freq);
    ConstroiHeap(heap, num_elems);

    /* Constroi a �rvore de Huffman. */
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
    /* Libera a mem�ria din�mica ocupada pelas estruturas criadas por
     * 'ConstroiHuffman'.
     */

    LiberaArvoreAux(Arvore);

    return;

} /* LiberaHuffman */

Boolean Comprime(char *txt, int n, char *bits, int *numBits, int numBitsMax)
{
    /* Comprime os 'n' caracteres do texto 'txt' usando as estruturas j�
     * constru�das, e deixa o resultado como uma seq��ncia de pseudo-bits
     * (ou bits verdadeiros) na �rea apontada por 'bits'. Devolve em
     * 'numBits' o n�mero total de bits gerado. Em caso de sucesso devolve
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
    /* Descomprime a cadeia de pseudo-bits (ou bits verdadeiros) na �rea
     * apontada por 'bits', de comprimento 'numBits' seguindo a �rvore de
     * Huffman j� constru�da.  Em caso de sucesso devolve 'true'; se
     * aparecer uma codifica��o incompat�vel com a �rvore, ou se houver
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
/* Fun��es auxiliares para os testes pelo programa principal */
/* --------------------------------------------------------- */

#define DESLOCA 5

char buf[10];  /* O buffer de impress�o ser� fixo de at� 9 caracteres e \0 */
/* Assim n�o � necess�rio prover a fun��o de libera��o (usa NULL) */

ArvHuf esq(ArvHuf p, int nivel) { return p->esq; }
ArvHuf dir(ArvHuf p, int nivel) { return p->dir; }

char *info(ArvHuf p, int nivel) { 
    if ((p->esq==NULL)&&(p->dir==NULL))  /* folha */
        sprintf(buf,"%4d:%c",p->peso,p->letra);
    else  /* n� interno */
        sprintf(buf,"%4d",p->peso);
    return buf;
} /* info */

void ImprimeHuffman()
    /* Imprime a �rvore de Huffman num formato leg�vel */
{

    ImprimeArvore(Arvore,(subarvfunc*)esq,(subarvfunc*)dir,(infofunc*)info,NULL,DESLOCA,"�rvore vazia");


} /* ImprimeHuffman */
