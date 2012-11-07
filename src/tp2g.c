/*
*	Problema de Grafos
*		Autor: Lucas Silvestre (2010054665)
*		Data: 09/10/2012
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funcoes.h"



int main(int argc, char *argv[]) {
	// Declara as variáveis
	char * inputFileName = argv[1];
	char * outputFileName = argv[2];
	char * testFileName = "tempos2.txt";
	int numPalavras, i, j, k, l, length;
	char palavra[5001];
	
	// Abrir arquivo de entrada
	FILE * inputFileOpen;
	if ((inputFileOpen = fopen(inputFileName, "r")) == NULL) {
		printf("Nao foi possivel abrir o arquivo.\n");
	}

	// Abrir arquivo de saída
	FILE * outputFileOpen;
	if ((outputFileOpen = fopen(outputFileName, "w")) == NULL) {
		printf("Nao foi possivel abrir o arquivo.\n");
	}

	// Abrir arquivo de testes
	FILE * testFileOpen;
	if ((testFileOpen = fopen(testFileName, "w")) == NULL) {
		printf("Nao foi possivel abrir o arquivo.\n");
	}

	// Lê o número de instâncias
	fscanf(inputFileOpen, "%d", &numPalavras);

	for (j = 10; j < 101; j+=10)
	{
		clock_t start = clock();
		
		/* code */
		for(i = 0; i < j; i++) {
			// Lê a palavra
			fscanf(inputFileOpen, "%s", palavra);
			
			fprintf(outputFileOpen, "%d\n", prog_gul(palavra));
			
		}

		fprintf(testFileOpen, "%f\n", ((double)clock() - start) / CLOCKS_PER_SEC);
	}


	// Retorna 0 se conseguiu fechar o arquivo com sucesso
	if(fclose(inputFileOpen) != 0) {
		printf("Erro ao tentar fechar o arquivo %s\n", inputFileName);
	}

	if(fclose(outputFileOpen) != 0) {
		printf("Erro ao tentar fechar o arquivo %s\n", outputFileName);
	}

	if(fclose(testFileOpen) != 0) {
		printf("Erro ao tentar fechar o arquivo %s\n", testFileName);
	}

	return 0;
}