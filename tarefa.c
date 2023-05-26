#include <stdio.h>
#include "t4.h"


int main(void) {
	FILE* f;
	unsigned char c;

	//Array que cont�m o n�mero de ocorr�ncias de cada char no arquivo

	int ocorrencias[128];

	//Inicializa o array com 0

	for (int i = 0; i < 128; i++) {
		ocorrencias[i] = 0;
	}

	//Abre o arquivo

	f = fopen("frase.txt", "r");

	if (f == NULL) {
		printf("erro ao abrir arquivo\n");
		return NULL;
	}

	/*L� os caracteres do arquivo e de acordo com seu valor ASCII(indice no array)
	* e incrementa 1 toda vez q esse caracter for encontrado */

	while (!feof(f)) {
		fread(&c, sizeof(unsigned char), 1, f);
		ocorrencias[c]++;
	}

	fclose(f);


	return 0;
}