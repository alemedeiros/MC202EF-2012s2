/* Programa: calculadora.c (Calculadora de polinômios) */
/* Autor: Alexandre N. de Medeiros        RA115966     */
/* Disciplina: MC202                      Turma E      */
/* Data: 30/ago/2011                                   */
/* Revisado: 16/set/2012                               */


/* Módulo de cálculo de expressões pós-fixas sobre uma base de dados     */
/* formada por polinômios em uma variável.                               */

#include <stdlib.h>
#include <ctype.h>
#include <stdio.h>

#include "pilha.h"
#include "polinomios.h"
#include "balloc.h"
#include "boolean.h"

/* Mensagens de erro para este módulo.                                     */

#define MSG_ERRO_NOME_INVALIDO "nome inválido para a base de polinômios."
#define MSG_ERRO_POLINOMIO_NAO_INICIALIZADO "tentativa de recuperar polinômio\
não inicializado."
#define MSG_ERRO_FALTA_OPERANDO "número insuficiente de operandos."
#define MSG_ERRO_FALTA_OPERADOR  "número insuficiente de operandores."
#define MSG_ERRO_CARACTERE_INVALIDO "caractere inválido."

#define IMPRIME_ERRO(msg)  {printf("Erro: %s\n",msg); exit(0); }

#define TAM_BASE 5
Polinomio vetorPoli[TAM_BASE];

void InicializaBasePolinomios()
/* Inicializa polinômios com NULL, indicando que não há polinômios       */
/* válidos na base.                                                      */
{
    int i;

    for (i = 0; i < TAM_BASE; i++)
        vetorPoli[i] = NULL;

    return;

} /* InicializaBasePolinomios */

Polinomio RecuperaPolinomio(char x)
/* Retorna o polinômio de nome x.                                        */
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
/* Armazena o polinômio p sob o nome x na base.                          */
{
    x = toupper(x);

    if (x >= 'A' && x < 'A' + TAM_BASE)
        vetorPoli[x - 'A'] = p;
    else
        IMPRIME_ERRO(MSG_ERRO_NOME_INVALIDO);

    return;

} /* ArmazenaPolinomio */

/*** Cálculo da expressão                                                 */

/* Definição dos elementos da pilha. Polinômios temporários devem ser     */
/* liberados após terem sido utilizados. Polinômios da base só são        */
/* liberados quando o usuário invoca libera.                              */
typedef struct ElemPilha
{
    Polinomio poli;
    Boolean temp;
} ElemPilha;

Polinomio CopiaPolinomio (Polinomio p)
/* Retorna uma cópia do polinomio 'p'                                      */
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
/* Cria e empilha um nó do tipo ElemPilha.                                 */
{
    ElemPilha *elem = MALLOC (sizeof(ElemPilha));
    elem->poli = poli;
    elem->temp = temp;
    Empilha (pilha, elem);

    return;

} /* EmpilhaOperando */

Boolean Operando(char c)
/* Verifica se um caractere corresponde a um operando válido.              */
{
    return (c >= 'a' && c < 'a'+TAM_BASE) || (c >= 'A' && c < 'A'+TAM_BASE);

} /* Operando */

Polinomio CalcExpr(char* expr)
/* Retorna o polinômio referente à expressão dada                        */
{
    char aux;
    Pilha duracell;
    Polinomio res;
    ElemPilha *op1, *op2, *final;

    /* Inicializa Pilha da expressão */
    CriaPilha(&duracell);

    while(*expr != '\0') {
        if (Operando(*expr)) {
            /* Empilha polinômio. */
            aux = toupper(*expr);
            EmpilhaOperando(&duracell, vetorPoli[(aux - 'A')], false);
        } else
            switch(*expr) {
            case '+':
            case '-':
            case '*':
                /* Operadores Binários */

                /* Desempilha os operandos. */
                op2 = VerificaDesempilha(&duracell);
                op1 = VerificaDesempilha(&duracell);

                if (op1 == NULL || op2 == NULL)
                    IMPRIME_ERRO(MSG_ERRO_FALTA_OPERANDO);

                /* Empilha o resultado da Operação. */
                if (*expr == '+')
                    EmpilhaOperando(&duracell, SomaPolinomios(op1->poli, op2->poli), true);
                if (*expr == '-')
                    EmpilhaOperando(&duracell, SubPolinomios(op1->poli, op2->poli), true);
                if (*expr == '*')
                    EmpilhaOperando(&duracell, MultPolinomios(op1->poli, op2->poli), true);

                /* Libera a memoria dinâmica necessária. */
                if (op1->temp)
                    LiberaPolinomio(op1->poli);
                if (op2->temp)
                    LiberaPolinomio(op2->poli);

                FREE(op1);
                FREE(op2);

                break;

            case '~':
                /* Operador unário */

                /* Desempilha o operando. */
                op1 = VerificaDesempilha(&duracell);

                /* Empilha o resultado da Operação. */
                EmpilhaOperando(&duracell, MultTermo(op1->poli, 0, -1.0), true);

                /* Libera a memoria dinâmica necessária. */
                if (op1->temp)
                    LiberaPolinomio(op1->poli);

                FREE(op1);

                break;

            default:
                /* Erro: nenhum operador válido. */
                IMPRIME_ERRO(MSG_ERRO_CARACTERE_INVALIDO);
            }

        /* Avança para o próximo caractere da expressão. */
        expr += 1;
    }

    final = VerificaDesempilha(&duracell);

    if (PilhaVazia(&duracell)) {
        /* Pilha Vazia, retorna resultado após liberar a memória dinâmica. */
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
