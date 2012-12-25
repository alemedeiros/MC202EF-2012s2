/* Programa: multPoli.c (Polinomios em multiplas variáveis)         */
/* Autor: Alexandre N. de Medeiros                      RA115966    */
/* Disciplina: MC602                                    Turma E     */
/* Data: 20/out/2011                                                */
/* Revisado: 25/dez/2012                                            */

/*
 * multPoli.c - Arquivo para implementação de polinômios em 
 *              múltiplas variáveis.
 */

#include <stdio.h>
#include <string.h>
#include "balloc.h"
#include "multPoli.h"

typedef enum {tipoPoli, tipoConst} tipoNo;

typedef struct Termo {
    tipoNo tipo;
    union {
        struct Termo *poli;
        float coef;
    } info;
    int expo;
    struct Termo *prox;
} Termo, *ImplPolinomio;


/********************************************************************/

Polinomio CriaPolinomioNulo()
{
    /* Devolve um novo polinômio identicamente nulo. */

    return NULL;
} /* CriaPolinomioNulo */

Boolean PolinomioNulo(Polinomio p)
{
    /* Verifica se o polinômio 'p' é identicamente nulo. */

    if (p == NULL)
        return true;
    else
        return false;
} /* PolinomioNulo */

ImplPolinomio CriaTermoAux(float coef, int* exps, int numVars)
{
    /* Cria um termo de acordo com o vetor de expoentes e coeficiente. */
    ImplPolinomio termo;

    termo = MALLOC(sizeof(Termo));

    if (numVars == 0) {
        /* Ultimo nó, guarda o coeficiente. */
        termo->tipo = tipoConst;
        termo->info.coef = coef;
        termo->expo = *exps;
        termo->prox = NULL;
    } else {
        termo->tipo = tipoPoli;
        termo->expo = *exps;
        termo->prox = NULL;
        termo->info.poli = CriaTermoAux(coef, exps + 1, numVars - 1);
    }

    return termo;
} /* CriaTermoAux */

ImplPolinomio CriaTermoAux2(ImplPolinomio coef, int expo)
{
    /* Cria um termo cujo coeficiente é um polinomio. */

    if (coef == NULL)
        return NULL;

    ImplPolinomio termo = MALLOC(sizeof(Termo));

    termo->tipo = tipoPoli;
    termo->expo = expo;
    termo->prox = NULL;
    termo->info.poli = coef;

    return termo;
} /* CriaTermoAux2 */

Polinomio CriaTermo(float coef, int exps[], int numVars)
{
    /* Devolve um novo polinômio formado por um único termo da forma 
     * coef x1^exp1 x2^exp2 x3^exp3 ..., onde 'numVars' é o número de
     * variáveis do polinômio e é o tamanho do vetor de expoentes 'exps'.
     */

    return CriaTermoAux(coef,exps,numVars - 1);
} /* CriaTermo */

void LiberaPolinomio(Polinomio p)
{
    /* Libera toda a memória dinâmica ocupada por um polinômio. */

    ImplPolinomio aux1 = (ImplPolinomio) p, aux2;

    while (aux1 != NULL) {
        if(aux1->tipo == tipoPoli)
            LiberaPolinomio(aux1->info.poli);

        aux2 = aux1->prox;
        FREE(aux1);
        aux1 = aux2;
    }

    return;
} /* LiberaPolinomio */

Polinomio CopiaPolinomio(Polinomio p)
{
    /* Devolve uma cópia do polinômio p, sem alterá-lo. */

    return SomaPolinomios(p, NULL);
} /* CopiaPolinomio */

ImplPolinomio SomaPolinomiosAux(ImplPolinomio a, ImplPolinomio b)
{
    /* Retorna a soma dos polinomios a e b, sem alterá-los. */

    int expo;
    ImplPolinomio qA, qB, res, qRes, aux;

    qA = a;
    qB = b;
    aux = res = qRes = NULL;

    while (qA != NULL || qB != NULL) {
        if (qA == NULL || (qB != NULL && qA->expo < qB->expo)) {
            /* Insere elemento de b. */
            if (qB->tipo == tipoConst)
                qRes = CriaTermoAux(qB->info.coef, &qB->expo, 0);
            else
                qRes = CriaTermoAux2(SomaPolinomiosAux(qB->info.poli, NULL), qB->expo);

            qB = qB->prox;
        } else if (qB == NULL || (qA != NULL && qA->expo > qB->expo)) {
            /* Insere elemento de a. */
            if (qA->tipo == tipoConst)
                qRes = CriaTermoAux(qA->info.coef, &qA->expo, 0);
            else
                qRes = CriaTermoAux2(SomaPolinomiosAux(qA->info.poli, NULL),qA->expo);

            qA = qA->prox;
        } else {
            /* Mesmo Expoente. */
            if (qA->tipo == tipoConst) {
                /* Soma dos coeficiente não é nula. */
                if (qA->info.coef + qB->info.coef != 0) {
                    expo = qA->expo;
                    qRes = CriaTermoAux(qA->info.coef+qB->info.coef, &expo, 0); 
                }
                else
                    qRes = NULL;

            }
            else
                qRes = CriaTermoAux2(SomaPolinomiosAux(qA->info.poli,qB->info.poli), qA->expo);

            qA = qA->prox;
            qB = qB->prox;

            /* Testa se numa camada mais abaixo o polinomio resultante é nulo. */
            if (qRes == NULL)
                continue; /* while */

        }

        /* Insere o Polinômio obtido no resultado. */
        if (res == NULL) {
            /* Inserção do primeiro elemento. */
            res = qRes;
            aux = res;
        } else {
            aux->prox = qRes;
            aux = aux->prox;
        }
    }

    return res;
} /* SomaPolinomiosAux */

