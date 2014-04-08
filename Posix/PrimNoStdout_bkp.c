#include"aupe.h"
int main(int argc, char *argv[]) {
	int lprimes,hprimes;
	int *prime;
	int i,j;
        int count=0;
	int current = 2;
	lprimes = atoi(argv[1]);
	hprimes = atoi(argv[2]);
        printf("lprimes=%d hprimes=%d\n",lprimes,hprimes);
	prime = (int *)malloc ((hprimes - lprimes)*sizeof(int));
	prime[0] = current;
	for (i=lprimes; i<hprimes; i++) {
NewCandidate:
		current++;
		for (j=0; prime[j]*prime[j] <= current; j++) {
			if (current % prime[j] == 0)
				goto NewCandidate;
		}
		prime[++count] = current;
	}
	for (i=0; i<count; i++) {
		printf("%d\n", prime[i]);
	}
	return(0);
}
