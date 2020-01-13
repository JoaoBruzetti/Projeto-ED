typedef struct cadastro{
    int cod;
    char nome[50], emp[50], dep[50], tel[10], cel[10];
    }CAD;

typedef struct elemento *Lista;

//A função cria lista não recebe nenhum parametro e retorna uma lista duplamente ligada
Lista cria_lista();

//Não recebe nenhum parametro e retorna uma estrutura CAD pronta preenchida pelo usuario
CAD cadastro(Lista *li);

//Cria um codigo para ser usado para o cadstro de um cliente
int cria_codigo(Lista *li, int codigo);

//Insere uma estrutura do tipo CAD na lista em ordem crescente em relação ao codigo do cliente cadastrado
int insere_contato(Lista *li, CAD cl);

// Exibe todos os clientes cadastrados em ordem crescente
int exibe_relatorio_cres(Lista *li);

// Exibe todos os clientes cadastrados em ordem decrescente
int exibe_relatorio_decres(Lista *li);

// Procura na lista algum cliente com o codigo igual ao codigo inserido pelo usuario
// se o cliente com o codigo igual ao que o usuario inseriu for encontrado os dados do cliente serão exibidos
int busca_codigo(Lista *li, int cod);

// Procura na lista algum cliente com o nome igual ao nome inserido pelo usuario
// se o cliente com o nome igual ao que o usuario inseriu for encontrado os dados do cliente serão exibidos
// lembrando que como podem haver 2 ou mais clientes com o mesmo nome a função pode exibir os dados de mais de um cliente
int busca_nome(Lista *li, char nome[50]);

// Retorna o tamanho da lista
int tamanho_lista(Lista *li);

// A função procura na lista um cliente com o cidgo igual ao que o usuario inseriu
// Se o cliente com o codigo inserido pelo usuario for encontrado o usuario tem a opçao de poder editar todos os dados do cliente
// menos o codigo, depois de inserir um novo dado para substituir o antigo o usuario pode confirmar a alteração ou cancela-la
int edita_contato(Lista *li, int cod);

// O usuario insere o codigo de um cliente que ele busca remover da lista se um cliente com esse codigo for achado
// O usuario deve confirmar a decição de excluir um cliente ou pode cancelar a exclusão
int remove_contato(Lista *li, int cod);

//Grava todo o conteudo da lista no arquivo
void grava_arquivo(Lista *li, FILE *f);

// Ao final do progama a lista criada é apagada
void apaga_lista(Lista *li);



