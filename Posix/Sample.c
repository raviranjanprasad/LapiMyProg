/**************************************************************
 * Program to find all prime numbers between given two nos. 
 * Objectives:
 * 	1. It should take the range of nos as a command line arguments.
 * 	2. The program should print the output in a file e.g 
 * 	   output.txt, by using printf statement.
 * 	3. Make a moduler programming approch, i.e the logic of
 * 	   getting prime no, display logic  should be sperate.
 * 	   as shown below in the skelton program.
 *
 * Exmaple:
 * [compile]
 * [ravi@localhost Posix]$ gcc -g -Wall PrimNo.c -o PrimNo
 *
 * [Run]
 * [ravi@localhost Posix]$ ./PrimNo 30 150
 * 
 * Result:
 * [ravi@localhost Posix]$ output.txt
 *
 * [ravi@localhost Posix]$ cat output.txt
 * Total prime nos=25
 * 31
 * 37
 * 41
 * 43
 * .
 * .
 * .
 * 149
 * Note: "aupe.h" is a header file which have all essential 
 *        header files required.
 **************************************************************/
#include"aupe.h"
int *getPrimNos(.........){
	.
	.
	.
}

void display(.......){
	.
	.
}

int main(int argc, char *argv[]) {
        int low, high;
        .
	.
	.
	.
	int *prime=getPrimNos(low,high);
	display(prime);

	return(0);
}
