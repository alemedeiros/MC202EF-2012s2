/* Programa: selas.c (Pontos de selas)                 */
/* Autor: Alexandre N. de Medeiros        RA115966     */
/* Disciplina: MC202                      Turma EF     */
/* Data: 02/ago/2012                                   */

#include <stdio.h>
#include <stdlib.h>

/* Constantes */
#define NMAX      20
#define TAMLINHA  100

/* Funções auxiliares */
void consomeLinha()
{
  /* Consome todos caracteres da linha atual na stdin */
  char c;

  while (((c = getchar()) != '\n') && (c != EOF));

  return;
} /* consomeLinha */

void entradaInvalida()
{
  /* Imprime mensagem de erro e termina execução */


  printf("Dados inválidos\n");
  exit(0);
} /* entradaInvalida */


int main()
{
  /* Variáveis */
  int max[20], min[20], i, j, info[20][20], n, aux;

  /* Leitura */
  aux = scanf("%d", &n);
  if (n < 1 || n > 20 || aux != 1)
    entradaInvalida();
  else
    consomeLinha();

  for (i = 0 ; i < n ; i++) {
    for (j = 0 ; j < n ; j++) {
      aux = scanf("%d", &info[i][j]);

      if (aux != 1)
        entradaInvalida();
    }
    consomeLinha();
  }

  /* Encontra mínimos e máximos da linha e coluna, respectivamente. */
  for (i = 0 ; i < n ; i++) {
    /* Inicializa vetor de mínimos e máximos */
    min[i] = info[i][0];
    max[i] = info[0][i];
    
    for (j = 0 ; j < n ; j++) {
      if (info[i][j] < min[i])
        min[i] = info[i][j];
      if (info[j][i] > max[i])
        max[i] = info[j][i];
    }
  }

  /* Procura pontos de sela */
  printf("Os pontos de sela da matriz são:\n\n");
  aux = 0;

  for (i = 0 ; i < n ; i++) {
    for (j = 0 ; j < n ; j++) {
      if (info[i][j] == min[i] && info[i][j] == max[j]) {
        printf("%4d%4d%4d\n", i, j, info[i][j]);
        aux++;
      }
    }
  }

  if (aux == 0)
    printf("    nenhum\n");
  
  return 0;
} /* main */
