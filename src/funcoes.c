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
