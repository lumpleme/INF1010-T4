#include <stdlib.h>
#include <stdio.h>
#include "t4.h"


void imprimeArray(int ocorrencias[]){
  printf("Array:\n");
  for(int i = 0; i < tam; i++){
	printf("%c - %d ocorrencias\n", i, ocorrencias[i]);
  }	
  return;	
}

No * insereLista (No * lista, char c, int quant){
  No * novo = NULL, * p = lista, * ant = NULL;
  novo = (No *)malloc(sizeof(No));
  if(novo == NULL){
    printf("Erro na alocacao");
    return NULL;
  }
  novo->a = c;
  novo->ocorrencia = quant;
  novo->dir = NULL;
  novo->esq = NULL;
	
  if(lista == NULL){
    lista = novo;
    novo->prox = NULL;
    return lista;
  }
	
  for(; p != NULL; p = p->prox){
    if(p->prox != NULL){
      if(p->prox->ocorrencia >= quant){
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
  for(int i = 0; i < tam; i++){
	lista = insereLista(lista, i, ocorrencias[i]);
  }
  return lista;
}
