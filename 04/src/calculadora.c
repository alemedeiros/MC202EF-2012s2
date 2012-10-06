/* Programa: calculadora.c (Calculadora de polin�mios) */
/* Autor: Alexandre N. de Medeiros        RA115966     */
/* Disciplina: MC602                      Turma E      */
/* Data: 30/ago/2011                                   */
/* Revisado: 16/set/2012                               */


/* M�dulo de c�lculo de express�es p�s-fixas sobre uma base de dados     */
/* formada por polin�mios em uma vari�vel.                               */

#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>

#include "pilha.h"
#include "polinomios.h"
#include "balloc.h"
#include "boolean.h"

/* Mensagens de erro para este m�dulo.                                     */

#define MSG_ERRO_NOME_INVALIDO "nome inv�lido para a base de polin�mios."
#define MSG_ERRO_POLINOMIO_NAO_INICIALIZADO "tentativa de recuperar polin�mio\
n�o inicializado."
#define MSG_ERRO_FALTA_OPERANDO "n�mero insuficiente de operandos."
#define MSG_ERRO_FALTA_OPERADOR  "n�mero insuficiente de operandores."
#define MSG_ERRO_CARACTERE_INVALIDO "caractere inv�lido."

#define IMPRIME_ERRO(msg)  {printf("Erro: %s\n",msg); exit(0); }

#define TAM_BASE 5
Polinomio vetorPoli[TAM_BASE];

void InicializaBasePolinomios()
/* Inicializa polin�mios com NULL, indicando que n�o h� polin�mios       */
/* v�lidos na base.                                                      */
{
    int i;

    for (i = 0; i < TAM_BASE; i++)
        vetorPoli[i] = NULL;

    return;

} /* InicializaBasePolinomios */

Polinomio RecuperaPolinomio(char x)
/* Retorna o polin�mio de nome x.                                        */
{
    Polinomio poli;

    x = toupper(x);

    if (x >= 'A' && x < 'A' + TAM_BASE)
        poli =  vetorPoli[x - 'A'];
    else {
        IMPRIME_ERRO(MSG_ERRO_NOME_INVALIDO);
        return NULL;
    }

    if (poli == NULL)
        IMPRIME_ERRO(MSG_ERRO_POLINOMIO_NAO_INICIALIZADO);

    return poli;

} /* RecuperaPolinomio */

void ArmazenaPolinomio(char x, Polinomio p)
/* Armazena o polin�mio p sob o nome x na base.                          */
{
    x = toupper(x);

    if (x >= 'A' && x < 'A' + TAM_BASE)
        vetorPoli[x - 'A'] = p;
    else
        IMPRIME_ERRO(MSG_ERRO_NOME_INVALIDO);

    return;

} /* ArmazenaPolinomio */

/*** C�lculo da express�o                                                 */

/* Defini��o dos elementos da pilha. Polin�mios tempor�rios devem ser     */
/* liberados ap�s terem sido utilizados. Polin�mios da base s� s�o        */
/* liberados quando o usu�rio invoca libera.                              */
typedef struct ElemPilha
{
    Polinomio poli;
    Boolean temp;
} ElemPilha;

Polinomio CopiaPolinomio (Polinomio p)
/* Retorna uma c�pia do polinomio 'p'                                      */
{
    Polinomio aux, res;

    aux = CriaPolinomioNulo();
    res = SomaPolinomios(p,aux);

    LiberaPolinomio(aux);

    return res;

} /* CopiaPolinomio */

ElemPilha* VerificaDesempilha (Pilha* pilha)
/* Desempilha um elemento, enviando uma mensagem de erro caso a pilha      */
/* esteja vazia.                                                           */
{
    if (PilhaVazia(pilha)) {
        IMPRIME_ERRO(MSG_ERRO_FALTA_OPERANDO);
        return NULL;
    }

    return (ElemPilha*) Desempilha(pilha);

} /* VerificaDesempilha */

void EmpilhaOperando(Pilha* pilha, Polinomio poli, Boolean temp)
/* Cria e empilha um n� do tipo ElemPilha.                                 */
{
    ElemPilha *elem = MALLOC (sizeof(ElemPilha));
    elem->poli = poli;
    elem->temp = temp;
    Empilha (pilha, elem);

    return;

} /* EmpilhaOperando */

Boolean Operando(char c)
/* Verifica se um caractere corresponde a um operando v�lido.              */
{
    return (c >= 'a' && c < 'a'+TAM_BASE) || (c >= 'A' && c < 'A'+TAM_BASE);

} /* Operando */

Polinomio CalcExpr(char* expr)
/* Retorna o polin�mio referente � express�o dada                        */
{
    char aux;
    Pilha duracell;
    Polinomio res;
    ElemPilha *op1, *op2, *final;

    /* Inicializa Pilha da express�o */
    CriaPilha(&duracell);

    while(*expr != '\0') {
        if (Operando(*expr)) {
            /* Empilha polin�mio. */
            aux = toupper(*expr);
            EmpilhaOperando(&duracell, vetorPoli[(aux - 'A')], false);
        } else
            switch(*expr) {
            case '+':
            case '-':
            case '*':
                /* Operadores Bin�rios */

                /* Desempilha os operandos. */
                op2 = VerificaDesempilha(&duracell);
                op1 = VerificaDesempilha(&duracell);

                if (op1 == NULL || op2 == NULL)
                    IMPRIME_ERRO(MSG_ERRO_FALTA_OPERANDO);

                /* Empilha o resultado da Opera��o. */
                if (*expr == '+')
                    EmpilhaOperando(&duracell, SomaPolinomios(op1->poli, op2->poli), true);
                if (*expr == '-')
                    EmpilhaOperando(&duracell, SubPolinomios(op1->poli, op2->poli), true);
                if (*expr == '*')
                    EmpilhaOperando(&duracell, MultPolinomios(op1->poli, op2->poli), true);

                /* Libera a memoria din�mica necess�ria. */
                if (op1->temp)
                    LiberaPolinomio(op1->poli);
                if (op2->temp)
                    LiberaPolinomio(op2->poli);

                FREE(op1);
                FREE(op2);

                break;

            case '~':
                /* Operador un�rio */

                /* Desempilha o operando. */
                op1 = VerificaDesempilha(&duracell);

                /* Empilha o resultado da Opera��o. */
                EmpilhaOperando(&duracell, MultTermo(op1->poli, 0, -1.0), true);

                /* Libera a memoria din�mica necess�ria. */
                if (op1->temp)
                    LiberaPolinomio(op1->poli);

                FREE(op1);

                break;

            default:
                /* Erro: nenhum operador v�lido. */
                IMPRIME_ERRO(MSG_ERRO_CARACTERE_INVALIDO);
            }

        /* Avan�a para o pr�ximo caractere da express�o. */
        expr += 1;
    }

    final = VerificaDesempilha(&duracell);

    if (PilhaVazia(&duracell)) {
        /* Pilha Vazia, retorna resultado ap�s liberar a mem�ria din�mica. */
        res = final->poli;

        if (!final->temp)
            res = CopiaPolinomio(final->poli);

        FREE(final);
        return res;

    } else {
        /* Erro: Sobraram elementos na pilha. */
        IMPRIME_ERRO(MSG_ERRO_FALTA_OPERADOR);
        return NULL;
    }

} /* CalcExpr */
