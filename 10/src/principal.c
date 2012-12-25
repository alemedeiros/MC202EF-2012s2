/*
 * principal.c - Programa teste para o m�dulo multPoli.
 */

#include <stdio.h>
#include "multPoli.h" 
#include "balloc.h"

void bprint(char *who, int where, void *ptr) {
/* Fun��o auxiliar que imprime dados sobre bloco de mem�ria n�o
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
  /* Base de polin�mios */
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
    
  /* Inicializa base de polin�mios */
  for (i = 0; i < TAM_BASE; i++)
    base[i] = NULL;

  do { 
    scanf("%c", &acao);
    printf("A��o: %c", acao);
    switch (acao)  { 
      
    case '#':
      ImprimeComentario();
      break;
      
    case 'a': /* Adiciona termos a um polin�mio da base */
    case 'A':
      scanf(" %c %f %d %d %d",&a, &coef, &expX, &expY, &expZ);
      printf(" %c %.1f %d %d %d",a, coef, expX, expY, expZ);
      ImprimeComentario();
      if ((indA = Indice(a)) == -1) {
	printf("Nome de polin�mio inv�lido.\n");
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
            
    case 'c': /* Copia um polin�mio da base */
    case 'C':
      scanf(" %c %c",&a,&b);
      printf(" %c %c",a,b);
      ImprimeComentario();
      if ((indA = Indice(a)) == -1 ||
	  (indB = Indice(b)) == -1) {
	printf("Nome de polin�mio inv�lido.\n");
	break;
      }
      aux = CopiaPolinomio(base[indB]);

      if (base[indB] != NULL)
	LiberaPolinomio(base[indA]);
      base[indA] = aux;
      break;

    case 'l': /* Libera um polin�mio da base */
    case 'L':
      scanf(" %c",&a);
      printf(" %c",a);
      ImprimeComentario();
      if ((indA = Indice(a)) == -1) {
	printf("Nome de polin�mio inv�lido.\n");
	break;
      }
      LiberaPolinomio(base[indA]);
      base[indA] = NULL;
      break;
                        
    case 'z':  /* Atribui valor zero a um polin�mio da base */
    case 'Z':
      scanf(" %c",&a);
      printf(" %c",a);
      ImprimeComentario();
      if ((indA = Indice(a)) == -1) {
	printf("Nome de polin�mio inv�lido.\n");
	break;
      }
      base[indA] = NULL;
      break;
                        
    case 'i':  /* Imprime um polin�mio da base */
    case 'I':
      scanf(" %c",&a);
      printf(" %c",a);
      ImprimeComentario();
      printf("%c = ", a);
      if ((indA = Indice(a)) == -1) {
	printf("Nome de polin�mio inv�lido.\n");
	break;
      }
      ImprimePolinomio(base[indA],"zyx");
      break;
            
    case 's': /* Soma dois polin�mios da base */
    case 'S':
      scanf(" %c %c %c",&a,&b,&c);
      printf(" %c %c %c",a,b,c);
      ImprimeComentario();
      if ((indA = Indice(a)) == -1 ||
	  (indB = Indice(b)) == -1 ||
	  (indC = Indice(c)) == -1) {
	printf("Nome de polin�mio inv�lido.\n");
	break;
      }
      aux = SomaPolinomios(base[indB],base[indC]);
      if (base[indA] != NULL)
	LiberaPolinomio(base[indA]);
      base[indA] = aux;
      break;
            
    case 'm': /* Multiplica dois polin�mios da base */
    case 'M':
      scanf(" %c %c %c",&a,&b,&c);
      printf(" %c %c %c",a,b,c);
      ImprimeComentario();
      if ((indA = Indice(a)) == -1 ||
	  (indB = Indice(b)) == -1 ||
	  (indC = Indice(c)) == -1) {
	printf("Nome de polin�mio inv�lido.\n");
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
      printf("#                      : coment�rio\n");
      printf("a P coef expX expY expZ: P <- P + coef x^expX y^expY z^expZ\n");
      printf("c P Q                  : P <- Q\n");
      printf("l P                    : libera polin�mio P\n");
      printf("i P                    : imprime polin�mio P\n");
      printf("s P Q R                : P <- Q + R\n");
      printf("m P Q R                : P <- Q * R\n");
      printf("z P                    : P <- 0\n");
      printf("x                      : t�rmino\n"); 
      printf("q                      : t�rmino\n"); 
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


