/* Programa: pilha.c (Calculadora de polin�mios)       */
/* Autor: Alexandre N. de Medeiros        RA115966     */
/* Disciplina: MC602                      Turma E      */
/* Data: 29/ago/2011                                   */
/* Revisado: 16/set/2012                               */

/* Implementa��o de pilhas. Os elementos empilhados s�o do tipo void*.     */

#include <stdlib.h>
#include <stdio.h>
#include "pilha.h"

/* Mensagens de erro para este m�dulo.                                     */
#define MSG_ERRO_PILHA_CHEIA "n�mero m�ximo de elementos na pilha excedido."
#define MSG_ERRO_PILHA_VAZIA "tentativa de desempilhar elemento de pilha vazia."

#define IMPRIME_ERRO(msg)  {printf("%s\n",msg); exit(0); }


void CriaPilha (Pilha* p)
{
  /* Inicializa uma pilha.                                                   */
  
  p->topo = -1;
  
  return;
} /* CriaPilha */

Boolean PilhaVazia (Pilha* p)
{
  /* Verifica se a pilha est� vazia.                                         */
  
  if (p->topo == -1)
    return true;
  else
    return false;
  
} /* PilhaVazia */

void Empilha (Pilha* p, void *elem)
{
  /* Empilha um elemento na pilha.                                           */
  if (p->topo + 1 == MAX_ELEM_PILHA)
    IMPRIME_ERRO(MSG_ERRO_PILHA_CHEIA);
  
  p->topo += 1;
  p->vetor[p->topo] = elem;
  
  return;

} /* Empilha */

void* Desempilha (Pilha* p)
{
  /* Desempilha um elemento da pilha.                                        */ 
  if (PilhaVazia(p))
    IMPRIME_ERRO(MSG_ERRO_PILHA_VAZIA);
  
  p->topo -= 1;
  
  return p->vetor[p->topo + 1];

} /* Desempilha */
