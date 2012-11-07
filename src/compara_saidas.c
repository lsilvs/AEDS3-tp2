/*
*	Problema do Palíndromo
*		Autor: Lucas Silvestre (2010054665)
*		Data: 07/11/2012
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
	// Declara as variáveis
	char * inputFileName0 = "dicionario.txt";
	char * inputFileName1 = "output1.txt";
	char * inputFileName2 = "output2.txt";
	char * outputFileName = "comp_saida.txt";
	int numPalavras, i, count = 0;
	float val1, val2, soma=0;
	char palavra[5001];
	
	// Abrir arquivo de entrada
	FILE * inputFileOpen0;
	if ((inputFileOpen0 = fopen(inputFileName0, "r")) == NULL) {
		printf("Nao foi possivel abrir o arquivo.\n");
	}

	FILE * inputFileOpen1;
	if ((inputFileOpen1 = fopen(inputFileName1, "r")) == NULL) {
		printf("Nao foi possivel abrir o arquivo.\n");
	}

	FILE * inputFileOpen2;
	if ((inputFileOpen2 = fopen(inputFileName2, "r")) == NULL) {
		printf("Nao foi possivel abrir o arquivo.\n");
	}

	// Abrir arquivo de saída
	FILE * outputFileOpen;
	if ((outputFileOpen = fopen(outputFileName, "w")) == NULL) {
		printf("Nao foi possivel abrir o arquivo.\n");
	}

	// Lê o número de instâncias
	fscanf(inputFileOpen0, "%d", &numPalavras);

	for(i = 0; i < numPalavras; i++) {
		// Lê a vals
		fscanf(inputFileOpen0, "%s", palavra);
		fscanf(inputFileOpen1, "%f", &val1);
		fscanf(inputFileOpen2, "%f", &val2);

		if (val1 != val2) {
			soma += ((val2*100/strlen(palavra)) - (val1*100/strlen(palavra)));
			count++;
		}

		fprintf(outputFileOpen, "%d\t%.2f\t%.2f\n", strlen(palavra), (val1*100/strlen(palavra)), (val2*100/strlen(palavra)));
		
	}

	printf("%d\n", count);
	printf("%f\n", soma/count);


	// Retorna 0 se conseguiu fechar o arquivo com sucesso
	if(fclose(inputFileOpen0) != 0) {
		printf("Erro ao tentar fechar o arquivo %s\n", inputFileName0);
	}

	if(fclose(inputFileOpen1) != 0) {
		printf("Erro ao tentar fechar o arquivo %s\n", inputFileName1);
	}

	if(fclose(inputFileOpen2) != 0) {
		printf("Erro ao tentar fechar o arquivo %s\n", inputFileName2);
	}

	if(fclose(outputFileOpen) != 0) {
		printf("Erro ao tentar fechar o arquivo %s\n", outputFileName);
	}

	return 0;
}