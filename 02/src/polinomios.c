/* Programa: polinomios.c (PolinÃÂ´mios)                 */
/* Autor: Alexandre N. de Medeiros        RA115966     */
/* Disciplina: MC202                      Turma E      */
/* Data: 10/ago/2011                                   */
/* Revisado: 03/ago/2012                               */

/* Este mÃÂ³dulo implementa operaÃÂ§ÃÂµes sobre polinÃÂ´mios em uma variÃÂ¡vel.   */
/* Cada polinÃÂ´mio ÃÂ© representado por uma lista ligada simples, com nÃÂ³   */
/* cabeÃÂ§a. Os nÃÂ³s da lista representam os termos nÃÂ£o nulos do polinÃÂ´mio */
/* em ordem crescente dos seus expoentes. O nÃÂ³ cabeÃÂ§a tem expoente '-1'.*/

#include "polinomios.h"
#include "balloc.h"
#include <stdio.h>

/*-----------------------  FunÃÂ§ÃÂµes auxiliares  ----------------------------*/

void InsereTermoAux(Polinomio p, int e, float c)
{
  /* Insere o termo '(e,c)' apÃÂ³s o nÃÂ³ apontado por 'p'.                  */

  Polinomio novo = MALLOC(sizeof(Termo));
  novo->expo = e;
  novo->coef = c;
  novo->prox = p->prox;
  p->prox = novo;

  return;

} /* InsereTermoAux */

/*---------------- ImplementaÃÂ§ÃÂ£o das funÃÂ§ÃÂµes da interface --------------*/


