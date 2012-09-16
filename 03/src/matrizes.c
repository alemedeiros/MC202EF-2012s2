/* Programa: matrizes.c (Matrizes esparsas)            */
/* Autor: Alexandre N. de Medeiros        RA115966     */
/* Disciplina: MC602                      Turma E      */
/* Data: 24/ago/2011                                   */
/* Revisado: 16/set/2012                               */

/* Descri��o:                                          */
/* Modulo de Opera��es com Matrizes, representadas com */
/* listas ligadas.                                     */
/* Opera��es implementadas:                            */
/*    Cria��o de uma matriz nula                       */
/*    Soma de duas matrizes                            */
/*    Transposi��o de uma matriz                       */
/*    Produto de duas matrizes                         */
/*    Libera��o da memoria ocupada por uma matriz      */
/*    Inser��o de elementos numa matriz                */
/*    Imprime uma matriz                               */

/* Laborat�rio 03 - matrizes esparsas ligadas - implementa��o. */
/* Adapta��o do exerc�cio originalmente preparado por Jorge Stolfi */

/* Complete todos os trechos indicados. */

#include <stdio.h>
#include "matrizes.h"
#include "balloc.h"

void remove_elem(matriz *a, ap_elemento r);

void erro(char *msg)
{ 
  printf("\n*** %s\n", msg); 

  exit(1);

} /* erro */

void prox_linha(void)
{ 
  char c;

  do { 
    scanf("%c", &c);
  } while ((c != '\n') && (c != EOF));

  return;

} /* prox_linha */

void inicializa(matriz *a, int m, int n)
{
  ap_elemento r, t;
  int i;

  /* Erros de entradas invalidas */
  if ((m < 1) || (m > LCMAX)) { erro("inicializa: n�mero de linhas inv�lido"); }
  if ((n < 1) || (n > LCMAX)) { erro("inicializa: n�mero de colunas inv�lido"); }

  /* Cria a Matriz. */
  a->nlins = m;
  a->ncols = n;
  a->nelems = 0;
  a->clin = (ap_elemento *)MALLOC((m+1)*sizeof(ap_elemento));
  a->ccol = (ap_elemento *)MALLOC((n+1)*sizeof(ap_elemento));

  /* Cria a cabe�a das cabe�as "r". */
  r = (ap_elemento)MALLOC(sizeof(elemento));
  if (r == NULL) 
    erro("inicializa: mem�ria esgotada");

  r->lin = m;
  r->col = n;
  r->val = 0;
  r->esq = r; r->dir = r;
  r->ac = r; r->ab = r;
  a->clin[m] = r;
  a->ccol[n] = r;

  /* Cria cabe�as das linhas: */
  for (i = 0; i < m; i++) { 
    t = (ap_elemento)MALLOC(sizeof(elemento));
    if (t == NULL) { erro("inicializa: mem�ria esgotada"); }
    t->lin = i;
    t->col = n;
    t->val = 0;
    t->esq = t;
    t->dir = t;

    /* Insere logo acima da super-cabe�a: */
    t->ac = r->ac; 
    t->ab = r;
    t->ab->ac = t;
    t->ac->ab = t;
    a->clin[i] = t;
  }

  /* Cria cabe�as das colunas: */
  for (i = 0; i < n; i++) { 
    t = (ap_elemento)MALLOC(sizeof(elemento));
    if (t == NULL)
      erro("inicializa: mem�ria esgotada");

    t->lin = m;
    t->col = i;
    t->val = 0;
    t->ab = t; 
    t->ac = t;

    /* Insere a esquerda da super-cabe�a: */
    t->esq = r->esq; 
    t->dir = r;
    t->dir->esq = t;
    t->esq->dir = t;
    a->ccol[i] = t;
  }

  return;

} /* inicializa */

void libera(matriz *a) 
/* Libera toda a mem�ria din�mica ocupada por uma matriz */
{
  int i;
  ap_elemento c, p1, p2;

  /* Libera os Elementos e os n�s cabe�a da matriz */
  for (i = 0; i <= a->nlins; i++) {
    /* Para cada linha remove todos os elementos da mesma e em seguida remove o
     * n� cabe�a
     */
    c = a->clin[i];
    p1 = c->dir;

    while (p1 != c) { 
      p2 = p1->dir;
      remove_elem(a,p1);
      p1 = p2;
    }

    FREE(c);
  }

  /* Libera os vetores de endere�os e a matriz */
  FREE(a->clin);
  FREE(a->ccol);
  FREE(a);

  return;

} /* libera */

