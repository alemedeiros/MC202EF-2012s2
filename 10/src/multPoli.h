/*
 * multPoli.h - Arquivo de interface para a implementação de
 *              polinômios em múltiplas variáveis.
 */

#ifndef MULTI_POLI
#define MULTI_POLI

typedef enum {false, true} Boolean;

typedef void * Polinomio;


Polinomio CriaPolinomioNulo();
/* Devolve um novo polinômio identicamente nulo.                          */

Boolean PolinomioNulo(Polinomio p);
/* Verifica se o polinômio 'p' é identicamente nulo.                      */

Polinomio CriaTermo(float coef, int exps[], int numVars);
/* Devolve um novo polinômio formado por um único termo da forma 
   coef x1^exp1 x2^exp2 x3^exp3 ..., onde 'numVars' é o número de
   variáveis do polinômio e é o tamanho do vetor de expoentes 'exps'.   */ 

void LiberaPolinomio(Polinomio p);
/* Libera toda a memória dinâmica ocupada por um polinômio.               */

Polinomio CopiaPolinomio(Polinomio p);
  /* Devolve uma cópia do polinômio p, sem alterá-lo. */

Polinomio SomaPolinomios(Polinomio a, Polinomio b);
/* Devolve a soma dos polinômios 'a' e 'b'. Não altera os polinômios      */
/* dados. Termos nulos não são inseridos no resultado.                    */

Polinomio MultPolinomios(Polinomio a, Polinomio b);
/* Devolve o produto dos polinômios 'a' e 'b', sem alterá-los */

void ImprimePolinomio(Polinomio p, char *vars);
/* Imprime o polinômio p em variáveis vars. */

#endif
