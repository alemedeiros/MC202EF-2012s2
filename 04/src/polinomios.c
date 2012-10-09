/* Programa: polinomios.c (Polin�mios)                 */
/* Autor: Alexandre N. de Medeiros        RA115966     */
/* Disciplina: MC202                      Turma E      */
/* Data: 10/ago/2011                                   */
/* Revisado: 16/set/2012                               */

/* Este m�dulo implementa opera��es sobre polin�mios em uma vari�vel.   */
/* Cada polin�mio � representado por uma lista ligada simples, com n�   */
/* cabe�a. Os n�s da lista representam os termos n�o nulos do polin�mio */
/* em ordem crescente dos seus expoentes. O n� cabe�a tem expoente '-1'.*/

#include "polinomios.h"
#include "balloc.h"
#include <stdio.h>

/*-----------------------  Fun��es auxiliares  ----------------------------*/

void InsereTermoAux(Polinomio p, int e, float c)
{
  /* Insere o termo '(e,c)' ap�s o n� apontado por 'p'.                  */

  Polinomio novo = MALLOC(sizeof(Termo));
  novo->expo = e;
  novo->coef = c;
  novo->prox = p->prox;
  p->prox = novo;

  return;

} /* InsereTermoAux */

/*---------------- Implementa��o das fun��es da interface --------------*/

void ImprimePolinomio(Polinomio p)
{
  /* Imprime, em ordem crescente dos expoentes, os termos do              */
  /* n�o nulos do 'p'. No caso do polin�mio identicamente nulo,           */
  /* imprime as palavras "Polin�mio nulo".                                */

  if (p==NULL) {
    printf("Polin�mio inv�lido\n");
    return;
  }

  if (p->prox==p) {
    printf("Polin�mio nulo\n");
    return;
  }

  p = p->prox;
  while (p->expo!=-1) {
    printf("(%2d,%5.1f) ",p->expo,p->coef);
    p = p->prox;
  }
  printf("\n");

} /* ImprimePolinomio */

Polinomio CriaPolinomioNulo()
{
  /* Devolve um novo polin�mio identicamente nulo.                        */

  /* Cria um n� cabe�a e retorna seu endere�o. */
  Polinomio novo = MALLOC(sizeof(Termo));
  novo->expo = -1;
  novo->prox = novo;

  return novo;

} /* CriaPolinomioNulo */

void LiberaPolinomio(Polinomio p)
{
  /* Libera toda a mem�ria din�mica ocupada por um polin�mio.             */

  Polinomio q = p->prox, aux;

  /* Libera n� por n� at� voltar ao n� cabe�a da lista. */
  while (q != p) {
    aux = q->prox;
    FREE(q);
    q = aux;
  }

  /* Libera o n� cabe�a */
  FREE(p);

  return;

} /* LiberaPolinomio */

Boolean PolinomioNulo(Polinomio p)
{
  /* Verifica se o polin�mio 'p' � identicamente nulo.                    */

  /* Se o n� cabe�a aponta pra si mesmo o Polin�mio � nulo. */
  if (p->prox == p)
    return true;
  else
    return false;

} /* PolinomioNulo */

void InsereTermo(Polinomio p, int e, float c)
{
  /* Insere no polinomio 'p' o termo '(e,c)', de maneira a manter os      */
  /* termos ordenados. Sup�e que n�o existe ainda em 'p' um termo com     */
  /* expoente 'e', e que 'c' n�o � zero.                                  */

  Polinomio atual = p, prox = p->prox;

  /* Caso encontrou a posi��o adequada OU chegou no final do polinomio
   * retorna a posi��o anterior.
   */
  while (prox->expo < e && prox != p) {
    atual = prox;
    prox = prox->prox;
  }

  InsereTermoAux(atual, e, c);

  return;

} /* InsereTermo */

Polinomio SomaPolinomios(Polinomio a, Polinomio b)
{
  /* Devolve a soma dos polin�mios 'a' e 'b'. N�o altera os polin�mios    */
  /* dados. Termos nulos n�o s�o inseridos no resultados.                 */

  Polinomio res, atualA = a->prox, atualB = b->prox, aux;

  res = CriaPolinomioNulo();
  aux = res;

  /* Como ambos polin�mios est�o ordenados, faz uma intercala��o
   * e caso encontra um termo de mesmo expoente em ambos, soma-os
   */
  while (atualA != a && atualB != b) {
    /* Termos de mesmo expoente em ambos polin�mios. */
    if (atualA->expo == atualB->expo) {
      if (atualA->coef + atualB->coef != 0) {
        InsereTermoAux(aux, atualA->expo, atualA->coef + atualB->coef);
        aux = aux->prox;
      }

      atualA = atualA->prox;
      atualB = atualB->prox;

    } else if (atualA->expo < atualB->expo) {
      /* Termo de expoente exclusivo do polin�mio 'a'. */
      InsereTermoAux(aux, atualA->expo, atualA->coef);
      aux = aux->prox;

      atualA = atualA->prox;
    } else if (atualA->expo > atualB->expo) {
      /* Termo de expoente exclusivo do polin�mio 'b'. */
      InsereTermoAux(aux, atualB->expo, atualB->coef);
      aux = aux->prox;

      atualB = atualB->prox;
    }

  }

  /* Insere, no novo polin�mio, os termos restantes do polin�mio de maior grau. */
  if (atualA == a) {
    while (atualB != b) {
      InsereTermoAux(aux, atualB->expo, atualB->coef);
      aux = aux->prox;

      atualB = atualB->prox;
    }
  } else {
    while (atualA != a) {
      InsereTermoAux(aux, atualA->expo, atualA->coef);
      aux = aux->prox;

      atualA = atualA->prox;
    }
  }

  return res;

} /* SomaPolinomios */

