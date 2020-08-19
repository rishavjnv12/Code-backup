//compile using gcc basic.c -lpthread -o basic
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *entry_point(void *value){
    printf("Hello from the second thread\n");

    int *num = (int *)value;

    printf("The value of value is %d\n",*num);
    
    return NULL;
}

int main(){
    pthread_t thread;

    printf("hello from the first thread\n");

    int num=123;
    pthread_create(&thread, NULL,entry_point,&num);
    pthread_join(thread, NULL);

    return EXIT_SUCCESS;
}