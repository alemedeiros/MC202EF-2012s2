/* Programa: base.c (Base de dados com árvores rubro-negras) */
/* Autor: Alexandre N. de Medeiros        RA115966           */
/* Disciplina: MC602                      Turma E            */
/* Data: 12/out/2011                                         */
/* Revisado: 24/dez/2012                                     */

/*
 * Arquivo base.c: implementação das funções de manipulação da base.
 * V. arquivo base.h
 *
 */

#include <stdio.h>
#include "base.h"
#include "balloc.h"
#include "imprimearvore.h"

/* Declaração de tipos para árvores rubro-negras */
/* --------------------------------------------- */

typedef enum {rubra, negra} Cor;

typedef struct AuxNoArv {
    Aluno info;                  /* registros de informação */
    struct AuxNoArv *esq,*dir;   /* subárvores */
    Cor cor;                     /* cor do nó */
} NoArv, * ImplBase;

/* Funções que implementam a impressão gráfica da árvore. */
/* ------------------------------------------------------ */

/* Deslocamento por nível para impressão da árvore */
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
    /* Insere o registro 'a' na base 'p' se não existe aluno
     * com o mesmo valor de 'ra', e devolve 'true';  caso
     * contrário devolve 'false'.
     */

    // indice da pilha
    int indP = -1;
    ImplBase aux = (ImplBase) *p, duracell[ALTURA_MAXIMA], pai, avo, tio;

    pai = avo = NULL;

    /* Inserção em base vazia. */
    if (aux == NULL) {
        aux = CriaNo(a);
        aux->cor = negra;
        *p = (Base) aux;
        return true;
    }

    while(aux != NULL) {
        /* Elemento já existe na base. */
        if (a.ra == aux->info.ra)
            return false;

        /* Empilha e procura pelo local de inserção. */
        indP++;
        duracell[indP] = aux;

        if (a.ra < aux->info.ra)
            aux = aux->esq;
        else
            aux = aux->dir;

    }

    /* Encontrou o lugar de inserção. */
    aux = CriaNo(a);

    if (a.ra < duracell[indP]->info.ra)
        duracell[indP]->esq = aux;
    else
        duracell[indP]->dir = aux;

    /* Verifica se é necessário reajustar a árvore. */
    while (indP >= 0) {
        pai = duracell[indP];

        if (pai->cor == negra)
            break; /* while */

        avo = duracell[indP - 1];
        if (avo->esq == pai)
            tio = avo->dir;
        else
            tio = avo->esq;

        /* Confere qual rotação será necessária, com base na cor do tio. */
        if (tio == NULL || tio->cor == negra) {
            if (aux == pai->esq && pai == avo->esq) {
                avo->esq = pai->dir;
                pai->dir = avo;

                /* Troca o 'avo' pelo 'pai' na árvore. */
                if (avo != *p) {
                    if (duracell[indP - 2]->dir == avo)
                        duracell[indP - 2]->dir = pai;
                    else
                        duracell[indP - 2]->esq = pai;
                } else
                    *p = pai;

                /* Acerta as cores dos nós. */
                avo->cor = rubra;
                pai->cor = negra;
            } else if (aux == pai->dir && pai == avo->dir) {
                avo->dir = pai->esq;
                pai->esq = avo;

                /* Troca o 'avo' pelo 'pai' na árvore. */
                if (avo != *p) {
                    if (duracell[indP - 2]->dir == avo)
                        duracell[indP - 2]->dir = pai;
                    else
                        duracell[indP - 2]->esq = pai;
                } else
                    *p = pai;

                /* Acerta as cores dos nós. */
                avo->cor = rubra;
                pai->cor = negra;
            } else if (aux == pai->dir && pai == avo->esq) {
                avo->esq = aux->dir;
                pai->dir = aux->esq;
                aux->esq = pai;
                aux->dir = avo;

                /* Troca o 'avo' pelo corrente ('aux') na árvore. */
                if (indP - 2 >= 0) {
                    if(duracell[indP - 2]->dir == avo)
                        duracell[indP - 2]->dir = aux;
                    else
                        duracell[indP - 2]->esq = aux;
                } else
                    *p = (Base) aux;

                /* Acerta as cores dos nós. */
                aux->cor = negra;
                avo->cor = rubra;
            } else {
                avo->dir = aux->esq;
                pai->esq = aux->dir;
                aux->dir = pai;
                aux->esq = avo;

                /* Troca o 'avo' pelo corrente ('aux') na árvore. */
                if (indP - 2 >= 0) {
                    if(duracell[indP - 2]->dir == avo)
                        duracell[indP - 2]->dir = aux;
                    else
                        duracell[indP - 2]->esq = aux;
                } else
                    *p = (Base) aux;

                /* Acerta as cores dos nós. */
                aux->cor = negra;
                avo->cor = rubra;
            }

            /* A sub-árvore corrente começa com um nó negro, não
                * é mais necessário fazer alterações na árvore.
                */
            break; /* while */
        } else {
            /* Acerta as cores dos nós. */
            avo->cor = rubra;
            pai->cor = tio->cor = negra;

            /* 'avo' agora é o nó corrente. */
            aux = avo;
            indP -= 2;
        }
    }

    /* Se a raiz é rubra, torna-a negra e aumenta a altura
     * negra de toda árvore.
     */
    aux = (ImplBase) *p;
    if (aux->cor == rubra)
        aux->cor = negra;

    return true;

} /* InsereBase */

Boolean ConsultaBase(Base *p, int ra, Aluno *a)
{
    /* Devolve 'true' se existe um registro com 'ra' dado na
     * base 'p';  caso contrário devolve 'false'. 'a' conterá 
     * os dados do aluno, se encontrado.
     */

    ImplBase aux = (ImplBase) *p;

    /* Não existe o elemento na base. */
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
     * Caso contrário, retorna 1 + a maior altura de suas sub-árvores.
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
    /* Devolve o número de nós da base 'p'.
     * Caso o *p seja nulo, temos subarvore vazia (número de nós = 0);
     * Caso contrário, retorna 1 + o número de nós de suas sub-árvores.
     */

    ImplBase aux = (ImplBase) *p;

    if(*p == NULL)
        return 0;
    else
        return 1 + NumeroNosBase((Base*) &aux->esq) + NumeroNosBase((Base*) &aux->dir);

} /* NumeroNosBase */

int NumeroNosNegrosBase(Base *p)
{
    /* Devolve o número de nós negros da base 'p'. */

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
    /* Executa um percurso inordem na base, invocando a função Visita
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
    /* Libera todos os nós da base apontada por 'p', bem 
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
