#include <stdio.h>

int main(int argc, char* argv[]){
    int c, m = 0, n = 0, i, j;
    char M[100], G[50], R[100];/*represents dividend polynomial, divisor polynomial and remainder polynomial*/

    /*Read from the file the first line of ASCII text containing an m-bit message consisting of a string of 0s and 1s.*/
    //printf("The message from the file is: ");
    while((c = getchar()) != '\n'){
	//putchar(c);
	M[m] = c;        //store the message in M
	m++;             //the number of bits in M
    }

    /*Read from the file the second line that represents n-bit polynomial, also in ASCII.*/
    //printf("\nThe polynomial is: ");
    while((c = getchar()) != '\n'){
	putchar(c);
	G[n] = c;        //store the divisor polynomial in G
	M[m + n] = '0';  //append 0 bits after M[m - 1]
	n++;             //the number of bits in G
    }
    printf("\n");

    /*At first, makes the remainder equal to dividend.*/
    for (i = 0; i < m + n - 1; i++){
	R[i] = M[i];
    }
    
    /*You have to calculate (m-1) times to get the remainder R.*/
    for (i = 0; i < m - 1; i++){
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
    
    /*The message to be transmitted equals to the subtraction between dividend and remainder*/
    //printf("\nThe message to be transmitted is: ");
    for (i = 0; i < m + n - 1; i++){
	if (R[i] == M[i]) M[i] = '0';
	else M[i] = '1';
	putchar(M[i]);
    }
    printf("\n");

    return 0;
}
