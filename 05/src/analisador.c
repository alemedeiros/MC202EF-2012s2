/* Programa: analisador.c (Análise sintática)          */
/* Autor: Alexandre N. de Medeiros        RA115966     */
/* Disciplina: MC202                      Turma E      */
/* Data: 06/sep/2011                                   */
/* Revisado: 06/oct/2012                               */

/*
 * analisador.c: Módulo de transformação de expressões na notação
 * infixa para pós-fixa.
 */

#include "analisador.h"
#include <ctype.h>

/* Definição de booleano. */
typedef enum { false, true } Boolean;

/* Variáveis globais a este módulo */

char *in;  /* Cadeia e índice para expressão infixa (entrada). */
int indIn;

char *pos; /* Cadeia e índice para expressão pósfixa (saída). */
int indPos;

Erro resCorreto = {EXPR_VALIDA,0}; /* resultado correto */

/* Macros úteis */
#define PULA_ESPACOS()      while (in[indIn] == ' ') indIn++
#define RETORNA_ERRO(err)   if (err.codigoErro != EXPR_VALIDA) return err

/* Protótipos das funções mutuamente recursivas  */
Erro Expressao();
Erro Termo();
Erro Fator();
Erro Primario();

/* Funções auxiliares */
Erro ProxChar();
Erro montaErro(int codigo, int pos);

/*************************************************************/
/*                 Função   principal                        */
/*************************************************************/

Erro InPos(char *infixa, char *posfixa)
{
    /*
     * Transforma uma expressão da notação infixa para a pós-fixa. Em caso
     * de erro, devolve o código e a posição na cadeia de entrada onde o
     * erro foi encontrado.
     */

    Erro err;

    /* Copia as entradas para as variáveis globais e marca o indice de posição como 0. */
    in = infixa;
    pos = posfixa;
    indPos = indIn = 0;

    /* Avança até o primeiro Caractere. */
    err = ProxChar();
    RETORNA_ERRO(err);

    /* Verifica se o primeiro caractere é fim de cadeia, ou seja, se a cadeia só possue espaços. */
    if (in[indIn] == '\0')
        return montaErro(CADEIA_DE_BRANCOS, 0);

    /* Inicializa a análise da expressão */
    err = Expressao();
    RETORNA_ERRO(err);

    /* Sobrou algum caractere (operando) */
    if (in[indIn] != '\0')
        return montaErro(OPERADOR_ESPERADO, indIn);

    pos[indPos] = '\0';
    return resCorreto;

}

/*************************************************************/
/*           Funções de implementação do analisador          */
/*************************************************************/
Erro montaErro(int codigo, int posicao)
{
    /* Devolve estrutura com código de erro e posição */

    Erro err;

    err.posicao = posicao;
    err.codigoErro = codigo;

    return err;

} /* montaErro */

Erro ProxChar()
{
    /* Avança até o próximo caractere e verifica sua validade. */

    char atual;

    PULA_ESPACOS();
    atual = in[indIn];

    /* Verifica se o caractere atual está dentre os caracteres válidos. */
    if ((atual >= 'a' && atual <= 'z') || (atual >= '(' && atual <= '+') ||
        atual == '-' || atual == '/' || atual == '^' || atual == '\0')
        return resCorreto;
    else
        return montaErro(CARACTERE_INVALIDO, indIn);

} /* ProxChar */

Erro Expressao()
{
    /* Processa uma expressão da cadeia de entrada.  */

    Erro err;
    char op;
    int unario = 0;

    /* Verifica operador unário. */
    op = in[indIn];
    if (op == '+' || op == '-') {
        if (op == '+')
            unario = 1;

        if (op == '-')
            unario = -1;

        indIn++;

        err = ProxChar();
        RETORNA_ERRO(err);
    }

    /* Processa o primeiro termo da expressão. */
    err = Termo();
    RETORNA_ERRO(err);

    /* Imprime operador unário, caso existente. */
    switch(unario) {
    case 1:
        pos[indPos] = '&';
        indPos++;
        break;

    case -1:
        pos[indPos] = '~';
        indPos++;
        break;
    }

    /* Processa todos outros termos da expressão. */
    op = in[indIn];
    while ((op == '+') || (op == '-')) {
        indIn++;

        err = ProxChar();
        RETORNA_ERRO(err);

        err = Termo();
        RETORNA_ERRO(err);

        pos[indPos] = op;
        indPos++;

        op = in[indIn];
    }

    return resCorreto;

} /* Expressao */


Erro Termo()
{
    /* Processa um termo da cadeia de entrada.  */

    Erro err;
    char op;

    /* Processa o primeiro fator do termo. */
    err = Fator();
    RETORNA_ERRO(err);

    /* Processa todos outros fatores do termo. */
    op = in[indIn];
    while ((op == '*') || (op == '/')) {
        indIn++;

        err = ProxChar();
        RETORNA_ERRO(err);

        err = Fator();
        RETORNA_ERRO(err);

        pos[indPos] = op;
        indPos++;

        op = in[indIn];
    }

    return resCorreto;

} /* Termo */


Erro Fator()
{
    /* Processa um fator da cadeia de entrada.  */
    Erro err;

    /* Processa o intermediario do fator. */
    err = Primario();
    RETORNA_ERRO(err);

    /* Verifica se há outro fator no fator. */
    if (in[indIn] == '^') {
        indIn++;

        err = ProxChar();
        RETORNA_ERRO(err);

        err = Fator();
        RETORNA_ERRO(err);

        pos[indPos] = '^';
        indPos++;
    }

    return resCorreto;

} /* Fator */

Erro Primario()
{
    /* Processa um fator primário da cadeia de entrada.  */

    Erro err;
    char atual;

    atual = in[indIn];

    switch (atual) {
    case '(':
        /* Caso: p = (e). */

        indIn++;

        err = ProxChar();
        RETORNA_ERRO(err);

        err = Expressao();
        RETORNA_ERRO(err);

        /* Confere se no final da expressão há um ')' */
        if (in[indIn] == ')') {
            indIn++;

            err = ProxChar();
            RETORNA_ERRO(err);
        }
        else
            return montaErro(FECHA_PARENTESE_ESPERADO, indIn);

        break; /* switch */

    default:
        /* Caso: p = x. */

        pos[indPos] = in[indIn];

        indPos++;
        indIn++;

        err = ProxChar();
        RETORNA_ERRO(err);

        break; /* switch */

    case ')':
    case '/':
    case '*':
    case '+':
    case '-':
    case '\0':
        /* Casos Inválidos: Ausencia de Operando. */
        return montaErro(OPERANDO_ESPERADO, indIn);

    }

    return resCorreto;

} /* Primario */
