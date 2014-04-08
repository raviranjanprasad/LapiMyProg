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
#define NTHREAD 10
typedef struct thrdParam{
	int lprimes;
	int hprimes;
	int *prime;
}thrdParam;

pthread_mutex_t mtx;

void display(void *arr){
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

}

void *getPrimNos(void *args){
	thrdParam *l_args=(thrdParam*)args;
	int i,j,mres;
        int count=0;
	int index=1;

        printf("Starting thread ID=%lu with arguments start=%d  end=%d\n",pthread_self(),l_args->lprimes,l_args->hprimes);
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
        mres=pthread_mutex_lock(&mtx);
        if(mres != 0)
             perror("Mutex lock failed\n");

        display(l_args->prime);

        mres=pthread_mutex_unlock(&mtx);
        if(mres != 0)
             perror("Mutex unlock failed\n");

	pthread_exit(NULL);
}


int main(int argc, char *argv[])
{
	int lp,hp,start,end,slot,temp,i,mres;
	pthread_t threads[NTHREAD];
        pthread_attr_t attr;
        pthread_attr_init(&attr);
        pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_JOINABLE);
        //pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED);

        pthread_mutexattr_t mtxAttr;
	mres=pthread_mutexattr_settype(&mtxAttr,PTHREAD_MUTEX_ERRORCHECK);
        if(mres!=0)
           perror("Setting Mutex Attribute as PTHREAD_MUTEX_ERRORCHECK failed\n");
     
        mres=pthread_mutex_init(&mtx,&mtxAttr);
        if(mres!=0)
           perror("Initializing Mutex Attribute failed\n");
        
	lp = atoi(argv[1]);
	hp = atoi(argv[2]);
        start=0; end=0;

        slot = (hp - lp)/NTHREAD;
	for(i=0;i<NTHREAD;i++){
                if(end == 0)
		  start = lp;
		else
		  start = end;
                
                end = start + slot;
                temp = end + slot;
                if(temp > hp)
		  end = hp;

                thrdParam *m_param=(thrdParam*)malloc(sizeof(thrdParam));
		m_param->lprimes = start;
		m_param->hprimes = end;
		m_param->prime = (int*)malloc((end - start)*sizeof(int));

		//Thread to find the prime numbers
		int mres=pthread_create(&threads[i],&attr, getPrimNos, (void *)m_param);
		if (mres != 0) {
			perror("Thread creation failed");
			exit(EXIT_FAILURE);
		}
	}

	/*for(i=0;i<NTHREAD;i++){
		printf("Waiting for thread to finish\n");
		mres = pthread_join(threads[i], NULL);
		if (mres != 0) {
			perror("Thread join failed");
			exit(EXIT_FAILURE);
		}
	}*/
        sleep(5);
        mres = pthread_mutexattr_destroy(&mtxAttr);  
        if(mres!=0)
           perror("pthred_mutexattr_destroy failed\n");

	return(0);
}
