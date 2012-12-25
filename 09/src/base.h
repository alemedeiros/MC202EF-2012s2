/* 
 *  Implementa��o de uma base de dados usando �rvores rubro-negras.
 *
 *  Arquivo base.h: defini��o de tipos e cabe�alhos das fun��es de
 *  manipula��o da base.
 *
 * A base de dados � sempre passada por refer�ncia a fim de
 * uniformizar o tratamento; em alguns casos isto n�o seria
 * necess�rio.
 *
 */

#define ALTURA_MAXIMA 10

typedef enum {false, true} Boolean;

typedef char * String;

typedef void * Base;  /* tipo efetivo escondido */


typedef struct {
  int ra;
  String nome;
  } Aluno;
  
/* Tipo da fun��o a ser passado para a fun��o de percurso: o argumento
   aponta para o campo de informa��o (aluno). */
typedef void TipoVisita(Aluno *aluno);


Base CriaBase();
/* Devolve apontador para uma base vazia */

Boolean InsereBase(Base *p, Aluno a);
/* Insere o registro 'a' na base 'p' se n�o existe aluno
   com o mesmo valor de 'ra', e devolve 'true';  caso
   contr�rio devolve 'false' */
   
Boolean ConsultaBase(Base *p, int ra, Aluno *a);
/* Devolve 'true' se existe um registro com 'ra' dado na
   base 'p';  caso contr�rio devolve 'false'. 'a' conter� 
   os dados do aluno, se encontrado. */
   
int AlturaBase(Base *p);
/* Devolve a altura da base 'p'. */

int AlturaNegraBase(Base *p);
/* Devolve a altura negra da base 'p'. */

int NumeroNosBase(Base *p);
/* Devolve o n�mero de n�s da base 'p'. */

int NumeroNosNegrosBase(Base *p);
/* Devolve o n�mero de n�s negros da base 'p'. */

void PercorreBase(Base *p, TipoVisita Visita);
/* Executa um percurso inordem na base, invocando a fun��o Visita
   para todos os elementos. */

void LiberaBase(Base *p);
/* Libera todos os n�s da base apontada por 'p', bem 
   como todas as cadeias que guardam os nomes. */

void ImprimeBase(Base *p);
/* Imprime a base como �rvore numa forma gr�fica. */
