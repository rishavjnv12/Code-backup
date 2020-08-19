#include <stdio.h>
#include <unistd.h>
int main(){
    if(fork() || fork())
        fork();
    printf("%d.Hello World\n",getpid());
    return 0;
}