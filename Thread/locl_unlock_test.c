#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <assert.h>

pthread_mutex_t cntr_mutex = PTHREAD_MUTEX_INITIALIZER;

long protVariable = 0L;
static int mutex_lock=0;
void *myThread( void *arg )
{
	int i, ret;

	if(!mutex_lock){
		mutex_lock=1;
		ret = pthread_mutex_lock( &cntr_mutex );
		assert( ret == 0 );
	}

	for (i = 0 ; i < 10 ; i++) {

		protVariable++;

	//	ret = pthread_mutex_unlock( &cntr_mutex );

	//	assert( ret == 0 );

	}

	pthread_exit( NULL );
}


#define MAX_THREADS    2 

int main()
{
	int ret, i;
	pthread_t threadIds[MAX_THREADS];

	/*for (i = 0 ; i < MAX_THREADS ; i++) {
		ret = pthread_create( &threadIds[i], NULL, myThread, NULL );
		if (ret != 0) {
			printf( "Error creating thread %d\n", (int)threadIds[i] );
		}
	}*/

        ret = pthread_create( &threadIds[0], NULL, myThread, NULL );
                if (ret != 0) {
                        printf( "Error creating thread %d\n", (int)threadIds[i] );
                }
	if(mutex_lock){
		mutex_lock=0;
		ret = pthread_mutex_unlock( &cntr_mutex );
		assert( ret == 0 );
	}
        
        ret = pthread_create( &threadIds[1], NULL, myThread, NULL );
                if (ret != 0) {
                        printf( "Error creating thread %d\n", (int)threadIds[i] );
                }


	/*for (i = 0 ; i < MAX_THREADS ; i++) {
		ret = pthread_join( threadIds[i], NULL );
		if (ret != 0) {
			printf( "Error joining thread %d\n", (int)threadIds[i] );
		}
	}*/

	printf( "The protected variable value is %ld\n", protVariable );

	ret = pthread_mutex_destroy( &cntr_mutex );

	if (ret != 0) {
		printf( "Couldn.t destroy the mutex\n");
	}

	return 0;
}
