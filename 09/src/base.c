/* Programa: base.c (Base de dados com �rvores rubro-negras) */
/* Autor: Alexandre N. de Medeiros        RA115966           */
/* Disciplina: MC602                      Turma E            */
/* Data: 12/out/2011                                         */
/* Revisado: 24/dez/2012                                     */

/*
 * Arquivo base.c: implementa��o das fun��es de manipula��o da base.
 * V. arquivo base.h
 *
 */

#include <stdio.h>
#include "base.h"
#include "balloc.h"
#include "imprimearvore.h"

/* Declara��o de tipos para �rvores rubro-negras */
/* --------------------------------------------- */

typedef enum {rubra, negra} Cor;

typedef struct AuxNoArv {
    Aluno info;                  /* registros de informa��o */
    struct AuxNoArv *esq,*dir;   /* sub�rvores */
    Cor cor;                     /* cor do n� */
} NoArv, * ImplBase;

/* Fun��es que implementam a impress�o gr�fica da �rvore. */
/* ------------------------------------------------------ */

/* Deslocamento por n�vel para impress�o da �rvore */
#define DESLOCA 5

ImplBase esq(ImplBase p, int nivel) { return p->esq; }
ImplBase dir(ImplBase p, int nivel) { return p->dir; }

char *info(ImplBase p, int nivel) { 
    char *buf = MALLOC(8);
    buf[0] =  (p->cor==rubra) ? 'R' : 'N';
    sprintf(&(buf[1]),"%06d",p->info.ra);
    return buf;
}

void libera(char *p) { FREE(p); }

void ImprimeBase(Base *p) {
    ImplBase q = (ImplBase)(*p);

    ImprimeArvore(q,(subarvfunc*)esq,(subarvfunc*)dir,(infofunc*)info,(libfunc *)libera,DESLOCA,"Base vazia\n");

}

/* ================================================== */

Base CriaBase()
{
    /* Devolve apontador para uma base vazia */

    return NULL;
} /* CriaBase */

ImplBase CriaNo(Aluno a)
{
    /* Devolve uma folha rubra com Aluno 'a' em seu campo info. */

    ImplBase no;

    no = MALLOC(sizeof(NoArv));

    no->info = a;
    no->dir = no->esq = NULL;
    no->cor = rubra;

    return no;
} /* CriaNo */

