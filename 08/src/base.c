/* Programa: base.c (Base de dados com árvores AVL) */
/* Autor: Alexandre N. de Medeiros        RA115966  */
/* Disciplina: MC202                      Turma E   */
/* Data: 04/out/2011                                */
/* Revisado: 18/dez/2012                            */

/*
 * Arquivo base.c: implementação das funções de manipulação da base.
 */

#include <stdio.h>
#include "base.h"
#include "balloc.h"

/* Constantes de balanceamento. */
#define ZERO 0
#define MAIS 1
#define MENOS -1

typedef struct AuxNoArv {
    Aluno info;                  /* registros de informação */
    struct AuxNoArv *esq,*dir;   /* subárvores */
    short int bal;               /* fator de balanceamento */
} NoArv, * ImplBase;

/*
   Complete o resto do arquivo; se não implementar a função de
   remoção, coloque apenas um esqueleto vazio devolvendo qualquer
   valor booleano para evitar erros de compilação.
*/

Base CriaBase()
{
    /* Devolve apontador para uma base vazia */
    return NULL;

} /* CriaBase */

ImplBase CriaNo(Aluno a)
{
    /* Cria um nó com as informações 'a' e fator 0. */
    ImplBase no = MALLOC(sizeof(NoArv));

    no->bal = ZERO;
    no->info = a;
    no->esq = NULL;
    no->dir = NULL;

    return no;

} /* CriaNo */

Base SubEsq(Base *p)
{
    /* Devolve a subárvore esquerda da base 'p' se não for vazia; caso
     * contrário devolve NULL.
     */

    ImplBase aux = (ImplBase) *p;

    if (*p == NULL)
        return NULL;
    else
        return (Base) aux->esq;

} /* SubEsq */

Base SubDir(Base *p)
{
    /* Devolve a subárvore direita da base 'p' se não for vazia; caso
     * contrário devolve NULL.
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
     * subárvore direita menos a altura da subárvore esquerda; devolve
     * zero se a árvore é vazia.
     */

    return ((ImplBase) *p)->bal;

} /* FatorBal */

ImplBase* ProcuraPos(ImplBase* p, int ra)
{
    /* Procura a posição onde está ou deveria estar o ra indicado. */

    /* 'p' deveria estar ou esta aqui! */
    if (*p == NULL || (*p)->info.ra == ra)
        return p;
    else
        /* Procura posição seguindo a definição da árvore de busca. */
        if ((*p)->info.ra < ra)
            return ProcuraPos(&((*p)->dir), ra);
        else
            return ProcuraPos(&((*p)->esq), ra);

} /* ProcuraPos */

void RotacaoRR(ImplBase *p)
{
    /* Rotação simples RR. */
    ImplBase aux1 = (*p)->dir, aux2 = *p;

    *p = aux1;
    aux2->dir = aux1->esq;
    aux1->esq = aux2;

    return;
} /* RotacaoRR */

void RotacaoRL(ImplBase *p)
{
    /* Rotação dupla RL. */
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
    /* Rotação dupla LR. */
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
    /* Rotação simples LL. */
    ImplBase aux1 = (*p)->esq, aux2 = *p;

    *p = aux1;
    aux2->esq = aux1->dir;
    aux1->dir = aux2;

    return;
} /* RotacaoLL */

