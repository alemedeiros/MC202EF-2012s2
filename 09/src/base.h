/* 
 *  Implementação de uma base de dados usando árvores rubro-negras.
 *
 *  Arquivo base.h: definição de tipos e cabeçalhos das funções de
 *  manipulação da base.
 *
 * A base de dados é sempre passada por referência a fim de
 * uniformizar o tratamento; em alguns casos isto não seria
 * necessário.
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
  
/* Tipo da função a ser passado para a função de percurso: o argumento
   aponta para o campo de informação (aluno). */
typedef void TipoVisita(Aluno *aluno);


Base CriaBase();
/* Devolve apontador para uma base vazia */

Boolean InsereBase(Base *p, Aluno a);
/* Insere o registro 'a' na base 'p' se não existe aluno
   com o mesmo valor de 'ra', e devolve 'true';  caso
   contrário devolve 'false' */
   
Boolean ConsultaBase(Base *p, int ra, Aluno *a);
/* Devolve 'true' se existe um registro com 'ra' dado na
   base 'p';  caso contrário devolve 'false'. 'a' conterá 
   os dados do aluno, se encontrado. */
   
int AlturaBase(Base *p);
/* Devolve a altura da base 'p'. */

int AlturaNegraBase(Base *p);
/* Devolve a altura negra da base 'p'. */

int NumeroNosBase(Base *p);
/* Devolve o número de nós da base 'p'. */

int NumeroNosNegrosBase(Base *p);
/* Devolve o número de nós negros da base 'p'. */

void PercorreBase(Base *p, TipoVisita Visita);
/* Executa um percurso inordem na base, invocando a função Visita
   para todos os elementos. */

void LiberaBase(Base *p);
/* Libera todos os nós da base apontada por 'p', bem 
   como todas as cadeias que guardam os nomes. */

void ImprimeBase(Base *p);
/* Imprime a base como árvore numa forma gráfica. */
