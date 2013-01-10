/* Programa: base.c (Base de dados com espalhamento encadeado)      */
/* Autor: Alexandre N. de Medeiros                      RA115966    */
/* Disciplina: MC202                                    Turma E     */
/* Data: 26/out/2011                                                */
/* Revisado: 10/jan/2013                                            */


/*
 * Arquivo 'base.c': Implementação da base de dados com espalhamento encadeado.
 * Laboratório: 11
 */

#include <stdio.h>
#include "base.h"


/********* DECLARAÇÃO DE CONSTANTES *********/

#define CABECA -1

/*********** DECLARAÇÕES DE TIPOS ***********/

typedef struct RegLista *Lista;
typedef struct RegLista
{
  Aluno aluno;
  Lista prox;
} RegLista;

typedef struct RegBase *ImplBase;
typedef struct RegBase
{
  int numregs;
  Lista tabela[MaxHash];
} RegBase;

/********** FUNÇÃO DE ESPALHAMENTO **********/

int Espalha(int k)
{
    return (k%MaxHash);
} /* Espalha */

/************ FUNÇÕES AUXILIARES ************/

Lista CriaLista()
{
    /* Devolve apontador para uma lista circular com nó cabeça vazia. */
    Lista l;

    l = MALLOC(sizeof(RegLista));

    /* Inicialização da Lista. */
    l->prox = l;
    l->aluno.ra = CABECA;
    l->aluno.nome = NULL;

    return l;

} /* CriaLista */

Lista CriaReg(Aluno a, Lista prox)
{
    /* Cria um Registro com a informação 'a' e retorna seu apontador. */
    Lista reg;

    reg = MALLOC(sizeof(RegLista));

    /* Inicialização do registro */
    reg->aluno = a;
    reg->prox = prox;

    return reg;

} /* CriaReg */

Lista ProcuraPosicao(Lista l, int ra)
{
    /* Devolve a posição anterior a posiçãon onde o 'ra' deveria estar. */
    Lista l1 = l->prox, l2 = l;

    /* Procura pela posiçãoo. */
    while (true) {
        /* Chegou ao fim da lista ou encontrou posição. */
        if (l1->aluno.ra == CABECA || l1->aluno.ra >= ra) {
            return l2;
        } else {
            /* Avança para próxima posição. */
            l2 = l1;
            l1 = l2->prox;
        }
    }

} /* ProcuraPosicao */

void LiberaLista(Lista l)
{
    /* Libera a Lista Circular apontada por 'l'. */

    Lista l1 = l->prox, l2;

    while (l1 != l) {
        l2 = l1->prox;
        FREE(l1->aluno.nome);
        FREE(l1);
        l1 = l2;
    }

    FREE(l);

    return;

} /* LiberaLista */

/*********** FUNÇÕES DA INTERFACE ***********/

Base CriaBase()
{
    /* Devolve apontador para uma base vazia com tabela inicializada */

    ImplBase q;
    int i;

    q = MALLOC(sizeof(RegBase));

    /* Inicialização da Base. */
    q->numregs = 0;
    for (i = 0; i < MaxHash; i++)
        q->tabela[i] = CriaLista();

    return (Base) q;

} /* CriaBase */

Boolean InsereBase(Base p, Aluno *a)
{
    /* Insere o registro 'a' na base 'p' se não existe aluno
     * com o mesmo valor de 'ra', e devolve 'true';  caso
     * contrário devolve 'false'
     */

    ImplBase q = (ImplBase) p;
    Lista l1 = ProcuraPosicao(q->tabela[Espalha(a->ra)], a->ra), l2 = l1->prox;

    if (l2->aluno.ra != a->ra) {
        l1->prox = CriaReg(*a,l2);
        q->numregs++;

        return true;
    } else
        return false;

} /* InsereBase */

Boolean RemoveBase(Base p, int ra)
{
    /* Remove da base 'p' o aluno com 'ra' dado; devolve 'true'
     * se ele existiu e 'false' caso contrário.
     */

    ImplBase q = (ImplBase) p;
    Lista l1 = ProcuraPosicao(q->tabela[Espalha(ra)], ra),
          l2 = l1->prox;

    if (l2->aluno.ra == ra) {
        l1->prox = l2->prox;
        FREE(l2->aluno.nome);
        FREE(l2);
        q->numregs--;

        return true;
    } else
        return false;

} /* RemoveBase */

Boolean ConsultaBase(Base p, int ra, Aluno *a)
{
    /* Devolve 'true' se existe um registro com 'ra' dado na
     * base 'p';  caso contrário devolve 'false'.  'a' conterá 
     * os dados do aluno, se encontrado.
     */

    ImplBase q = (ImplBase) p;
    Lista l1 = ProcuraPosicao(q->tabela[Espalha(ra)], ra), l2 = l1->prox;

    if (l2->aluno.ra == ra) {
        *a = l2->aluno;

        return true;
    } else
        return false;

} /* ConsultaBase */

int NumeroRegsBase(Base p)
{
    /* Devolve o número de registros (alunos) na base 'p'. */

    ImplBase q = (ImplBase) p;

    return q->numregs;

} /* NumeroRegsBase */

void ImprimeBase(Base p)
{
    /* Imprime, os registros contidos na base 'p', um por linha.  A ordem
     * de impressão segue a ordem das entradas da tabela, e para cada
     * entrada, a ordem da lista ligada.  Cada linha começa com o índice
     * correspondente na tabela de espalhamento. Deve ser usado o formato
     * "(%3d) %6d %s\n".
     */

    ImplBase q = (ImplBase) p;
    Lista l;
    int i;

    for (i = 0; i < MaxHash; i++) {
        l = (q->tabela[i])->prox;
        while (l->aluno.ra != CABECA) {
            printf("(%3d) %6d %s\n",i, l->aluno.ra, l->aluno.nome);
            l = l->prox;
        }
    }

    return;

} /* ImprimeBase */

void LiberaBase(Base p)
{
    /* Libera toda a memória utilizada pela base 'p', bem como
     * todas as cadeias que guardam os nomes.
     */

    ImplBase q = (ImplBase) p;
    int i;

    for (i = 0; i < MaxHash; i++)
        LiberaLista(q->tabela[i]);

    FREE(p);

    return;

} /* LiberaBase */
