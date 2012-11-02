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


int prog_gul(char * palavra) {
	int *best, *prev, i, j, max = 0;
	int length = strlen(palavra);
	best = (int*) malloc ( sizeof( int ) * length );
	prev = (int*) malloc ( sizeof( int ) * length );

	for ( i = 0; i < length; i++ ) best[i] = 1, prev[i] = i;

	for ( i = 1; i < length; i++ )
	  for ( j = 0; j < i; j++ )
	     if ( palavra[i] > palavra[j] && best[i] < best[j] + 1 )
	        best[i] = best[j] + 1, prev[i] = j;

	for ( i = 0; i < length; i++ )
	  if ( max < best[i] )
	     max = best[i];

	free( best );
	free( prev );

	return (length - max);
}


