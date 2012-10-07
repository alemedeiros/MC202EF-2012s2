/*
 * principal.c - Arquivo de teste para o m�dulo de transforma��o de
 * express�es em nota��o infixa para �rvores bin�rias e represnta��es
 * pr�-fixa e p�s-fixa.
 */
#include <stdio.h>
#include <string.h>
#include "balloc.h"
#include "analisador.h"


/* Fun��o auxiliar que imprime dados sobre bloco de mem�ria n�o
   liberado. */
void bprint(char *who, int where, void *ptr) {

  printf("Arquivo: %s, linha: %d\n",who,where);
  
} /* bprint */


/* Mensagens de erro para os c�digos previstos em analisador.h */
char *msg_erro[] = {
  "Express�o v�lida.",
  "Operando esperado nesta posi��o.",
  "Operador esperado nesta posi��o.",  
  "Fecha par�ntese esperado nesta posi��o.",
  "Caractere inv�lido nesta posi��o.",
  "Cadeia de brancos."
};


void mostraErro(Erro erro) {
/* Imprime uma mensagem de erro. N�o encerra a execu��o do programa.    */
  int i;
  printf("Erro:   ");  /* Mostra posi��o do primeiro erro encontrado */
  for (i = 0; i < erro.posicao; i++)
    printf(" ");
  printf("^\n"); 
  printf("        %s\n\n", msg_erro[erro.codigoErro]);
} /* mostraErro */


int leExpr(char *in) {
/* Tenta ler uma express�o da entrada, desprezando linhas maiores do */
/* que TAM_MAX_EXPR, linhas vazias e linhas de coment�rio. Retorna o */
/* n�mero de caracteres lidos.                                       */
  int m;
  char ch;
  
  for (;;) {
    if (fgets(in,TAM_MAX_EXPR+2,stdin)==NULL) /* fim de arquivo */
      return 0;
    m = strlen(in);
    if (in[0]=='#')  { /* coment�rio */
      printf("%s",in);
    } else if (in[m-1]!='\n') { /* '\n' n�o coube */
      printf("Infixa: %s",in);
      do {
	ch=getc(stdin);
        putc(ch,stdout);
      } while (ch!='\n');    /* resto da entrada */
      printf("Erro:   Cadeia de entrada muito longa.\n\n");
    } else if (m>1) {        /* cadeia n�o vazia */
      in[m-1] = '\0';             /* elimina '\n' */
      return m-1;
    }
  }
  
} /* LeExpr */


void despejaArv(ArvBin a) {
  /* Despeja uma �rvore em nota��o infixa -- pode ser usada para
     depura��o. */
  if (a!=NULL) {
    despejaArv(a->esq);
    printf("%c",a->info);
    despejaArv(a->dir);
  }
}


int main() {
  char in[TAM_MAX_EXPR+2], res[TAM_MAX_EXPR+1];
  Erro erro;
  ArvBin arv;

  while (leExpr(in)>0) {
    erro = InArv(in,&arv);
    printf("Infixa: %s\n", in);
    if (erro.codigoErro == EXPR_VALIDA) {
      ArvPre(arv,res);
      printf("Prefixa: %s\n",res);
      ArvPos(arv,res);
      printf("Posfixa: %s\n\n",res);
    }
    else
      mostraErro(erro); 
    printf("\n");
    LiberaArv(arv);
  }
        
 /* Verifica se foram liberados todos os blocos alocados */
  bapply(bprint);

        
  printf("Processamento terminado\n");
  
  return 0;
  
} /* main */