Boolean InsereAux(ImplBase* p, Aluno a, Boolean* alt)
{
    /* Insere a informação 'a' na árvore AVL, mantendo
     * suas propriedades.
     */

    ImplBase aux;

    /* Posição de inserção vazia. */
    if (*p == NULL) {
        *p = CriaNo(a);
        *alt = true;
        return true;
    }

    /* 'ra' repetido! retorna false. */
    if (a.ra == (*p)->info.ra)
        return false;

    /* Desce à Direita. */
    if ((*p)->info.ra < a.ra) {
        /* Não houve Inserção. */
        if (!InsereAux(&((*p)->dir), a, alt))
            return false;

        /* Não houve mudança na altura. */
        if (!(*alt))
            return true;

        /* Mudança na altura! */
        switch ((*p)->bal) {
        case MENOS:
            /* Termina a propagação de mudança na altura. */
            (*p)->bal = ZERO;
            *alt = false;

            break; /* switch */

        case ZERO:
            /* Continua a propagação de mudança de altura. */
            (*p)->bal = MAIS;

            break; /* switch */

        case MAIS:
            /* Rotaciona a árvore e termina a propagação de
             * mudança na altura.
             */
            aux = *p;

            if (((*p)->dir)->bal == MAIS) {
                RotacaoRR(p);

                /* Correção dos fatores de Balanceamento. */
                aux->bal = ZERO;

            }
            else {
                ImplBase auxDir = aux->dir;

                RotacaoRL(p);

                /* Correção dos fatores de Balanceamento. */
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
        /* Desce à esquerda. */

        /* Não houve Inserção. */
        if (!InsereAux(&((*p)->esq), a, alt))
            return false;

        /* Não houve mudança na altura. */
        if (!(*alt))
            return true;

        switch ((*p)->bal) {
        case MAIS:
            /* Termina a propagação de mudança na altura. */
            (*p)->bal = ZERO;
            *alt = false;

            break; /* switch */

        case ZERO:
            /* Continua a propagação de mudança de altura. */
            (*p)->bal = MENOS;

            break; /* switch */

        case MENOS:
            /* Rotaciona a árvore e termina a propagação de
             * mudança na altura.
             */
            aux = *p;

            if ((aux->esq)->bal == MENOS) {
                RotacaoLL(p);

                /* Correção dos fatores de Balanceamento. */
                aux->bal = ZERO;

            }
            else {
                /* Rotação dupla LR. */
                ImplBase auxEsq = aux->esq;

                RotacaoLR(p);

                /* Correção dos fatores de Balanceamento. */
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
    /* Insere o registro 'a' na base 'p' se não existe aluno
     * com o mesmo valor de 'ra', e devolve 'true';  caso
     * contrário devolve 'false'.
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
     * base 'p';  caso contrário devolve 'false'. 'a' conterá
     * os dados do aluno, se encontrado.
     */

    /* Procura a posição onde 'ra' deveria estar. */
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
     * Caso contrário, retorna 1 + a maior altura de suas sub-árvores.
     */

    ImplBase aux = (ImplBase) *p;

    if(*p == NULL)
        return 0;
    else
        return 1 + Max(AlturaBase((Base*) &aux->esq), AlturaBase((Base*) &aux->dir));

} /* AlturaBase */

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

void PercorreBase(Base *p, TipoVisita Visita)
{
    /* Executa um percurso inordem na base, invocando a função Visita
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

    /* 'ra' não encontrado. */
    if (*p == NULL)
        return false;

    /* 'ra' encontrado. */
    if (ra == (*p)->info.ra) {
        if ((*p)->dir == NULL) {
            /* Remove o elemento e coloca sua subárvore esquerda no seu lugar. */
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

            /* Remove o elemento de sua posição inicial. */
            RemoveAux(p, aluno_aux.ra, alt);

            (*p)->info = aluno_aux;
            return true;

        }
    }

    /* Desce à Direita. */
    if ((*p)->info.ra < ra) {
        /* Não houve Inserção. */
        if (!RemoveAux(&((*p)->dir), ra, alt))
            return false;

        /* Não houve mudança na altura. */
        if (!(*alt))
            return true;

        switch ((*p)->bal) {
        case MAIS:
            /* Continua a propagação de mudança de altura. */
            (*p)->bal = ZERO;

            break; /* switch */

        case ZERO:
            /* Termina a propagação de mudança na altura. */
            (*p)->bal = MENOS;
            *alt = false;

            break; /* switch */

        case MENOS:
            /* Rotaciona a árvore. */
            aux = *p;

            if ((aux->esq)->bal == MAIS) {
                ImplBase auxEsq = aux->esq;
                
                RotacaoLR(p);

                /* Correção dos fatores de Balanceamento. */
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

                /* Correção dos fatores de Balanceamento. */
                if ((*p)->bal == ZERO) {
                    /* Termina a propagação de mudança na altura. */
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
        /* Desce à esquerda. */

        /* Não houve Inserção. */
        if (!RemoveAux(&((*p)->esq), ra, alt))
            return false;

        /* Não houve mudança na altura. */
        if (!(*alt))
            return true;

        switch ((*p)->bal) {
        case MENOS:
            /* Continua a propagação de mudança de altura. */
            (*p)->bal = ZERO;

            break; /* switch */

        case ZERO:
            /* Termina a propagação de mudança na altura. */
            (*p)->bal = MAIS;
            *alt = false;

            break; /* switch */

        case MAIS:
            /* Rotaciona a árvore. */
            aux = *p;

            if ((aux->dir)->bal == MENOS) {
                ImplBase auxDir = aux->dir;

                RotacaoRL(p);

                /* Correção dos fatores de Balanceamento. */
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

                /* Correção dos fatores de Balanceamento. */
                if ((*p)->bal == ZERO) {
                    /* Termina a propagação de mudança na altura. */
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
    /* Devolve 'true' se um registro com 'ra' pôde ser removido da
     * base 'p';  caso contrário devolve 'false'.
     *
     * A IMPLEMENTAÇÃO DESTA FUNÇÃO É OPCIONAL.
     *
     */

    ImplBase* aux = (ImplBase*) p;
    Boolean alt = false;

    if(!RemoveAux(aux, ra, &alt))
        return false;
    else
        return true;

} /* RemoveBase */
