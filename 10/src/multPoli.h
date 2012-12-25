/*
 * multPoli.h - Arquivo de interface para a implementa��o de
 *              polin�mios em m�ltiplas vari�veis.
 */

#ifndef MULTI_POLI
#define MULTI_POLI

typedef enum {false, true} Boolean;

typedef void * Polinomio;


Polinomio CriaPolinomioNulo();
/* Devolve um novo polin�mio identicamente nulo.                          */

Boolean PolinomioNulo(Polinomio p);
/* Verifica se o polin�mio 'p' � identicamente nulo.                      */

Polinomio CriaTermo(float coef, int exps[], int numVars);
/* Devolve um novo polin�mio formado por um �nico termo da forma 
   coef x1^exp1 x2^exp2 x3^exp3 ..., onde 'numVars' � o n�mero de
   vari�veis do polin�mio e � o tamanho do vetor de expoentes 'exps'.   */ 

void LiberaPolinomio(Polinomio p);
/* Libera toda a mem�ria din�mica ocupada por um polin�mio.               */

Polinomio CopiaPolinomio(Polinomio p);
  /* Devolve uma c�pia do polin�mio p, sem alter�-lo. */

Polinomio SomaPolinomios(Polinomio a, Polinomio b);
/* Devolve a soma dos polin�mios 'a' e 'b'. N�o altera os polin�mios      */
/* dados. Termos nulos n�o s�o inseridos no resultado.                    */

Polinomio MultPolinomios(Polinomio a, Polinomio b);
/* Devolve o produto dos polin�mios 'a' e 'b', sem alter�-los */

void ImprimePolinomio(Polinomio p, char *vars);
/* Imprime o polin�mio p em vari�veis vars. */

#endif
