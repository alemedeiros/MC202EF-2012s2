/* Programa: base.c (Base de dados com �rvores AVL) */
/* Autor: Alexandre N. de Medeiros        RA115966  */
/* Disciplina: MC202                      Turma E   */
/* Data: 04/out/2011                                */
/* Revisado: 18/dez/2012                            */

/*
 * Arquivo base.c: implementa��o das fun��es de manipula��o da base.
 */

#include <stdio.h>
#include "base.h"
#include "balloc.h"

/* Constantes de balanceamento. */
#define ZERO 0
#define MAIS 1
#define MENOS -1

typedef struct AuxNoArv {
    Aluno info;                  /* registros de informa��o */
    struct AuxNoArv *esq,*dir;   /* sub�rvores */
    short int bal;               /* fator de balanceamento */
} NoArv, * ImplBase;

/*
   Complete o resto do arquivo; se n�o implementar a fun��o de
   remo��o, coloque apenas um esqueleto vazio devolvendo qualquer
   valor booleano para evitar erros de compila��o.
*/

Base CriaBase()
{
    /* Devolve apontador para uma base vazia */
    return NULL;

} /* CriaBase */

ImplBase CriaNo(Aluno a)
{
    /* Cria um n� com as informa��es 'a' e fator 0. */
    ImplBase no = MALLOC(sizeof(NoArv));

    no->bal = ZERO;
    no->info = a;
    no->esq = NULL;
    no->dir = NULL;

    return no;

} /* CriaNo */

Base SubEsq(Base *p)
{
    /* Devolve a sub�rvore esquerda da base 'p' se n�o for vazia; caso
     * contr�rio devolve NULL.
     */

    ImplBase aux = (ImplBase) *p;

    if (*p == NULL)
        return NULL;
    else
        return (Base) aux->esq;

} /* SubEsq */

Base SubDir(Base *p)
{
    /* Devolve a sub�rvore direita da base 'p' se n�o for vazia; caso
     * contr�rio devolve NULL.
     */

    ImplBase aux = (ImplBase) *p;

    if (*p == NULL)
        return NULL;
    else
        return (Base) aux->dir;

} /* SubDir */

int FatorBal(Base *p)
{
    /* Devolve o fator de balanceamento da raiz da base: altura da
     * sub�rvore direita menos a altura da sub�rvore esquerda; devolve
     * zero se a �rvore � vazia.
     */

    return ((ImplBase) *p)->bal;

} /* FatorBal */

ImplBase* ProcuraPos(ImplBase* p, int ra)
{
    /* Procura a posi��o onde est� ou deveria estar o ra indicado. */

    /* 'p' deveria estar ou esta aqui! */
    if (*p == NULL || (*p)->info.ra == ra)
        return p;
    else
        /* Procura posi��o seguindo a defini��o da �rvore de busca. */
        if ((*p)->info.ra < ra)
            return ProcuraPos(&((*p)->dir), ra);
        else
            return ProcuraPos(&((*p)->esq), ra);

} /* ProcuraPos */

void RotacaoRR(ImplBase *p)
{
    /* Rota��o simples RR. */
    ImplBase aux1 = (*p)->dir, aux2 = *p;

    *p = aux1;
    aux2->dir = aux1->esq;
    aux1->esq = aux2;

    return;
} /* RotacaoRR */

void RotacaoRL(ImplBase *p)
{
    /* Rota��o dupla RL. */
    ImplBase aux1 = (*p)->dir, aux2 = *p;

    *p = aux1->esq;
    aux1->esq = (*p)->dir;
    aux2->dir = (*p)->esq;
    (*p)->dir = aux1;
    (*p)->esq = aux2;

    return;
} /* RotacaoRL */

void RotacaoLR(ImplBase *p)
{
    /* Rota��o dupla LR. */
    ImplBase aux1 = (*p)->esq, aux2 = *p;

    *p = aux1->dir;
    aux1->dir = (*p)->esq;
    aux2->esq = (*p)->dir;
    (*p)->esq = aux1;
    (*p)->dir = aux2;

    return;
} /* RotacaoLR */

void RotacaoLL(ImplBase *p)
{
    /* Rota��o simples LL. */
    ImplBase aux1 = (*p)->esq, aux2 = *p;

    *p = aux1;
    aux2->esq = aux1->dir;
    aux1->dir = aux2;

    return;
} /* RotacaoLL */