void ImprimePolinomio(Polinomio p)
{
  /* Imprime, em ordem crescente dos expoentes, os termos do              */
  /* nÃÂ£o nulos do 'p'. No caso do polinÃÂ´mio identicamente nulo,           */
  /* imprime as palavras "PolinÃÂ´mio nulo".                                */

  if (p==NULL) {
    printf("PolinÃÂ´mio invÃÂ¡lido\n");
    return;
  }

  if (p->prox==p) {
    printf("PolinÃÂ´mio nulo\n");
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
  /* Devolve um novo polinÃÂ´mio identicamente nulo.                        */

  /* Cria um nÃÂ³ cabeÃÂ§a e retorna seu endereÃÂ§o. */
  Polinomio novo = MALLOC(sizeof(Termo));
  novo->expo = -1;
  novo->prox = novo;

  return novo;

} /* CriaPolinomioNulo */



void LiberaPolinomio(Polinomio p)
{
  /* Libera toda a memÃÂ³ria dinÃÂ¢mica ocupada por um polinÃÂ´mio.             */

  Polinomio q = p->prox, aux;

  /* Libera nÃÂ³ por nÃÂ³ atÃÂ© voltar ao nÃÂ³ cabeÃÂ§a da lista. */
  while (q != p) {
    aux = q->prox;
    FREE(q);
    q = aux;
  }

  /* Libera o nÃÂ³ cabeÃÂ§a */
  FREE(p);

  return;

} /* LiberaPolinomio */

Boolean PolinomioNulo(Polinomio p)
{
  /* Verifica se o polinÃÂ´mio 'p' ÃÂ© identicamente nulo.                    */

  /* Se o nÃÂ³ cabeÃÂ§a aponta pra si mesmo o PolinÃÂ´mio ÃÂ© nulo. */
  if (p->prox == p)
    return true;
  else
    return false;

} /* PolinomioNulo */


void InsereTermo(Polinomio p, int e, float c)
{
  /* Insere no polinomio 'p' o termo '(e,c)', de maneira a manter os      */
  /* termos ordenados. SupÃÂµe que nÃÂ£o existe ainda em 'p' um termo com     */
  /* expoente 'e', e que 'c' nÃÂ£o ÃÂ© zero.                                  */

  Polinomio atual = p, prox = p->prox;

  /* Caso encontrou a posiÃÂ§ÃÂ£o adequada OU chegou no final do polinomio
   * retorna a posiÃÂ§ÃÂ£o anterior.
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
  /* Devolve a soma dos polinÃÂ´mios 'a' e 'b'. NÃÂ£o altera os polinÃÂ´mios    */
  /* dados. Termos nulos nÃÂ£o sÃÂ£o inseridos no resultados.                 */

  Polinomio res, atualA = a->prox, atualB = b->prox, aux;

  res = CriaPolinomioNulo();
  aux = res;

  /* Como ambos polinÃÂ´mios estÃÂ£o ordenados, faz uma intercalaÃÂ§ÃÂ£o
   * e caso encontra um termo de mesmo expoente em ambos, soma-os
   */
  while (atualA != a && atualB != b) {
    /* Termos de mesmo expoente em ambos polinÃÂ´mios. */
    if (atualA->expo == atualB->expo) {
      if (atualA->coef + atualB->coef != 0) {
        InsereTermoAux(aux, atualA->expo, atualA->coef + atualB->coef);
        aux = aux->prox;
      }
      atualA = atualA->prox;
      atualB = atualB->prox;

    }
    else if (atualA->expo < atualB->expo) {
      /* Termo de expoente exclusivo do polinÃÂ´mio 'a'. */
      InsereTermoAux(aux, atualA->expo, atualA->coef);
      aux = aux->prox;

      atualA = atualA->prox;
    }
    else if (atualA->expo > atualB->expo) {
      /* Termo de expoente exclusivo do polinÃÂ´mio 'b'. */
      InsereTermoAux(aux, atualB->expo, atualB->coef);
      aux = aux->prox;

      atualB = atualB->prox;
    }

  }

  /* Insere, no novo polinÃÂ´mio, os termos restantes do polinÃÂ´mio de maior grau. */
  if (atualA == a) {
    while (atualB != b) {
      InsereTermoAux(aux, atualB->expo, atualB->coef);
      aux = aux->prox;

      atualB = atualB->prox;
    }
  }
  else {
    while (atualA != a) {
      InsereTermoAux(aux, atualA->expo, atualA->coef);
      aux = aux->prox;

      atualA = atualA->prox;
    }
  }

  return res;

} /* SomaPolinomios */

Polinomio MultTermo(Polinomio p, int e, float c)
{
  /* Devolve o polinÃÂ´mio 'p' multiplicado pelo termo '(e,c)'. SupÃÂµe       */
  /* que 'c' nÃÂ£o ÃÂ© nulo. NÃÂ£o altera os polinÃÂ´mio dado.                    */

  Polinomio
  res,                // Resultado da MultiplicaÃÂ§ÃÂ£o
  atual = p->prox,    // NÃÂ³ atual do polinomio p
  aux;

  res = CriaPolinomioNulo();
  aux = res;
  /* Multiplica todos termos do polinÃÂ´mio 'p' por um termo. */
  while (atual != p) {
    InsereTermoAux(aux, atual->expo + e, atual->coef * c);
    aux = aux->prox;
    atual = atual->prox;
  }

  return res;

} /* MultTermo */


Polinomio MultPolinomios(Polinomio a, Polinomio b)
{
  /* Devolve o produto dos polinÃÂ´mios 'a' e 'b'. NÃÂ£o altera os polinÃÂ´mios */
  /* dados.                                                               */

  Polinomio
  aux1,               // Resultado parcial da multiplicaÃÂ§ÃÂ£o por um termo
  aux2,               // Resultado parcial do resultado atual com 'aux1'
  atualB = b->prox,   // Termo atual do PolinÃÂ´mio 'b'
  res;                // Resultado final

  res = CriaPolinomioNulo();

  /* Multiplica o polinomio 'a' pelos termos de 'b', usando um termo de
   * 'b' por vez, somando o resultado de cada multiplicaÃÂ§ÃÂ£o.
   */
  while (atualB != b) {
    /* Multiplica 'atualB' termo pelo polinÃÂ´mio 'a'. */
    aux1 = MultTermo(a, atualB->expo, atualB->coef);
    atualB = atualB->prox;

    /* Soma o resultado da multiplicaÃÂ§ÃÂ£o com a soma parcial. */
    aux2 = SomaPolinomios(res, aux1);

    /* Libera os PolinÃÂ´mios que nÃÂ£o serÃÂ£o mais utilizados. */
    LiberaPolinomio(aux1);
    LiberaPolinomio(res);

    res = aux2;
  }

  return res;

} /* MultPolinomios */
