/* Programa: base.c (Base de dados com �rvores de busca simples) */
/* Autor: Alexandre N. de Medeiros        RA115966               */
/* Disciplina: MC202                      Turma E                */
/* Data: 28/sep/2011                                             */
/* Revisado: 09/out/2012                                         */

/*
 * Arquivo base.c: implementa��o das fun��es de manipula��o da base.
 */

#include <stdio.h>
#include <string.h>
#include "base.h"
#include "balloc.h"

typedef struct AuxNoArv
{
    Aluno info;                   /* registros de informa��o */
    struct AuxNoArv *esq,*dir; 	  /* sub�rvores */
} NoArv, * ImplBase;


Base CriaBase()
{
    /* Devolve apontador para uma base vazia */

    return NULL;

} /* CriaBase */

Boolean InsereBase(Base *p, Aluno a)
{
    /* Insere o registro 'a' na base 'p' se n�o existe aluno
     * com o mesmo valor de 'ra', e devolve 'true';  caso
     * contr�rio devolve 'false'
     */

    ImplBase aux = (ImplBase) *p;

    /* Encontrou o lugar de inser��o. */
    if (*p == NULL) {
        aux = (ImplBase) MALLOC(sizeof(NoArv));
        aux->info = a;
        aux->esq = NULL;
        aux->dir = NULL;

        *p = (Base) aux;

        return true;
    }

    /* Elemento j� existe na base. */
    if (a.ra == aux->info.ra)
        return false;

    /* Procura pelo local de inser��o. */
    if (a.ra < aux->info.ra)
        p = (Base*) &(aux->esq);
    else
        p = (Base*) &(aux->dir);

    return InsereBase(p, a);

} /* InsereBase */

Boolean ConsultaBase(Base *p, int ra, Aluno *a)
{
    /* Devolve 'true' se existe um registro com 'ra' dado na
     * base 'p';  caso contr�rio devolve 'false'. 'a' conter�
     * os dados do aluno, se encontrado.
     */

    ImplBase aux = (ImplBase) *p;

    /* N�o existe o elemento na base. */
    if (*p == NULL)
        return false;

    /* Encontrou. */
    if (ra == aux->info.ra) {
        *a = aux->info;
        return true;
    }

    /* Continua Procurando */
    if (ra < aux->info.ra)
        p = (Base*) &(aux->esq);
    else
        p = (Base*) &(aux->dir);

    return ConsultaBase(p, ra, a);

} /* ConsultaBase */

ImplBase MenorElemento(ImplBase p)
{
    /* Devolve o menor Elemento da Base indicada. Assume base n�o nula. */

    if (p->esq == NULL)
        return p;
    else
        return MenorElemento(p->esq);

} /* MenorElemento */

Boolean RemoveBase(Base *p, int ra)
{
    /* Devolve 'true' se um registro com 'ra' p�de ser removido da
     * base 'p';  caso contr�rio devolve 'false'.
     */

    ImplBase aux = (ImplBase) *p;

    if (*p == NULL)
        return false;

    if (ra == aux->info.ra) {
        /* Est� no n� desejado. */
        if (aux->dir == NULL) {
            /* Remove o elemento e coloca sua sub�rvore esquerda no seu lugar. */
            *p = (Base) aux->esq;
            FREE(aux->info.nome);
            FREE(aux);
        } else {
            /* Troca o elemento que vai remover por seu sucessor inordem. */
            ImplBase sucessor;
            String auxNome;

            sucessor = MenorElemento(aux->dir);
            auxNome = sucessor->info.nome;
            sucessor->info.nome = aux->info.nome;
            aux->info.nome = auxNome;
            aux->info.ra = sucessor->info.ra;

            /* Remove o elemento trocado de sua posi��o inicial. */
            RemoveBase((Base*) &(aux->dir), aux->info.ra);

        }

        return true;

    }

    /* Procura pelo n� desejado. */
    if (ra < aux->info.ra)
        p = (Base*) &(aux->esq);
    else
        p = (Base*) &(aux->dir);

    return RemoveBase(p, ra);

} /* RemoveBase */

int Max(int a, int b)
{
    /* Devolve o maior valor entre 'a' e 'b'. */

    if (a > b) return a;
    else return b;

} /* Max */

int AlturaBase(Base *p)
{
    /* Devolve a altura da base 'p'.
     * Caso o *p seja nulo, temos subarvore vazia (altura = 0);
     * Caso contr�rio, retorna 1 + a maior altura de suas sub-�rvores.
     */

    ImplBase aux = (ImplBase) *p;

    if(*p == NULL)
        return 0;
    else
        return 1 + Max(AlturaBase((Base*) &(aux->esq)), AlturaBase((Base*) &(aux->dir)));

} /* AlturaBase */

int NumeroNosBase(Base *p)
{
    /* Devolve o n�mero de n�s da base 'p'.
     * Caso o *p seja nulo, temos subarvore vazia (n�mero de n�s = 0);
     * Caso contr�rio, retorna 1 + o n�mero de n�s de suas sub-�rvores.
     */

    ImplBase aux = (ImplBase) *p;

    if(*p == NULL)
        return 0;
    else
        return 1 + NumeroNosBase((Base*) &(aux->esq)) + NumeroNosBase((Base*) &(aux->dir));

} /* NumeroNosBase */


void PercorreBase(Base *p, void (*Visita)(Aluno*))
{
    /* Executa um percurso inordem na base, invocando a fun��o Visita
     * para todos os elementos.
     */

    ImplBase aux = (ImplBase) *p;

    if (*p == NULL)
        return;

    PercorreBase((Base*) &(aux->esq), Visita);
    Visita(&(aux->info));
    PercorreBase((Base*) &(aux->dir), Visita);

    return;

}   /* PercorreBase */

void LiberaBase(Base *p)
{
    /* Libera todos os n�s da base apontada por 'p', bem
     * como todas as cadeias que guardam os nomes.
     */

    ImplBase aux = (ImplBase) *p;

    if(*p == NULL)
        return;

    LiberaBase((Base*) &(aux->esq));
    LiberaBase((Base*) &(aux->dir));

    FREE(aux->info.nome);
    FREE(aux);

    return;

} /* LiberaBase */
