// .c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"

int prog_din(char * palavra) {
	int j, k, l, length;
	int dp[2][5001];
	memset(dp, 0, sizeof dp);   
    length = strlen(palavra);


    for(j = length-1; j >= 0; j--) {
        char ch = palavra[j];
        for (k = 0; k < length; k++)
            if (ch == palavra[k])
                dp[1][k+1] = dp[0][k]+1;
            else 
            	dp[1][k+1] = max(dp[1][k], dp[0][k+1]);

        for (l = 0; l <= length; l++)
            dp[0][l] = dp[1][l];
    }
    printf("%d\n", (length - dp[1][k]));
}
