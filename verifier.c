#include <stdio.h>

int main(int argc, char* argv[]){
    int c, m = 0, n = 0, i, j;
    char M[100], G[50], R[100];/*represents dividend polynomial, divisor polynomial and remainder polynomial*/
    
    /*Read the first line of the output of the generator program, that represents the polynomial*/
    while ((c = getchar()) != '\n'){
	G[n] = c;          //store the polynomial in G
	n++;               //the number of bits in G
    }
    
    /*Read the second line of the output of the generator program, that represents the message treansmitted.*/
    while ((c = getchar()) != '\n'){
	M[m] = c;          //store the message in M
	m++;               //the number of bits in M
    }
    
    /*At first, makes the remainder equal to dividend.*/
    for (i = 0; i < m; i++){
	R[i] = M[i];
    }

    /*You have to calculate (m-n+1) times to get the remainder R.*/
    for (i = 0; i < m - n + 1; i++){
	if (R[i] == '1'){
	    for (j = i; j < n + i; j++){
		/*Because R[j] is a character, the action of exclusive-OR equals to that if the two characters is the same, them the result is '0', else, the result is '0'.*/
		if (R[j] == G[j - i]) R[j] = '0';
		else R[j] = '1';
}
	}
	else{
	    for (j = i; j < n + i; j++){
		if (R[j] == '0') R[j] = '0';
		else R[j] = '1';
	    }
	}
    }

    j = 0;            //*the number of '0' in remainder R
    /*If the remainder is 0, that means j equals to m, then the message transmitted is correct.*/
    for (i = 0; i < m; i++){
	if (R[i] == '0'){
	    j++;
	    continue;
	}
	else{
	    printf("Errors accur while transmitting.\n");
	    return;
	}
    }
    if (j == m){
	printf("The message is transmitted correctly.\n");
	printf("The original message is: ");
	for (i = 0; i < m - n + 1; i++) putchar(M[i]);
	putchar('\n');
    }

    return 0;
}
