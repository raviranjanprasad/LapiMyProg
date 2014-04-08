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
 * int main(......){
 * ...
 * int *prime=getPrimNos(lprimes,hprimes);
 * display(prime);
 * .... 
 * }
 **************************************************************/
#include"aupe.h"
typedef struct thrdParam{
	int lprimes;
	int hprimes;
	int *prime;
}thrdParam;


void *getPrimNos(void *args){
	thrdParam *l_args=(thrdParam*)args;
	int i,j;
        int count=0;
	int index=1;
	//int l_args->prime = (int*)malloc((l_args->hprimes - l_args->lprimes)*sizeof(int));
	printf("Thread function arguments %d and %d\n",l_args->lprimes,l_args->hprimes);        
        for (i=l_args->lprimes; i<l_args->hprimes; i++) {
                count = 0;
                for(j=2;j<=i/2;j++){
                        if(i%j==0){
                                count++;
                                break;
                        }
                }
                if(count==0 && i!= 1)
                  l_args->prime[index++] = i;
        }

	//Smart way to store the size of an array
        l_args->prime[0] = index - 1;
	pthread_exit(l_args->prime);
}

void *display(void *arr){
        int i;
	int *l_arr=(int*)arr;
        close(1);
        if(open("/home/ravi/MyProg/Thread/output.txt", oflag,mode) == -1){
	   perror("/home/ravi/MyProg/Thread/output.txt");
	   exit(1);
	}

        printf("prime size=%d\n",l_arr[0]);
        for (i=1; i<=l_arr[0]; i++) {
                printf("%d\n", l_arr[i]);
        }
	pthread_exit(NULL);
}

int main(int argc, char *argv[]) {
	int lp,hp,*prime;
	pthread_t id1,id2;
	void *thread_result;
	lp = atoi(argv[1]);
	hp = atoi(argv[2]);
        
        thrdParam *m_param=(thrdParam*)malloc(sizeof(thrdParam));
        m_param->lprimes = lp;
	m_param->hprimes = hp;
	m_param->prime = (int*)malloc((hp - lp)*sizeof(int));
        
	//Thread to find the prime numbers
        int res=pthread_create(&id1, NULL, getPrimNos, (void *)m_param);
        if (res != 0) {
                perror("Thread creation failed");
                exit(EXIT_FAILURE);
        }
        printf("Waiting for thread to finish\n");
        res = pthread_join(id1, &thread_result);
        if (res != 0) {
                perror("Thread join failed");
                exit(EXIT_FAILURE);
        }

	prime=(int*)thread_result;
	
	//Thread to Display the Prime numbers
        res=pthread_create(&id2, NULL, display, (void *)prime);
        if (res != 0) {
                perror("Thread creation failed");
                exit(EXIT_FAILURE);
        }
        res = pthread_join(id2, NULL);
        if (res != 0) {
                perror("Thread join failed");
                exit(EXIT_FAILURE);
        }

        free(prime);
	return(0);
}
