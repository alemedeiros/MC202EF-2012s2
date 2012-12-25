/*
 * principal.c - Programa teste para o módulo multPoli.
 */

#include <stdio.h>
#include "multPoli.h" 
#include "balloc.h"

void bprint(char *who, int where, void *ptr) {
/* Função auxiliar que imprime dados sobre bloco de memória não
   liberado. */
  printf("Arquivo: %s, linha: %d\n",who,where);
} /* bprint */


void ImprimeComentario() {
  char c;
  int res;
    do { 
      res = scanf("%c", &c); 
      if (res!=EOF)
	printf("%c",c);
    } while ((res!=EOF) && (c!='\n'));
}

int Indice(char c) {
  if (c >= 'A' && c <= 'Z')
    return c - 'A';
  else
    if (c >= 'a' && c <= 'z')
      return c - 'a';
    else
      return -1;
}


int main() {
  /* Base de polinômios */
#define TAM_BASE 10
  Polinomio base[TAM_BASE];

  char acao;
  char a, b, c;
  int indA, indB, indC;
  int i, expX, expY, expZ;
  int exps[3];
  float coef;
  Polinomio aux, aux2;
  Boolean fim = false;
    
  /* Inicializa base de polinômios */
  for (i = 0; i < TAM_BASE; i++)
    base[i] = NULL;

  do { 
    scanf("%c", &acao);
    printf("Ação: %c", acao);
    switch (acao)  { 
      
    case '#':
      ImprimeComentario();
      break;
      
    case 'a': /* Adiciona termos a um polinômio da base */
    case 'A':
      scanf(" %c %f %d %d %d",&a, &coef, &expX, &expY, &expZ);
      printf(" %c %.1f %d %d %d",a, coef, expX, expY, expZ);
      ImprimeComentario();
      if ((indA = Indice(a)) == -1) {
	printf("Nome de polinômio inválido.\n");
	break;
      }
      aux = base[indA];
      exps[0] = expZ; 
      exps[1] = expY; 
      exps[2] = expX;
      aux2 = CriaTermo(coef, exps, 3);
      base[indA] = SomaPolinomios(aux, aux2);      
      LiberaPolinomio(aux);
      LiberaPolinomio(aux2);
      break;
            
    case 'c': /* Copia um polinômio da base */
    case 'C':
      scanf(" %c %c",&a,&b);
      printf(" %c %c",a,b);
      ImprimeComentario();
      if ((indA = Indice(a)) == -1 ||
	  (indB = Indice(b)) == -1) {
	printf("Nome de polinômio inválido.\n");
	break;
      }
      aux = CopiaPolinomio(base[indB]);

      if (base[indB] != NULL)
	LiberaPolinomio(base[indA]);
      base[indA] = aux;
      break;

    case 'l': /* Libera um polinômio da base */
    case 'L':
      scanf(" %c",&a);
      printf(" %c",a);
      ImprimeComentario();
      if ((indA = Indice(a)) == -1) {
	printf("Nome de polinômio inválido.\n");
	break;
      }
      LiberaPolinomio(base[indA]);
      base[indA] = NULL;
      break;
                        
    case 'z':  /* Atribui valor zero a um polinômio da base */
    case 'Z':
      scanf(" %c",&a);
      printf(" %c",a);
      ImprimeComentario();
      if ((indA = Indice(a)) == -1) {
	printf("Nome de polinômio inválido.\n");
	break;
      }
      base[indA] = NULL;
      break;
                        
    case 'i':  /* Imprime um polinômio da base */
    case 'I':
      scanf(" %c",&a);
      printf(" %c",a);
      ImprimeComentario();
      printf("%c = ", a);
      if ((indA = Indice(a)) == -1) {
	printf("Nome de polinômio inválido.\n");
	break;
      }
      ImprimePolinomio(base[indA],"zyx");
      break;
            
    case 's': /* Soma dois polinômios da base */
    case 'S':
      scanf(" %c %c %c",&a,&b,&c);
      printf(" %c %c %c",a,b,c);
      ImprimeComentario();
      if ((indA = Indice(a)) == -1 ||
	  (indB = Indice(b)) == -1 ||
	  (indC = Indice(c)) == -1) {
	printf("Nome de polinômio inválido.\n");
	break;
      }
      aux = SomaPolinomios(base[indB],base[indC]);
      if (base[indA] != NULL)
	LiberaPolinomio(base[indA]);
      base[indA] = aux;
      break;
            
    case 'm': /* Multiplica dois polinômios da base */
    case 'M':
      scanf(" %c %c %c",&a,&b,&c);
      printf(" %c %c %c",a,b,c);
      ImprimeComentario();
      if ((indA = Indice(a)) == -1 ||
	  (indB = Indice(b)) == -1 ||
	  (indC = Indice(c)) == -1) {
	printf("Nome de polinômio inválido.\n");
	break;
      }
      aux = MultPolinomios(base[indB],base[indC]);
      if (base[indA] != NULL)
	LiberaPolinomio(base[indA]);
      base[indA] = aux;
      break;

    case 'h':
    case 'H':
      ImprimeComentario();
      printf("\n");
      printf("#                      : comentário\n");
      printf("a P coef expX expY expZ: P <- P + coef x^expX y^expY z^expZ\n");
      printf("c P Q                  : P <- Q\n");
      printf("l P                    : libera polinômio P\n");
      printf("i P                    : imprime polinômio P\n");
      printf("s P Q R                : P <- Q + R\n");
      printf("m P Q R                : P <- Q * R\n");
      printf("z P                    : P <- 0\n");
      printf("x                      : término\n"); 
      printf("q                      : término\n"); 
      printf("h                      : imprime resumo\n");
      fim = true;
      break;
            
    case 'x':
    case 'X':
    case 'q':
    case 'Q':
      ImprimeComentario();
      fim = true;
      break;
      
    }  /* switch */
    
  } while (!fim);
      

  bapply(bprint);
   
   printf("Processamento terminado\n");
   
   return 0;
  
} /* main */


