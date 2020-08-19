#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

//The sum computed by background thread
long long sum=0;


// Thread Function to generate sum of 0 to N
void* sum_runner(void *arg){
    long long *limit_ptr=(long long*)arg;
    long long limit=*limit_ptr;

    //printf("Hello world\n");
    for(long long i=0; i<=limit;i++){
        sum+=i;
    }
   //sum is the global variable

   pthread_exit(0);

}

int main(int argc, char **argv){
    if(argc < 2){
        printf("Usage: %s <num>\n",argv[0]);
        exit(-1);
    }
    long long limit = atoll(argv[1]);

    //Thread ID
    pthread_t tid;

    //Create attributes
    pthread_attr_t attr;
    pthread_attr_init(&attr);

    pthread_create(&tid,&attr,sum_runner,&limit);
    
    //Do other stuff

    //printf("Hello world\n");
    //wait untill the thread is done its work
    pthread_join(tid,NULL);

    printf("sum is %lld\n",sum);

    return 0;
}
