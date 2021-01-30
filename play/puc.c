#include <stdio.h>
#include <stdlib.h>
int main(){
    system("echo \"print('Hello World')\" > hello.py");
    
    system("python3 hello.py");
    return 0;
}