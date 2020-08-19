#include <stdio.h>
#include <unistd.h>

int main(){
    int x=fork();
    printf("%d.Hello, world\n");
    return 0;
}