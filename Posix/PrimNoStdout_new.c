/**************************************************************
 * Program to find all prime numbers between given two nos. 
 * Objectives:
 * 	1. It should take the range of nos as a command line arguments
 * 	2. The program should print the output in a file e.g 
 * 	   output.txt, by using printf statement.
 * 	3. Make a moduler programming approch, i.e the logic of
 * 	   getting prime no, display logic  should be sperate.
 * 	   as shown below.
 *
 * Exmaple:
 * [ravi@localhost Posix]$ ./PrimNoStdout 30 150
 * 
 * Result:
 * output.txt
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
 **************************************************************/
#include"aupe.h"
int *getPrimNos(int lprimes,int hprimes){
	int i,j;
        int count=0;
	int index=1;
	int *prime = (int *)malloc((hprimes - lprimes)*sizeof(int));
        
        for (i=lprimes; i<hprimes; i++) {
                count = 0;
                for(j=2;j<=i/2;j++){
                        if(i%j==0){
                                count++;
                                break;
                        }
                }
                if(count==0 && i!= 1)
                  prime[index++] = i;
        }

	//Smart way to store the size of an array
        prime[0] = index - 1;
	return prime;
}

void display(int *arr){
        int i;
        close(1);
        if(open("/home/ravi/MyProg/Posix/output.txt", oflag,mode) == -1){
	   perror("/home/ravi/MyProg/Posix/output.txt");
	   exit(1);
	}
        /*if(write(1,arr,arr[0]*sizeof(int)) == -1){
	   perror("Prime Output");
	   exit(1);
	}*/

        printf("prime size=%d\n",arr[0]);
        for (i=1; i<=arr[0]; i++) {
                printf("%d\n", arr[i]);
        }
}

int main(int argc, char *argv[]) {
	int lprimes,hprimes;
	lprimes = atoi(argv[1]);
	hprimes = atoi(argv[2]);
	int *prime=getPrimNos(lprimes,hprimes);
        //It is very difficult to find the size of the array from a returned address.
	display(prime);
        free(prime);
	return(0);
}