Polinomio SomaPolinomios(Polinomio a, Polinomio b)
{
    /* Devolve a soma dos polinômios 'a' e 'b'. Não altera os polinômios
     * dados. Termos nulos não são inseridos no resultado.
     */

    return SomaPolinomiosAux(a, b);

} /* SomaPolinomios */

ImplPolinomio MultPolinomiosAux(ImplPolinomio a, ImplPolinomio b)
{
    /* Retorna o Produto dos polinomios 'a' e 'b', sem alterá-los. */

    int expo;
    ImplPolinomio res, aux, qA, qB, qRes, aux2;

    res = aux = aux2 = NULL;
    qB = b;

    while (qB != NULL) {
        /* Multiplica um termo de 'b' pelo polinomio 'a' a cada ciclo. */
        qA = a;
        while (qA != NULL) {
            if (qA->tipo == tipoConst) {
                expo = qA->expo + qB->expo;
                qRes = CriaTermoAux(qA->info.coef * qB->info.coef, &expo, 0);

            } else
                qRes = CriaTermoAux2(MultPolinomiosAux(qA->info.poli,qB->info.poli), qA->expo + qB->expo);

            qA = qA->prox;

            /* Testa se numa camada mais abaixo o polinomio resultante é nulo. */
            if (qRes == NULL)
                continue; /* while */

            /* Insere o Polinômio obtido no resultado parcial. */
            if (aux2 == NULL) {
                /* Inserção do primeiro elemento. */
                aux2 = qRes;
                aux = aux2;
            } else {
                aux->prox = qRes;
                aux = aux->prox;
            }
        }

        aux = res;

        /* Soma o resultado parcial com o resultado final. */
        res = SomaPolinomios(res,aux2);
        LiberaPolinomio(aux);
        LiberaPolinomio(aux2);
        aux = aux2 = NULL;
        qB = qB->prox;
    }

    return res;

} /* MultPolinomiosAux */

Polinomio MultPolinomios(Polinomio a, Polinomio b)
{
    /* Devolve o produto dos polinômios 'a' e 'b', sem alterá-los. */
    if (a == NULL || b == NULL)
        return NULL;

    return MultPolinomiosAux(a,b);
} /* MultPolinomios */

/********************************************************************/


void ImprimePolinomioAux(Polinomio p, char *vars, int numVars, int indVar);      
void ImprimeTermo(Termo *t, char *vars, int numVars, int indVar, Boolean primeiro);

void ImprimePolinomio(Polinomio p, char *vars) {

    if (p == NULL)
        printf("0");
    else
        ImprimePolinomioAux(p,vars,strlen(vars),0);

    printf("\n");

} /* ImprimePolinomio */


void ImprimePolinomioAux(Polinomio p, char *vars, int numVars, int indVar) {

    ImplPolinomio pp;
    Boolean primeiro=true;

    for (pp=p; pp!=NULL; pp=pp->prox) {
        ImprimeTermo(pp,vars,numVars,indVar,primeiro);
        primeiro = false;
    }

} /* ImprimePolinomioAux */


void ImprimeTermo(Termo *t, char *vars, int numVars, int indVar, Boolean primeiro) {

    int expo = t->expo;
    Boolean constCoef = (t->tipo==tipoConst);
    char var = vars[indVar];

    if (constCoef) {
        float coef = t->info.coef;
        if (coef<0.0) {
            printf(" - ");
            coef = -coef;
        } else {
            if (!primeiro)
                printf(" + ");
        }
        if (expo==0)
            printf("%3.1f", coef);
        else { 			/* expo>0 */
            if (coef!=1.0)
                printf("%3.1f", coef);
        } 
    } else { // coef tipoPoli
        if (primeiro)
            printf("(");
        else
            printf(" + (");
        ImprimePolinomioAux(t->info.poli,vars,numVars,indVar+1);
        printf(")");
    }
    if (expo==1) 
        printf("%c",var);
    else if (expo>1) 
        printf("%c^%d",var,expo);


} /* ImprimeTermo */
