/* Teste do pacote 'aloca'. 

   Comandos:
   
   m k n: aloca 'n' bytes e atribui o apontador à variável aponts[k]
   f k  : libera o bloco apontado por aponts[k]
   a k  : imprime o número de blocos disponíveis de tamanho 2^k
   t    : imprime a tabela de todos os blocos disponíveis
   
*/

#include <stdio.h>
#include <limits.h>    /* usa INT_MAX */
#include "aloca.h"

/* Número de variáveis apontadoras */
#define NUM_APONTADORES 4

/* Dados para formatação de linhas impressas */
#define VALORES_POR_LINHA 10
#define NUM_LINHAS  (NUM_NIVEIS/VALORES_POR_LINHA)

void ProxLinha() {
    char c;
    do { scanf("%c", &c); } while ((c != '\n') && (c != EOF));
} /* prox_linha */


Boolean Verif(int k, int limite) {
  /* Verifica o valor do argumento */
  if ((k<0)||(k>limite)) {
    printf("Argumento inválido\n");
    return false;
  }
  return true;
} /* Verif */
    

int main() {

  char acao;
  int tamanho,i,k,j;
  void *aponts[NUM_APONTADORES];
  
  for (i=0; i<NUM_APONTADORES; i++)
    aponts[i]=NULL;

  while (true) {
    scanf("%c", &acao);
    printf("%c: ",acao);
    switch (acao) {
      case 'm':                        
	scanf("%d %d",&k,&tamanho);
        ProxLinha();
	printf("%d  %d\n",k,tamanho);
        if (Verif(k,NUM_APONTADORES)&&Verif(tamanho,INT_MAX)) {
	  aponts[k] = malloc(tamanho);
          if (aponts[k]==NULL)
	    printf("Não há memória suficiente\n");
	}
        break;
      case 'f':
	scanf("%d",&k);
	ProxLinha();
        printf("%d\n",k);
        if (Verif(k,NUM_APONTADORES))
	  free(aponts[k]);
        break;
      case 'a':
	scanf("%d",&k);
	ProxLinha();
        printf("%d\n",k);
        if (Verif(k,NUM_NIVEIS))
	  printf("%d bloco(s) disponível(is)\n",avail(k));
        break;
      case 't':
	ProxLinha();
        printf("\n");
	printf("Blocos disponíveis:\n");
        for (k=0; k<=NUM_NIVEIS; k+=VALORES_POR_LINHA) {
	  for (j=0; ((j<VALORES_POR_LINHA)&&((k+j)<=NUM_NIVEIS)); j++)
	    printf("%3d ",k+j);
          printf("\n");
	  for (j=0; ((j<VALORES_POR_LINHA)&&((k+j)<=NUM_NIVEIS)); j++)
	    printf("%3d ",avail(k+j));
          printf("\n");
	}
        break;
      case 'x':
      case 'q':
	printf(" Fim da execução.\n");
	return 0;
	break;
      case '#': 
	{ int c;
	  do 
	    { c = getchar(); putchar(c); } 
	  while ((c != '\n') && (c != EOF));
	}
	break;  
      default:
	ProxLinha();
	printf("Ação inválida\n");
    } /* switch */
  } /* while */
  
  return 0;
  
  } /* main */

        