Boolean InsereAux(ImplBase* p, Aluno a, Boolean* alt)
{
    /* Insere a informa��o 'a' na �rvore AVL, mantendo
     * suas propriedades.
     */

    ImplBase aux;

    /* Posi��o de inser��o vazia. */
    if (*p == NULL) {
        *p = CriaNo(a);
        *alt = true;
        return true;
    }

    /* 'ra' repetido! retorna false. */
    if (a.ra == (*p)->info.ra)
        return false;

    /* Desce � Direita. */
    if ((*p)->info.ra < a.ra) {
        /* N�o houve Inser��o. */
        if (!InsereAux(&((*p)->dir), a, alt))
            return false;

        /* N�o houve mudan�a na altura. */
        if (!(*alt))
            return true;

        /* Mudan�a na altura! */
        switch ((*p)->bal) {
        case MENOS:
            /* Termina a propaga��o de mudan�a na altura. */
            (*p)->bal = ZERO;
            *alt = false;

            break; /* switch */

        case ZERO:
            /* Continua a propaga��o de mudan�a de altura. */
            (*p)->bal = MAIS;

            break; /* switch */

        case MAIS:
            /* Rotaciona a �rvore e termina a propaga��o de
             * mudan�a na altura.
             */
            aux = *p;

            if (((*p)->dir)->bal == MAIS) {
                RotacaoRR(p);

                /* Corre��o dos fatores de Balanceamento. */
                aux->bal = ZERO;

            }
            else {
                ImplBase auxDir = aux->dir;

                RotacaoRL(p);

                /* Corre��o dos fatores de Balanceamento. */
                if ((*p)->bal == ZERO) {
                    auxDir->bal = ZERO;
                    aux->bal = ZERO;
                }
                else if ((*p)->bal == MAIS) {
                    auxDir->bal = ZERO;
                    aux->bal = MENOS;
                }
                else {
                    auxDir->bal = MAIS;
                    aux->bal = ZERO;
                }

            }

            (*p)->bal = ZERO;
            *alt = false;

            break; /* switch */

        }
        return true;

    }
    else {
        /* Desce � esquerda. */

        /* N�o houve Inser��o. */
        if (!InsereAux(&((*p)->esq), a, alt))
            return false;

        /* N�o houve mudan�a na altura. */
        if (!(*alt))
            return true;

        switch ((*p)->bal) {
        case MAIS:
            /* Termina a propaga��o de mudan�a na altura. */
            (*p)->bal = ZERO;
            *alt = false;

            break; /* switch */

        case ZERO:
            /* Continua a propaga��o de mudan�a de altura. */
            (*p)->bal = MENOS;

            break; /* switch */

        case MENOS:
            /* Rotaciona a �rvore e termina a propaga��o de
             * mudan�a na altura.
             */
            aux = *p;

            if ((aux->esq)->bal == MENOS) {
                RotacaoLL(p);

                /* Corre��o dos fatores de Balanceamento. */
                aux->bal = ZERO;

            }
            else {
                /* Rota��o dupla LR. */
                ImplBase auxEsq = aux->esq;

                RotacaoLR(p);

                /* Corre��o dos fatores de Balanceamento. */
                if ((*p)->bal == ZERO) {
                    auxEsq->bal = ZERO;
                    aux->bal = ZERO;
                }
                else if ((*p)->bal == MAIS) {
                    auxEsq->bal = MENOS;
                    aux->bal = ZERO;
                }
                else {
                    auxEsq->bal = ZERO;
                    aux->bal = MAIS;
                }
            }

            (*p)->bal = ZERO;
            *alt = false;

            break; /* switch */

        }

        return true;

    }

} /* InsereAux */

Boolean InsereBase(Base *p, Aluno a)
{
    /* Insere o registro 'a' na base 'p' se n�o existe aluno
     * com o mesmo valor de 'ra', e devolve 'true';  caso
     * contr�rio devolve 'false'.
     */

    ImplBase* aux = (ImplBase*) p;
    Boolean alt = false;

    if(!InsereAux(aux, a, &alt))
        return false;
    else
        return true;

} /* InsereBase */

