#include <stdio.h>
#include <stdlib.h>
#include "t4.h"

struct no {
	char a;
	int ocorrencia;
	No* dir;
	No* esq;
	No* prox;
};


void imprimeArray(int ocorrencias[], int tam){
	printf("Array:\n");
	for (int i = 0; i < tam; i++) {
		printf("%c - %d ocorrencias\n", i, ocorrencias[i]);
	}
	return;	
}

No * insereLista (No * lista, char c, int quant){
	No* novo = NULL, * p = lista, * ant = NULL;
	novo = (No*)malloc(sizeof(No));
	if (novo == NULL) {
		printf("Erro na alocacao");
		return NULL;
	}
	novo->a = c;
	novo->ocorrencia = quant;
	novo->dir = NULL;
	novo->esq = NULL;

	if (lista == NULL) {
		lista = novo;
		novo->prox = NULL;
		return lista;
	}

	for (; p != NULL; p = p->prox) {
		if (p->prox != NULL) {
			if (p->prox->ocorrencia >= quant) {
				ant = p;
				p = p->prox;
				break;
			}
		}
		ant = p;
	}
	ant->prox = novo;
	novo->prox = p;
	return lista;
}

No * formaLista (int ocorrencias[], int tam){
  	No* lista = NULL;
	for (int i = 0; i < tam; i++) {
		lista = insereLista(lista, i, ocorrencias[i]);
	}
	return lista;
}
	
void imprimeLista(No* lista) {
	printf("\nLista encadeada por prioridade:\n\n");
	for (No* p = lista; p != NULL; p = p->prox) {
		printf("%c - %d ocorrencias\n", p->a, p->ocorrencia);
	}
	return;
}

/*arv_vazia verifica se a árvore binária passada como parâmetro está vazia, retorna 1 (True) se estiver,
senão, retorna 0 (False)*/

int arv_vazia(No* a) {
	return a == NULL;
}


/*arvImprime imprime a árvore binária em pré- ordem, ou seja, primeiro as informações no nó raiz,
seguido dos nós à esquerda e por fim os nós à direita*/

void arvImprime(No* a){
	/*Até o final da árvore, imprimimos suas informações*/

	if (!arv_vazia(a)) {
		/*Imprimindo as informações do nó raiz, incluindo seu valor inteiro e os ponteiros do
		nó à esquerda, à direita e seu próprio ponteiro*/

		printf("No:%p Esquerda:%p Char:%c Direita:%p\n", a, a->esq, a->a, a->dir);
		
		/*Imprime as informações dos nós à esquerda recursivamente*/
		
		arvImprime(a->esq); 
		
		/*Imprime as informações dos nós à direita recursivamente*/
		
		arvImprime(a->dir); 
	}
}
