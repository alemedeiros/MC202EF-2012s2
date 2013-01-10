/* Este arquivo é a interface para uma implementação simples das
   funções 'malloc' e 'free' de maneira compatível com as funções da
   biblioteca padrão 'malloc.h.
   
   O método de alocação é o de blocos conjugados ("buddy system")
   explicado na apostila do curso. Os blocos são alocados de um vetor
   global de bytes de tamanho TAM_MEM. Nesta implementação TAM_MEM tem
   que ser uma potência de 2, NUM_NIVEIS= log2(TAM_MEM).
   
   A função adicional 'avail' é usada para testar a implementação.
   
*/   

#ifndef _ALOCA_H
#define _ALOCA_H

#define TAM_MEM 1024*1024    /* tamanho total da memória disponível em bytes */
#define NUM_NIVEIS 20        /* log2(TAM_MEM) */

typedef enum {false, true} Boolean;

void *malloc(int tamanho);
/* Devolve um apontador para um bloco de memória com pelo menos
   'tamanho' bytes disponíveis, além das outras informações. */

void free(void *p);
/* Libera o bloco de memória apontado por 'p'. */

int avail(int k);
/* Devolve o número de blocos de tamanho '2^k' disponíveis - usado
   para testes. */

#endif /* _ALOCA_H */
