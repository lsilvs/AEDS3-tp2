// .c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"

int prog_din(char * palavra) {
	int j, k, l, length;
	int array[2][5001];
	memset(array, 0, sizeof array);   
    length = strlen(palavra);


    for(j = length-1; j >= 0; j--) {
        char ch = palavra[j];

        for (k = 0; k < length; k++)
            if (ch == palavra[k])
                array[1][k+1] = array[0][k]+1;
            else 
            	array[1][k+1] = max(array[1][k], array[0][k+1]);

        for (l = 0; l <= length; l++)
            array[0][l] = array[1][l];
    }
    return (length - array[1][k]);
}


inline int primeira_ocor_rev(char letra, char *palavra_rev, int R)
{
    int i;

    for (i = R+1; i<strlen(palavra_rev); i++)
    {
        if (letra == palavra_rev[i])
        {
            return(i);
        }

    }

    return(-1);
}

int prog_gul(char * palavra) {

    int I, R=-1, length, fixas=0; int ocor_aux1, ocor_aux2;
    char *palavra_rev = malloc(sizeof(char)*5001);

    length=strlen(palavra);

    //reverso da palavra
    int j = strlen(palavra)-1, i;
    for(i=0; i<strlen(palavra); i++)
    {
        palavra_rev[j] = palavra[i];
        j--;
    }

    //percorrer a palavra comparando com seu reverso
    for (I=0; I<length; I++)
    {
        //verifica se ja chegou no final do reverso
        if(R<length-1)
        {
            if (I < length-2)
            {
                ocor_aux1 = primeira_ocor_rev(palavra[I], palavra_rev, R);
                ocor_aux2 = primeira_ocor_rev(palavra[I+1], palavra_rev, R);


                //salva ocorrencia em R

                //duas letras acima de R
                if (ocor_aux1 > R && ocor_aux2 > R)
                {
                    if (ocor_aux1 < ocor_aux2){
                        R = ocor_aux1; fixas += 1;
                    }
                    else if (ocor_aux1 > ocor_aux2){
                        R = ocor_aux2; fixas += 1; I++;
                    }
                    else if (ocor_aux1 == ocor_aux2)
                    {
                        R = ocor_aux1; fixas += 1;
                    }
                }
                //primeira letras acima de R
                else if (ocor_aux1 > R)
                {
                    R = ocor_aux1; fixas += 1;
                }
                //segunda letras acima de R
                else if (ocor_aux2 > R)
                {
                    R = ocor_aux2; fixas += 1; I++;
                }

            }
            //so tem uma letra para comparar (ultima execucao)
            else
            {
                ocor_aux1 = primeira_ocor_rev(palavra[I], palavra_rev, R);
                if(ocor_aux1 != -1)
                {
                    R = ocor_aux1;
                    fixas += 1;
                }
            }

        }
        else
        {
            break;
        }

    }
free(palavra_rev);

return (length - fixas);
}


