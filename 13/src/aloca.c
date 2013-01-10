/* Programa: aloca.c (Gerenciamento de memória)     */
/* Autor: Alexandre N. de Medeiros       RA115966   */
/* Disciplina: MC202                     Turma E    */
/* Data: 08/nov/2011                                */
/* Revisado: 10/jan/2013                            */

/* Imlementação do sistema de alocação de memória usando blocos
   conjugados. */


#include "aloca.h"

/*-------------------*/
/* Tipos e definições*/
/*-------------------*/

#define SIZE_INT sizeof(int)
#define NULL (void*)0

typedef struct NoLista
{
  int nivel;            /* bit de sinal (negativo) indica que está disponível */
  struct NoLista *esq, *dir;
} NoLista, *Lista;

/* Tamanho mínimo de bloco a ser alocado, incluindo as informações para NoLista;
   ignora problemas de alinhamento */
#define ALOCA_MIN   (sizeof(NoLista)) 

#define LISTA_VAZIA(k)   ((disp[k].esq)==(&(disp[k])))
#define POT2(k)          (1<<k)

/*-------------------*/
/* Variáveis globais */
/*-------------------*/

char mem[TAM_MEM];
char *origem = &mem[0];
NoLista disp[NUM_NIVEIS+1];    /* as teto(log2(ALOCA_MIN)) posições iniciais não serão usadas */
Boolean primeiraVez = true;


/*--------------------*/
/* Funções auxiliares */
/*--------------------*/

void RemoveLista(Lista x)
{
    /* Remove o nó 'x' de sua lista. */

    (x->esq)->dir = x->dir;
    (x->dir)->esq = x->esq;

    return;

} /* RemoveLista */

void InsereLista(Lista x, Lista y)
{
    /* Insere o nó 'x' a direita do nó 'y'. */

    x->dir = y->dir;
    (y->dir)->esq = x;
    y->dir = x;
    x->esq = y;

    return;

} /* InsereLista */

void InitMem()
{
    /* Inicializa a memória. */

    int i;
    Lista aux = (Lista) origem;

    /* Marca todos os níveis abaixo do nível 20 como vazias. */
    for (i = 0; i <= NUM_NIVEIS; i++) {
        disp[i].esq = disp[i].dir = &disp[i];
    }

    /* Marca toda a memória como nível máximo e insere-a na lista 'disp'. */
    aux->nivel = - (NUM_NIVEIS);
    InsereLista(aux, &disp[NUM_NIVEIS]);

    primeiraVez = false;
    return;

} /* InitMem */

Lista RetornaNo(int init, int final)
{
    /* Retorna um nó do nível 'final'.
     * Caso necessário quebra o nó de nível 'init',
     * inserindo os nós que sobrarem no vetor 'disp'.
     */

    Lista res = disp[init].dir, aux2;
    char *aux1;
    int nivel;

    RemoveLista(res);
    nivel = res->nivel = - (res->nivel);


    while (nivel > final) {
        /* Quebra o nó em dois. */
        nivel--;
        res->nivel = nivel;

        aux1 = (char*) res + POT2(nivel) * sizeof(char);
        aux2 = (Lista) aux1;
        aux2->nivel = -nivel;
        InsereLista(aux2, &disp[nivel]);

    }

    return res;

} /* RetornaNo */

/*----------------------*/
/* Funções de interface */
/*----------------------*/

void *malloc(int tamanho)
{
    /* Devolve um apontador para um bloco de memória com pelo menos
     * 'tamanho' bytes; devolve NULL se não existir.
     */

    int nivel_min, nivel_disp;
    Lista bloco;

    /* Inicialização da memória na primeira vez que a função é chamada */
    if (primeiraVez)
        InitMem();

    /* Verifica o nível mínimo adequado ao tamanho desejado. */
    for (nivel_min = 0; nivel_min <=  NUM_NIVEIS; nivel_min++)
        if (tamanho + sizeof(int) <= POT2(nivel_min) && ALOCA_MIN <= POT2(nivel_min))
            break; /* for */

    /* Procura menor nível disponível. */
    for (nivel_disp = nivel_min; nivel_disp <= NUM_NIVEIS; nivel_disp++)
        if (!LISTA_VAZIA(nivel_disp))
            break; /* for */

    /* Tamanho indisponível. */
    if (nivel_disp > NUM_NIVEIS)
        return NULL;

    bloco = RetornaNo(nivel_disp, nivel_min);

    return (void*) (bloco + sizeof(int));

} /* malloc */

void free(void *p)
{
    /* Libera o bloco de memória apontado por 'p'. */

    Lista bloco = (Lista) p - sizeof(int), conj;
    unsigned int num_bloco, num_conj;


    /* Checa se o sistema já foi inicializado ou se p é valido. */
    if (primeiraVez || p == NULL)
        return;

    /* Encontra o número do bloco indicado. */
    for (num_bloco = 0; num_bloco < TAM_MEM; num_bloco++) 
        if (&mem[num_bloco] == (char*) bloco)
            break; /* for */

    /* Checa se encontrou-o. */
    if (num_bloco == TAM_MEM)
        return;

    while (bloco->nivel < NUM_NIVEIS) {
        /* Determina o conjugado. */
        num_conj = num_bloco ^ POT2(bloco->nivel);
        conj = (Lista) &mem[num_conj];

        /* Junta os Blocos conjugados caso possível. */
        if (conj->nivel < 0 && conj->nivel == -bloco->nivel) {

            RemoveLista(conj);

            conj->nivel = ++(bloco->nivel);

            /* Caso o conjugado seja o filho esquerdo da 'arvore'.
             * troca o valor de 'bloco' para o 'conj'.
             */
            if (conj < bloco) {
                num_bloco = num_conj;
                bloco = conj;
            }
        }
        else
            break; /* while */
    }

    /* Insere o novo bloco na lista. */
    InsereLista(bloco, &disp[bloco->nivel]);
    bloco->nivel = - (bloco->nivel);

    return;

} /* free */

int avail(int k)
{
    /* Devolve o número de blocos de tamanho '2^k' disponíveis - usado
     * para testes.
     */

    Lista aux;
    int num_disp = 0;

    /* Inicialização da memória na primeira vez que a função é chamada */
    if (primeiraVez)
        InitMem();

    aux = disp[k].dir;

    /* Conta o número de elementos disponíveis no nível k. */
    while (aux != &disp[k]) {
        aux = aux->dir;
        num_disp++;
    }

    return num_disp;

} /* avail */
