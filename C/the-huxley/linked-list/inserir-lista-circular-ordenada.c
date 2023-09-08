#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef int TIPOCHAVE;

typedef struct
{
    TIPOCHAVE chave;
    char valor[100];
} ITEM;

typedef struct estrutura
{
    ITEM item;
    struct estrutura *prox;
} NO;

typedef struct
{
    NO* cabeca;
    int tamanho;
} LISTA;


// Inicializa a lista deixando-a pronta para ser utilizada.
void inicializar(LISTA *l)
{
    l->cabeca = (NO*) malloc(sizeof(NO));
    l->cabeca->prox = l->cabeca;  // faz a referencia circular
    l->tamanho = 0;
}


// Cria um novo no com o item e o apontador para o proximo passados.
NO* criarNo(ITEM item, NO *prox)
{
    NO* pNovo = (NO*) malloc(sizeof(NO));
    pNovo->item = item;
    pNovo->prox = prox;
    return pNovo;
}


// Retornar o tamanho da lista
int tamanho(LISTA *l)
{
    return l->tamanho;
}


// Retorna true se a lista esta vazia, ou seja, se tem tamanho = 0
bool vazia(LISTA *l)
{
    return tamanho(l) == 0;
}


// Exibicao da lista
void exibirLista(LISTA *l)
{
    NO* p = l->cabeca->prox;
    while (p != l->cabeca)
    {
        printf("(%d,%s)", p->item.chave, p->item.valor);
        p = p->prox;
    }
}

// Imprime a lista partindo da cabeca para a cauda
void imprimirLista(LISTA *l)
{
    printf("Tamanho = %d\n", tamanho(l));
    exibirLista(l);
    printf("\n");
}


// Liberacao das variaveis dinamicas dos nos da lista, iniciando da cabeca
void destruir(LISTA *l)
{
    NO* atual = l->cabeca->prox;
    while (atual != l->cabeca) {  // enquando nao deu a volta completa
        NO* prox = atual->prox; // guarda proxima posicao
        free(atual);            // libera memoria apontada por atual
        atual = prox;
    }
    free(l->cabeca);  // liberacao no No cabeca
    l->cabeca = NULL; // ajusta inicio da lista (vazia)
}


/////////////////////////////////////////////////////

/*
 Objetivo: Inserir em uma lista ordenada o item passado e garantir
           que nao havera duplicacao.
*/
bool inserirNaOrdem(ITEM item, LISTA *l)
{


NO* prev = l->cabeca;
NO* curr = l->cabeca->prox;

while(curr != l->cabeca) {
  	// Ocorre quando ir? acontecer a duplica??o de itens.
 	if(curr->item.chave == item.chave) {
     	return false;
    };
  	// Interrompe a execu??o caso o item inserido seja menor que o valor do item atual.
  	if(curr->item.chave > item.chave) {
    	break;
    }
  	prev = curr;
  	curr = curr->prox;
}
	// Armazena a lista ordenada em um novo n?
	NO* newNode = (NO*)malloc(sizeof(NO));
	newNode->item = item;
	newNode->prox = curr;

	// "Resetando" a cabe?a da lista
	prev->prox = newNode;

	l->tamanho++;

	return true;


}

/////////////////////////////////////////////////////

void lerItens(LISTA *l)
{
    int n;
    scanf("%d", &n);

    // insere os valores n pares chave,valor
    ITEM item;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &item.chave);
        scanf("%s", item.valor);
        inserirNaOrdem(item, l);
    }
}


int main(){
  LISTA l;
  ITEM item;

  inicializar(&l);

  lerItens(&l);
  imprimirLista(&l);

  lerItens(&l);
  imprimirLista(&l);

  destruir(&l);
  return 0;
}
