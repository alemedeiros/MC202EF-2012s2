/* Este m�dulo � a interface para  opera��es sobre polin�mios em uma    */
/* vari�vel. Cada polin�mio � representado por uma lista ligada         */
/* simples, com n� cabe�a. Os n�s da lista representam os termos n�o    */
/* nulos do polin�mio em ordem crescente dos seus expoentes. O n�       */
/* cabe�a tem expoente '-1'.                                            */


typedef struct Termo {
  int    expo;
  float  coef;
  struct Termo *prox;
} Termo, *Polinomio;

typedef enum {false=0, true=1} Boolean;

void ImprimePolinomio(Polinomio p);
/* Imprime, em ordem crescente dos expoentes, os termos do              */
/* n�o nulos do 'p'. No caso do polin�mio identicamente nulo,           */
/* imprime as palavras "Polin�mio nulo".                                */

Polinomio CriaPolinomioNulo();
/* Devolve um novo polin�mio identicamente nulo.                        */

void LiberaPolinomio(Polinomio p);
/* Libera toda a mem�ria din�mica ocupada por um polin�mio.             */

Boolean PolinomioNulo(Polinomio p);
/* Verifica se o polin�mio 'p' � identicamente nulo.                    */

void InsereTermo(Polinomio p, int e, float c);
/* Insere no polinomio 'p' o termo '(e,c)', de maneira a manter os      */
/* termos ordenados. Sup�e que n�o existe ainda em 'p' um termo com     */
/* expoente 'e', e que 'c' n�o � zero.                                  */

Polinomio MultTermo(Polinomio p, int e, float c);
/* Devolve o polin�mio 'p' multiplicado pelo termo '(e,c)'. Sup�e       */
/* que 'c' n�o � nulo. N�o altera os polin�mio dado.                    */

Polinomio SomaPolinomios(Polinomio a, Polinomio b);
/* Devolve a soma dos polin�mios 'a' e 'b'. N�o altera os polin�mios    */
/* dados. Termos nulos n�o s�o inseridos no resultados.                 */

Polinomio MultTermo(Polinomio p, int e, float c);
/* Devolve o polin�mio 'p' multiplicado pelo termo '(e,c)'. Sup�e       */
/* que 'c' n�o � nulo. N�o altera os polin�mio dado.                    */

Polinomio MultPolinomios(Polinomio a, Polinomio b);
/* Devolve o produto dos polin�mios 'a' e 'b'. N�o altera os polin�mios */
/* dados. Deve usar as fun��es 'MultTermo' e 'SomaPolinomios'.          */