Boolean InsereBase(Base *p, Aluno a)
{
    /* Insere o registro 'a' na base 'p' se n�o existe aluno
     * com o mesmo valor de 'ra', e devolve 'true';  caso
     * contr�rio devolve 'false'.
     */

    // indice da pilha
    int indP = -1;
    ImplBase aux = (ImplBase) *p, duracell[ALTURA_MAXIMA], pai, avo, tio;

    pai = avo = NULL;

    /* Inser��o em base vazia. */
    if (aux == NULL) {
        aux = CriaNo(a);
        aux->cor = negra;
        *p = (Base) aux;
        return true;
    }

    while(aux != NULL) {
        /* Elemento j� existe na base. */
        if (a.ra == aux->info.ra)
            return false;

        /* Empilha e procura pelo local de inser��o. */
        indP++;
        duracell[indP] = aux;

        if (a.ra < aux->info.ra)
            aux = aux->esq;
        else
            aux = aux->dir;

    }

    /* Encontrou o lugar de inser��o. */
    aux = CriaNo(a);

    if (a.ra < duracell[indP]->info.ra)
        duracell[indP]->esq = aux;
    else
        duracell[indP]->dir = aux;

    /* Verifica se � necess�rio reajustar a �rvore. */
    while (indP >= 0) {
        pai = duracell[indP];

        if (pai->cor == negra)
            break; /* while */

        avo = duracell[indP - 1];
        if (avo->esq == pai)
            tio = avo->dir;
        else
            tio = avo->esq;

        /* Confere qual rota��o ser� necess�ria, com base na cor do tio. */
        if (tio == NULL || tio->cor == negra) {
            if (aux == pai->esq && pai == avo->esq) {
                avo->esq = pai->dir;
                pai->dir = avo;

                /* Troca o 'avo' pelo 'pai' na �rvore. */
                if (avo != *p) {
                    if (duracell[indP - 2]->dir == avo)
                        duracell[indP - 2]->dir = pai;
                    else
                        duracell[indP - 2]->esq = pai;
                } else
                    *p = pai;

                /* Acerta as cores dos n�s. */
                avo->cor = rubra;
                pai->cor = negra;
            } else if (aux == pai->dir && pai == avo->dir) {
                avo->dir = pai->esq;
                pai->esq = avo;

                /* Troca o 'avo' pelo 'pai' na �rvore. */
                if (avo != *p) {
                    if (duracell[indP - 2]->dir == avo)
                        duracell[indP - 2]->dir = pai;
                    else
                        duracell[indP - 2]->esq = pai;
                } else
                    *p = pai;

                /* Acerta as cores dos n�s. */
                avo->cor = rubra;
                pai->cor = negra;
            } else if (aux == pai->dir && pai == avo->esq) {
                avo->esq = aux->dir;
                pai->dir = aux->esq;
                aux->esq = pai;
                aux->dir = avo;

                /* Troca o 'avo' pelo corrente ('aux') na �rvore. */
                if (indP - 2 >= 0) {
                    if(duracell[indP - 2]->dir == avo)
                        duracell[indP - 2]->dir = aux;
                    else
                        duracell[indP - 2]->esq = aux;
                } else
                    *p = (Base) aux;

                /* Acerta as cores dos n�s. */
                aux->cor = negra;
                avo->cor = rubra;
            } else {
                avo->dir = aux->esq;
                pai->esq = aux->dir;
                aux->dir = pai;
                aux->esq = avo;

                /* Troca o 'avo' pelo corrente ('aux') na �rvore. */
                if (indP - 2 >= 0) {
                    if(duracell[indP - 2]->dir == avo)
                        duracell[indP - 2]->dir = aux;
                    else
                        duracell[indP - 2]->esq = aux;
                } else
                    *p = (Base) aux;

                /* Acerta as cores dos n�s. */
                aux->cor = negra;
                avo->cor = rubra;
            }

            /* A sub-�rvore corrente come�a com um n� negro, n�o
                * � mais necess�rio fazer altera��es na �rvore.
                */
            break; /* while */
        } else {
            /* Acerta as cores dos n�s. */
            avo->cor = rubra;
            pai->cor = tio->cor = negra;

            /* 'avo' agora � o n� corrente. */
            aux = avo;
            indP -= 2;
        }
    }

    /* Se a raiz � rubra, torna-a negra e aumenta a altura
     * negra de toda �rvore.
     */
    aux = (ImplBase) *p;
    if (aux->cor == rubra)
        aux->cor = negra;

    return true;

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
        p = (Base*) &aux->esq;
    else
        p = (Base*) &aux->dir;

    return ConsultaBase(p, ra, a);

} /* ConsultaBase */

int Max(int a, int b)
{
    /* Devolve o maior valor entre 'a' e 'b'. */

    if (a > b)
        return a;
    else
        return b;

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
        return 1 + Max(AlturaBase((Base*) &aux->esq), AlturaBase((Base*) &aux->dir));

} /* AlturaBase */

int AlturaNegraBase(Base *p)
{
    /* Devolve a altura negra da base 'p'. */
    int altN;
    ImplBase aux = (ImplBase) *p;

    if (*p == NULL)
        return 0;
    else {
        altN = AlturaNegraBase((Base*) &aux->dir);

        if (aux->cor == negra)
            return 1 + altN;
        else
            return altN;
    }
} /* AlturaNegraBase */

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
        return 1 + NumeroNosBase((Base*) &aux->esq) + NumeroNosBase((Base*) &aux->dir);

} /* NumeroNosBase */

int NumeroNosNegrosBase(Base *p)
{
    /* Devolve o n�mero de n�s negros da base 'p'. */

    int nosN;
    ImplBase aux = (ImplBase) *p;

    if(*p == NULL)
        return 0;
    else {
        nosN = NumeroNosNegrosBase((Base*) &aux->esq) + NumeroNosNegrosBase((Base*) &aux->dir);

        if (aux->cor == negra)
            return 1 + nosN;
        else
            return nosN;
    }

} /* NumerosNosNegrosBase */

void PercorreBase(Base *p, TipoVisita Visita)
{
    /* Executa um percurso inordem na base, invocando a fun��o Visita
     * para todos os elementos.
     */

    ImplBase aux = (ImplBase) *p;

    if (*p == NULL)
        return;

    PercorreBase((Base*) &(aux->esq), Visita);
    (Visita)(&aux->info);
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

    LiberaBase((Base*) &aux->esq);
    LiberaBase((Base*) &aux->dir);

    FREE(aux->info.nome);
    FREE(aux);

    return;

} /* LiberaBase */
