/* Este arquivo � a interface para uma implementa��o simples das
   fun��es 'malloc' e 'free' de maneira compat�vel com as fun��es da
   biblioteca padr�o 'malloc.h.
   
   O m�todo de aloca��o � o de blocos conjugados ("buddy system")
   explicado na apostila do curso. Os blocos s�o alocados de um vetor
   global de bytes de tamanho TAM_MEM. Nesta implementa��o TAM_MEM tem
   que ser uma pot�ncia de 2, NUM_NIVEIS= log2(TAM_MEM).
   
   A fun��o adicional 'avail' � usada para testar a implementa��o.
   
*/   

#ifndef _ALOCA_H
#define _ALOCA_H

#define TAM_MEM 1024*1024    /* tamanho total da mem�ria dispon�vel em bytes */
#define NUM_NIVEIS 20        /* log2(TAM_MEM) */

typedef enum {false, true} Boolean;

void *malloc(int tamanho);
/* Devolve um apontador para um bloco de mem�ria com pelo menos
   'tamanho' bytes dispon�veis, al�m das outras informa��es. */

void free(void *p);
/* Libera o bloco de mem�ria apontado por 'p'. */

int avail(int k);
/* Devolve o n�mero de blocos de tamanho '2^k' dispon�veis - usado
   para testes. */

#endif /* _ALOCA_H */
