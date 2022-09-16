#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int msum;
int csum;
void *runner(void *param);

int main(int argc, char *argv[]){

	pthread_t 	tid;
	pthread_attr_t	attr;
	pthread_attr_init(&attr);

	pthread_create(&tid, &attr, runner, argv[1]);

    

	int upper = atoi(argv[1]);
	msum = 0;
	int i ;
	for( i = 0 ; i <= upper ; i++)
		msum += i;
	
     	pthread_join(tid,NULL);
	//int dif = csum - msum;
	printf("csum = %d\nmsum = %d\nDifference = %d\n",csum , msum, csum-msum );
	//printf("Difference = %d\n" , dif);
	return 0 ;
}
void *runner (void *param){
	int upper = atoi(param);
	int i;
	csum = 0 ;
	if(upper > 0){
		for(i = 0 ; i <=upper*2 ; i++)
		csum += i;
	}
	pthread_exit(0);
}