Boolean ConsultaBase(Base *p, int ra, Aluno *a)
{
    /* Devolve 'true' se existe um registro com 'ra' dado na
     * base 'p';  caso contr�rio devolve 'false'. 'a' conter�
     * os dados do aluno, se encontrado.
     */

    /* Procura a posi��o onde 'ra' deveria estar. */
    ImplBase* aux = ProcuraPos((ImplBase*) p, ra);

    if (*aux == NULL)
        return false;
    else {
        *a = (*aux)->info;
        return true;
    }

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

void PercorreBase(Base *p, TipoVisita Visita)
{
    /* Executa um percurso inordem na base, invocando a fun��o Visita
     * para todos os elementos.
     */

    ImplBase aux = (ImplBase) *p;

    if (*p == NULL)
        return;

    PercorreBase((Base*) &aux->esq, Visita);
    Visita(&aux->info);
    PercorreBase((Base*) &aux->dir, Visita);

    return;

} /* PercorreBase */


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

ImplBase MenorElemento(ImplBase p)
{
    /* Devolve o menor Elemento da Base indicada. */

    if (p->esq == NULL)
        return p;
    else
        return MenorElemento(p->esq);

} /* MenorElemento */

ImplBase MaiorElemento(ImplBase p)
{
    /* Devolve o maior Elemento da Base indicada. */

    if (p->dir == NULL)
        return p;
    else
        return MaiorElemento(p->dir);

} /* MaiorElemento */

Boolean RemoveAux(ImplBase* p, int ra, Boolean* alt)
{
    ImplBase aux;
    Aluno aluno_aux;

    /* 'ra' n�o encontrado. */
    if (*p == NULL)
        return false;

    /* 'ra' encontrado. */
    if (ra == (*p)->info.ra) {
        if ((*p)->dir == NULL) {
            /* Remove o elemento e coloca sua sub�rvore esquerda no seu lugar. */
            aux = *p;
            *p = aux->esq;
            FREE(aux->info.nome);
            FREE(aux);
            *alt = true;
            return true;

        }
        else if ((*p)->esq == NULL) {
            aux = *p;
            *p = aux->dir;
            FREE(aux->info.nome);
            FREE(aux);
            *alt = true;
            return true;
        }
        else {
            /* Troca o elemento que vai remover por seu sucessor da inordem. */
            aux = MenorElemento((*p)->dir);
            aluno_aux = aux->info;
            aux->info.nome = (*p)->info.nome;

            /* Remove o elemento de sua posi��o inicial. */
            RemoveAux(p, aluno_aux.ra, alt);

            (*p)->info = aluno_aux;
            return true;

        }
    }

    /* Desce � Direita. */
    if ((*p)->info.ra < ra) {
        /* N�o houve Inser��o. */
        if (!RemoveAux(&((*p)->dir), ra, alt))
            return false;

        /* N�o houve mudan�a na altura. */
        if (!(*alt))
            return true;

        switch ((*p)->bal) {
        case MAIS:
            /* Continua a propaga��o de mudan�a de altura. */
            (*p)->bal = ZERO;

            break; /* switch */

        case ZERO:
            /* Termina a propaga��o de mudan�a na altura. */
            (*p)->bal = MENOS;
            *alt = false;

            break; /* switch */

        case MENOS:
            /* Rotaciona a �rvore. */
            aux = *p;

            if ((aux->esq)->bal == MAIS) {
                ImplBase auxEsq = aux->esq;
                
                RotacaoLR(p);

                /* Corre��o dos fatores de Balanceamento. */
                if ((*p)->bal == ZERO) {
                    auxEsq->bal = ZERO;
                    aux->bal = ZERO;
                }
                else if ((*p)->bal == MAIS) {
                    auxEsq->bal = MENOS;
                    aux->bal = ZERO;
                }
                else {
                    auxEsq->bal = ZERO;
                    aux->bal = MAIS;
                }

                (*p)->bal = ZERO;

            }
            else {
                RotacaoLL(p);

                /* Corre��o dos fatores de Balanceamento. */
                if ((*p)->bal == ZERO) {
                    /* Termina a propaga��o de mudan�a na altura. */
                    *alt = false;
                    (*p)->bal = MAIS;
                    aux->bal = MENOS;
                }
                else {
                    (*p)->bal = ZERO;
                    aux->bal = ZERO;
                }
            }

            break; /* switch */

        }

        return true;

    }
    else
    {
        /* Desce � esquerda. */

        /* N�o houve Inser��o. */
        if (!RemoveAux(&((*p)->esq), ra, alt))
            return false;

        /* N�o houve mudan�a na altura. */
        if (!(*alt))
            return true;

        switch ((*p)->bal) {
        case MENOS:
            /* Continua a propaga��o de mudan�a de altura. */
            (*p)->bal = ZERO;

            break; /* switch */

        case ZERO:
            /* Termina a propaga��o de mudan�a na altura. */
            (*p)->bal = MAIS;
            *alt = false;

            break; /* switch */

        case MAIS:
            /* Rotaciona a �rvore. */
            aux = *p;

            if ((aux->dir)->bal == MENOS) {
                ImplBase auxDir = aux->dir;

                RotacaoRL(p);

                /* Corre��o dos fatores de Balanceamento. */
                if ((*p)->bal == ZERO) {
                    auxDir->bal = ZERO;
                    aux->bal = ZERO;
                }
                else if ((*p)->bal == MAIS) {
                    auxDir->bal = ZERO;
                    aux->bal = MENOS;
                }
                else {
                    auxDir->bal = MENOS;
                    aux->bal = ZERO;
                }

                (*p)->bal = ZERO;
            }
            else {
                RotacaoRR(p);

                /* Corre��o dos fatores de Balanceamento. */
                if ((*p)->bal == ZERO) {
                    /* Termina a propaga��o de mudan�a na altura. */
                    *alt = false;
                    aux->bal = MAIS;
                    (*p)->bal = MENOS;
                }
                else {
                    aux->bal = ZERO;
                    (*p)->bal = ZERO;
                }
            }
            break; /* switch */
        }
        return true;

    }

} /* RemoveAux */

Boolean RemoveBase(Base *p, int ra)
{
    /* Devolve 'true' se um registro com 'ra' p�de ser removido da
     * base 'p';  caso contr�rio devolve 'false'.
     *
     * A IMPLEMENTA��O DESTA FUN��O � OPCIONAL.
     *
     */

    ImplBase* aux = (ImplBase*) p;
    Boolean alt = false;

    if(!RemoveAux(aux, ra, &alt))
        return false;
    else
        return true;

} /* RemoveBase */
