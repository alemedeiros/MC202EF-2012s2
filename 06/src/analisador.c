/* Programa: analisador.c (Análise sintática e árvores)*/
/* Autor: Alexandre N. de Medeiros        RA115966     */
/* Disciplina: MC202                      Turma E      */
/* Data: 20/sep/2011                                   */
/* Revisado: 06/out/2012                               */

/*
 * analisador.c: Módulo de transformação de expressões em árvores
 * binárias e seus percursos.
 */

#include "analisador.h"
#include <stdlib.h>
#include <ctype.h>
#include "balloc.h"

/* Definição de booleano. */
typedef enum { false, true } Boolean;

/* Variáveis globais a este módulo */

char *in;  /* Cadeia e índice para expressão infixa (entrada). */
int indIn;

Erro resCorreto = {EXPR_VALIDA,0}; /* resultado correto */

/* Macro para desprezar espaços em branco na cadeia de entrada. */
/* Para evitar chamadas desnecessárias a esta macro, adotou-se  */
/* seguinte conveção. A macro é invocada uma vez imediatamente  */
/* antes da primeira chamada à função Expressao e imediatamente */
/* após todo o incremento de indIn.                             */
#define DESPREZA_ESPACOS() while (in[indIn] == ' ') indIn++

/* Macro para retornar erro, utilizada para verificar se houve
 * erro numa chamada recursiva quando o programa volta da mesma
 */
#define RETORNA_ERRO(err) if (err.codigoErro != EXPR_VALIDA) return err

/* Macro para encontrar o final de uma cadeia de caracteres, ou seja,
 * procura o caractere '\0'.
 */
#define FIM_DE_CADEIA(str) while(*str != '\0') str++

/* Protótipos das funções mutuamente recursivas. */
/* O resultado é devolvido através da variável 'arv'. */
Erro Expressao(ArvBin *arv);
Erro Termo(ArvBin *arv);
Erro Fator(ArvBin *arv);
Erro Primario(ArvBin *arv);

/* Funções auxiliares */
Erro montaErro(int codigo, int pos);
Erro ProxChar();
ArvBin CriaNo(char info, ArvBin esq, ArvBin dir);

/*************************************************************/
/*                 Função   principal                        */
/*************************************************************/

Erro InArv(char *infixa, ArvBin *arv)
{
    /*
     * Transforma a notação infixa em árvore binária.  Em caso de erro,
     * devolve o código e a posição na cadeia de entrada onde o erro foi
     * encontrado.
     */

    Erro err;

    /* Inicializa as variáveis globais e a árvore. */
    in = infixa;
    indIn = 0;
    *arv = NULL;

    /* Avança até o primeiro Caractere. */
    err = ProxChar();
    RETORNA_ERRO(err);

    /* Verifica se o primeiro caractere é fim de cadeia, ou seja, se a cadeia só possue espaços. */
    if (in[indIn] == '\0')
  	return montaErro(CADEIA_DE_BRANCOS, 0);

    /* Inicializa a análise da expressão */
    err = Expressao(arv);
    RETORNA_ERRO(err);

    /* Sobrou algum caractere (operando), retorna o erro adequado. */
    if (in[indIn] != '\0')
        return montaErro(OPERADOR_ESPERADO, indIn);

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

    DESPREZA_ESPACOS();
    atual = in[indIn];

    /* Verifica se o caractere atual está dentre os caracteres válidos. */
    if ((atual >= 'a' && atual <= 'z') || (atual >= '(' && atual <= '+') ||
        atual == '-' || atual == '/' || atual == '^' || atual == '\0')
        return resCorreto;
    else
        return montaErro(CARACTERE_INVALIDO, indIn);

} /* ProxChar */

ArvBin CriaNo(char info, ArvBin esq, ArvBin dir)
{
    /* Cria um nó para a árvore e retorna seu endereço. */
    ArvBin raiz = MALLOC(sizeof(NoArvBin));

    raiz->info = info;
    raiz->esq = esq;
    raiz->dir = dir;

    return raiz;

} /* CriaNo */

