#include <stdlib.h>
#include "t4.h"

char a;
	int ocorrencia;
	No* dir;
	No* esq;
	No* prox;

No * insereLista (No * lista, char c, int quant){
  if(lista == NULL)
    return NULL;
  No * novo = NULL, No* p = lista, No* ant = NULL;
  novo = (No *)malloc(sizeof(No));
  if(novo == NULL)
    return NULL;
  novo->a = c;
  novo->ocorrencia = quant;
  novo->dir = NULL;
  novo->esq = NULL;
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

No * formaLista (int ocorrencias[]){
  
  
  
}