void encontra(matriz *a, int i, int j, ap_elemento *ppl, ap_elemento *ppc)
/* Fun��o auxiliar: se o elemento "a[i,j]" existe,
 * devolve seu endere�o em "*ppl" e "*ppc".  Caso contr�rio,
 * devolve nessas vari�veis os endere�os dos seus sucessores
 * imediatos na linha e coluna (possivelmente as respectivas
 * cabe�as).
 */
{
  ap_elemento pl, pc;

  if ((i < 0) || (i >= a->nlins)) 
    erro("encontra: linha inv�lida");
  if ((j < 0) || (j >= a->ncols)) 
    erro("encontra: coluna inv�lida");

  /* Procura elemento "pl" na linha "i": */
  pl = a->clin[i]; 
  pl = pl->dir;
  
  while (pl->col < j) { pl = pl->dir; }

  if (pl->col == j)
    pc = pl;
  else { 
    /* Procura elemento "pc" na coluna "j": */
    pc = a->ccol[j];
    pc = pc->ab;
    while (pc->lin < i) { pc =  pc->ab; }

    /* Consist�ncia: */
    if (pc == pl) { erro("encontra: apontadores pirados"); }
  }

  if ((pl->lin != i) || (pl->col < j)) { erro("encontra: pl inconsistente"); }
  if ((pc->col != j) || (pc->lin < i)) { erro("encontra: pc inconsistente"); }
  (*ppl) = pl; (*ppc) = pc;

  return;

} /* encontra */

float valor(matriz *a, int i, int j)
{
  ap_elemento pl, pc;

  encontra(a, i, j, &pl, &pc); 

  if (pl != pc) { 
    return 0;
  }
  else {
    return pl->val;
  }

} /* valor */

void remove_elem(matriz *a, ap_elemento r)
/* Fun��o auxiliar: elimina um elemento "r" da matriz "a". */
{
  /* Remove o elemento da lista da coluna */
  r->ac->ab = r->ab;
  r->ab->ac = r->ac;

  /* Remove o elemento da lista da linha */
  r->esq->dir = r->dir;
  r->dir->esq = r->esq;

  /* Libera o elemento e decresce o valor de elementos n�o nulos da matriz */
  FREE(r);
  a->nelems--;

  return;

} /* remove_elem */
 
void insere_elem(matriz *a, int i, int j, float v, ap_elemento pl, ap_elemento pc) 
/* Fun��o auxiliar: insere um elemento de valor "v" e �ndices "[i,j]",
  dadas as posi��es dos sucessores do elemento "a[i,j]" na linha e 
  coluna, respectivamente (possivelmente cabe�as).  Sup�e que o 
  elemento n�o est� na matriz, e que "v != 0". */
{
  ap_elemento r;

  if (v == 0) { erro("insere: elemento nulo"); }
  if (pl->col < j) { erro("insere: pl inconsistente"); }
  if (pc->lin < i) { erro("insere: pc inconsistente"); }

  r = (ap_elemento)MALLOC(sizeof(elemento));
  r->lin = i;
  r->col = j;
  r->val = v;

  /* Insere o elemento nas listas da linha e da coluna: */
  /* Insere na Linha */
  pl->esq->dir = r;
  r->esq = pl->esq;
  pl->esq = r;
  r->dir = pl;

  /* Insere na Coluna */
  pc->ac->ab = r;
  r->ac = pc->ac;
  pc->ac = r;
  r->ab = pc;

  a->nelems++;

  return;

} /* insere_elem */

void atribui(matriz *a, int i, int j, float v)
{
  ap_elemento pl, pc;
  encontra(a, i, j, &pl, &pc); 

  if (pl != pc) {
    /* Elemento n�o existe; se "v" n�o � nulo, precisa encaixar: */
    if (v != 0.0)
      insere_elem(a, i, j, v, pl, pc);

  }
  else {
    /* Elemento existe; se "v" � nulo, precisa remover, sen�o alterar: */
    if (v != 0.0)
      pl->val = v;
    else
      remove_elem(a, pl);
  }

  return;

} /* atribui */

void le_matriz(matriz *a)
{ 
  int m, n, d;
  int i, j, k; float v;
  int ip, jp; /* �ndices do elemento anterior. */
  int ko;

  scanf("%d %d %d", &m, &n, &d);
  prox_linha();
  inicializa(a, m, n);

  ip = -1; jp = n-1;

  for (k = 0; k < d; k++) {
    scanf("%d %d %f", &i, &j, &v);
    prox_linha();

    if (v != 0)
      insere_elem(a, i, j, v, a->clin[i], a->ccol[j]);

  }

  return;

} /* le_matriz */