Erro Expressao(ArvBin *arv)
{
    /* Processa uma expressão da cadeia de entrada.  */

    Erro err;
    char op;
    int unario = 0;

    /* Verifica operador unário. */
    if (in[indIn] == '+' || in[indIn] == '-') {
        if (in[indIn] == '+')
            unario = 1;

        if (in[indIn] == '-')
            unario = -1;

        indIn++;

        err = ProxChar();
        RETORNA_ERRO(err);
    }

    /* Processa o primeiro termo da expressão. */
    err = Termo(arv);
    RETORNA_ERRO(err);

    /* Caso haja um operador unario, cria um nó e coloca a árvore obtida até o momento como sua sub-árvore direita. */
    switch(unario) {
    case 1:
        *arv = CriaNo('&', NULL, *arv);
        break;

    case -1:
        *arv = CriaNo('~', NULL, *arv);
        break;
    }

    /* Processa todos outros termos da expressão. */
    op = in[indIn];
    while ((op == '+') || (op == '-')) {
        /* Cria um nó e coloca a árvore obtida até agora como sua sub-árvore
         * esquerda e coloca esse nó como nova raiz.
         */
        *arv = CriaNo(op, *arv, NULL);

        indIn++;

        err = ProxChar();
        RETORNA_ERRO(err);

        /* Insere o próximo termo como sub-árvore direita da raiz. */
        err = Termo(&((*arv)->dir));
        RETORNA_ERRO(err);

        op = in[indIn];
    }

    return resCorreto;

} /* Expressao */

Erro Termo(ArvBin *arv)
{
    /* Processa um termo da cadeia de entrada.  */

    Erro err;
    char op;

    /* Processa o primeiro fator do termo. */
    err = Fator(arv);
    RETORNA_ERRO(err);

    /* Processa todos outros fatores do termo. */
    op = in[indIn];
    while ((op == '*') || (op == '/')) {
        /* Cria um nó e coloca a árvore obtida até agora como sua sub-árvore
         * esquerda e coloca esse nó como nova raiz.
         */
        *arv = CriaNo(op, *arv, NULL);

        indIn++;

        err = ProxChar();
        RETORNA_ERRO(err);

        /* Insere o próximo fator como sub-árvore direita da raiz. */
        err = Fator(&((*arv)->dir));
        RETORNA_ERRO(err);

        op = in[indIn];
    }

    return resCorreto;

} /* Termo */


Erro Fator(ArvBin *arv)
{
    /* Processa um fator da cadeia de entrada.  */
    Erro err;

    /* Processa o intermediario do fator. */
    err = Primario(arv);
    RETORNA_ERRO(err);

    /* Verifica se há outro fator no fator. */
    if (in[indIn] == '^') {
        /* Cria um nó e coloca a árvore obtida até agora como sua sub-árvore
         * esquerda e coloca esse nó como nova raiz.
         */
        *arv = CriaNo('^', *arv, NULL);

        indIn++;

        err = ProxChar();
        RETORNA_ERRO(err);

        /* Insere o próximo fator como sub-árvore direita da raiz. */
        err = Fator(&((*arv)->dir));
        RETORNA_ERRO(err);
    }

    return resCorreto;

} /* Fator */

Erro Primario(ArvBin *arv)
{
    /* Processa um primário da cadeia de entrada.  */

    Erro err;
    char atual;

    atual = in[indIn];

    switch (atual) {
    case '(':
        /* Caso: p = (e). */

        indIn++;

        err = ProxChar();
        RETORNA_ERRO(err);

        err = Expressao(arv);
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

        /* Insere uma folha no endereço recebido. */
        *arv = CriaNo(atual, NULL, NULL);

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


void ArvPre(ArvBin arv, char *pre)
{
    /* Produz a representação pré-fixa a partir da árvore. */
    if (arv != NULL) {
        *pre = arv->info;
        pre++;
        *pre = '\0';

        ArvPre(arv->esq, pre);
        FIM_DE_CADEIA(pre);

        ArvPre(arv->dir, pre);

    }

    return;

} /* ArvPre */

void ArvPos(ArvBin arv, char *pos)
{
    /* Produz a representação pós-fixa a partir da árvore. */

    if (arv != NULL) {
        ArvPos(arv->esq,pos);

        FIM_DE_CADEIA(pos);
        ArvPos(arv->dir,pos);

        FIM_DE_CADEIA(pos);
        *pos = arv->info;
        pos++;
    }
    *pos = '\0';

    return;

} /* ArvPos */

void LiberaArv(ArvBin arv)
{
    /* Libera o espaço ocupado pela árvore. */

    if(arv != NULL) {
        LiberaArv(arv->esq);
        LiberaArv(arv->dir);

        FREE(arv);
    }

    return;

} /* LiberaArv */
