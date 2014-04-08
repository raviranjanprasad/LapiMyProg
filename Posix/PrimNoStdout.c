#include"aupe.h"
int main(int argc, char *argv[]) {
	int lprimes,hprimes;
	int *prime;
	int i,j;
        int count=0;
	int index=0;
	lprimes = atoi(argv[1]);
	hprimes = atoi(argv[2]);
	prime = (int *)malloc ((hprimes - lprimes)*sizeof(int));
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
	for (i=0; i<index; i++) {
		printf("%d\n", prime[i]);
	}
	return(0);
}