Polinomio SubPolinomios(Polinomio a, Polinomio b)
{
  /* Devolve a diferen�a entre o polin�mio 'a' e o polin�mio 'b'. N�o      */
  /* altera os polin�mios dados. Termos nulos n�o s�o inseridos no         */
  /* resultado.                                                            */

  Polinomio res, atualA = a->prox, atualB = b->prox, aux;

  res = CriaPolinomioNulo();
  aux = res;

  /* Como ambos polin�mios est�o ordenados, faz uma intercala��o
   * e caso encontra um termo de mesmo expoente em ambos, soma-os
   */
  while (atualA != a && atualB != b) {
    /* Termos de mesmo expoente em ambos polin�mios. */
    if (atualA->expo == atualB->expo) {
      if (atualA->coef - atualB->coef != 0) {
        InsereTermoAux(aux, atualA->expo, atualA->coef - atualB->coef);
        aux = aux->prox;
      }

      atualA = atualA->prox;
      atualB = atualB->prox;

    } else if (atualA->expo < atualB->expo) {
      /* Termo de expoente exclusivo do polin�mio 'a'. */
      InsereTermoAux(aux, atualA->expo, atualA->coef);
      aux = aux->prox;

      atualA = atualA->prox;
    } else if (atualA->expo > atualB->expo) {
      /* Termo de expoente exclusivo do polin�mio 'b'. */
      InsereTermoAux(aux, atualB->expo, -atualB->coef);
      aux = aux->prox;

      atualB = atualB->prox;
    }

  }

  /* Insere, no novo polin�mio, os termos restantes do polin�mio de maior grau. */
  if (atualA == a) {
    while (atualB != b) {
      InsereTermoAux(aux, atualB->expo, -atualB->coef);
      aux = aux->prox;

      atualB = atualB->prox;
    }
  } else {
    while (atualA != a) {
      InsereTermoAux(aux, atualA->expo, atualA->coef);
      aux = aux->prox;

      atualA = atualA->prox;
    }
  }

  return res;

} /* SubPolinomios */

Polinomio MultTermo(Polinomio p, int e, float c)
{
  /* Devolve o polin�mio 'p' multiplicado pelo termo '(e,c)'. Sup�e       */
  /* que 'c' n�o � nulo. N�o altera os polin�mio dado.                    */

  Polinomio
  res,                // Resultado da Multiplica��o
  atual = p->prox,    // N� atual do polinomio p
  aux;

  res = CriaPolinomioNulo();
  aux = res;
  /* Multiplica todos termos do polin�mio 'p' por um termo. */
  while (atual != p) {
    InsereTermoAux(aux, atual->expo + e, atual->coef * c);
    aux = aux->prox;
    atual = atual->prox;
  }

  return res;

} /* MultTermo */

Polinomio MultPolinomios(Polinomio a, Polinomio b)
{
  /* Devolve o produto dos polin�mios 'a' e 'b'. N�o altera os polin�mios */
  /* dados.                                                               */

  Polinomio
  aux1,               // Resultado parcial da multiplica��o por um termo
  aux2,               // Resultado parcial do resultado atual com 'aux1'
  atualB = b->prox,   // Termo atual do Polin�mio 'b'
  res;                // Resultado final


  res = CriaPolinomioNulo();

  /* Multiplica o polinomio 'a' pelos termos de 'b', usando um termo de
   * 'b' por vez, somando o resultado de cada multiplica��o.
   */
  while (atualB != b) {
    /* Multiplica 'atualB' termo pelo polin�mio 'a'. */
    aux1 = MultTermo(a, atualB->expo, atualB->coef);
    atualB = atualB->prox;

    /* Soma o resultado da multiplica��o com a soma parcial. */
    aux2 = SomaPolinomios(res, aux1);

    /* Libera os Polin�mios que n�o ser�o mais utilizados. */
    LiberaPolinomio(aux1);
    LiberaPolinomio(res);

    res = aux2;
  }

  return res;

} /* MultPolinomios */
