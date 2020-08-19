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
    for(long long i=0; i<=limit;i++)
        sum+=i;
    
   //sum is the global variable

   pthread_exit(0);

}

int main(int argc, char **argv){
    if(argc < 2){
        printf("Usage: %s <num1><num3><num3><num4>\n",argv[0]);
        exit(-1);
    }

    int num_args=argc-1;


   
    pthread_t tids[num_args];
    for(int i=0;i<num_args;i++){
        long long limit = atoll(argv[i+1]);
        pthread_attr_t attr;
        pthread_attr_init(&attr);
        pthread_create(&tids[i],&attr,sum_runner,&limit);
    }
    
    
    for(int i=0;i<num_args;i++){
        pthread_join(tids[i],NULL);
    }

    printf("sum is %lld\n",sum);

    return 0;
}
