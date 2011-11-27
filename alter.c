#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
    int arg, c, i, m = 0;
    char M[100];
    
    /*Only 2 parameters are logical.*/
    if (argc != 2) return;

    /*Change argv[1] to the form of interger.*/
    arg = atoi(argv[1]);
    
    /*Read the first line of the output of the generator program, get the polynomial, and input to the verify grogram later.*/
    while ((c = getchar()) != '\n'){
	putchar(c);
    }
    printf("\n");
    
    /*Read the second line of the output of the generator program, get the message transmitted.*/
    while ((c = getchar()) != '\n'){
	M[m] = c;          //store the message transmitted in M
	m++;               //the number of bits in M
    }
    
    /*Invert 1 bit in M. It means invert M[arg - 1]*/ 
    if (M[arg - 1] == '0') M[arg - 1] = '1';
    else M[arg - 1] = '0';

    /*Output the message transmitted*/
    for (i = 0; i < m; i++) putchar(M[i]);
    printf("\n");
    
    return 0;
}
