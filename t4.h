
typedef struct no No; 

struct no {
	char a;
	int ocorrencia;
	No* dir;
	No* esq;
	No* prox;
};