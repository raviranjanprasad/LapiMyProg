#include "aupe.h"

typedef struct t_param{
  int a;
  int b;
  int res;
}t_param;

void *thread_function(void *arg) {
	t_param *l_arg = (t_param*)arg;
	printf("thread_function Arguments %d and %d\n",l_arg->a,l_arg->b);
	sleep(3);
        l_arg->res = l_arg->a + l_arg->b;
	pthread_exit(l_arg);
}

int main(int argc,char *argv[]) {
	int res;
	pthread_t a_thread;
	void *thread_result;
        int p1=atoi(argv[1]);
	int p2=atoi(argv[2]);

        t_param *thArgs = (t_param*)malloc(sizeof(t_param));
	thArgs->a = p1;
	thArgs->b = p2;
	res = pthread_create(&a_thread, NULL, thread_function, (void *)thArgs);
	if (res != 0) {
		perror("Thread creation failed");
		exit(EXIT_FAILURE);
	}
	printf("Waiting for thread to finish\n");
	res = pthread_join(a_thread, &thread_result);
	if (res != 0) {
		perror("Thread join failed");
		exit(EXIT_FAILURE);
	}
	printf("Thread joined, it returned %d\n", ((t_param*)thread_result)->res);
	exit(EXIT_SUCCESS);
}