void imprime_matriz(matriz *a)
{
  int i;

  printf("%d %d %d\n", a->nlins, a->ncols, a->nelems);

  for (i = 0; i < a->nlins; i++) {
    elemento *p = a->clin[i]->dir;

    while (p->col < a->ncols) {
      printf("  %2d %2d %8.2f\n", p->lin, p->col, p->val);
      p = p->dir;
    }
  }

  return;

} /* imprime_matriz */
 
void transpoe(matriz *a, matriz *t)
{ 
  int i;
  ap_elemento elem_a;
  inicializa(t, a->ncols, a->nlins);

  /* Percorre coluna por coluna da matriz a e insere os elementos 'aij' em 't'
   * como 'aji'
   */
  for (i = 0; i < a->ncols; i++) {
    elem_a = a->ccol[i]->ab;

    while (elem_a != a->ccol[i]) {
      insere_elem(t, elem_a->col, elem_a->lin, elem_a->val,
                  t->clin[elem_a->col], t->ccol[elem_a->lin]);

      elem_a = elem_a->ab;
    }
  }

  return;

} /* transpoe */

void soma(matriz *a, matriz *b, matriz *s)
{
  int i;
  ap_elemento elem_a, elem_b;

  /* Verifica se possuem mesmas dimens�es: */
  if ((a->nlins != b->nlins) || (a->ncols != b->ncols))
    erro("soma: matrizes com tamanhos diferentes");

  /* Inicializa matriz 's' com mesmas dimensoes de 'a' e 'b': */
  inicializa(s, a->nlins, a->ncols);

  for(i = 0; i < a->ncols; i++) {
    elem_a = a->ccol[i]->ab;
    elem_b = b->ccol[i]->ab;

    /* Seguindo o paradigma de intercala��o soma coluna por coluna das matrizes
     * 'a' e 'b'.
     */
    while (elem_a != a->ccol[i] || elem_b != b->ccol[i]) {
      if (elem_a->lin > elem_b->lin) {
        insere_elem(s, elem_b->lin, i, elem_b->val, s->clin[elem_b->lin],
                    s->ccol[i]);

        elem_b = elem_b->ab;

      }
      else if (elem_a->lin < elem_b->lin) {
        insere_elem(s, elem_a->lin, i, elem_a->val, s->clin[elem_a->lin],
                    s->ccol[i]);

        elem_a = elem_a->ab;

      }
      else if (elem_a->lin == elem_b->lin) {
        if (elem_a->val + elem_b->val != 0)
          insere_elem(s, elem_a->lin, i, elem_a->val + elem_b->val,
                      s->clin[elem_a->lin], s->ccol[i]);

        elem_a = elem_a->ab;
        elem_b = elem_b->ab;
      }

    }

  }

  return;

} /* soma */

void multiplica(matriz *a, matriz *b, matriz *p) 
{
  int i, j;
  float val;
  ap_elemento elem_a, elem_b;

  if ((a->ncols) != (b->nlins)) { erro("multiplica: tamanhos invalidos"); }
  inicializa(p, a->nlins, b->ncols);

  /* Para aumentar a eficiencia, caso pelo menos uma das matrizes seja nula, o
   * resultado ser� nulo
   */
  if(a->nelems == 0 || b->nelems == 0)
    return;

  /* Percorre a linha da matriz 'a' e a coluna da matriz 'b', fazendo um
   * somat�rio do produto dos elementos 'aik' e 'bkj', guardando o resultado
   * em 'pij'
   */
  for(i = 0; i < a->nlins; i++) {
    for(j = 0; j < b->ncols; j++) {
      elem_a = a->clin[i]->dir;
      elem_b = b->ccol[j]->ab;
      val = 0;

      while (elem_b != b->ccol[j] && elem_a != a->clin[i]) {
        if(elem_a->col == elem_b->lin) {
          /* Ambos elementos s�o n�o-nulos, portanto efetua-se o calculo
           * necess�rio e anda em ambas matrizes.
           */
          val += elem_b->val * elem_a->val;

          elem_a = elem_a->dir;
          elem_b = elem_b->ab;
        } else if(elem_a->col > elem_b->lin) {
          /* O elemento de 'a' que multiplicaria o elemento de b � nulo, o
           * produto resultante ser� 0, omite-se esse calculo e anda apenas na
           * coluna do 'b'.
           */
          elem_b = elem_b->ab;
        } else if(elem_a->col < elem_b->lin) {
          /* O elemento de 'b' que multiplicaria o elemento de a � nulo, o
           * produto resultante ser� 0, omite-se esse calculo e anda apenas na
           * linha do 'a'.
           */
          elem_a = elem_a->dir;
        }
      }

      if (val != 0)
        insere_elem(p, i, j, val, p->clin[i], p->ccol[j]);
    }
  }

  return;

} /* multiplica */
