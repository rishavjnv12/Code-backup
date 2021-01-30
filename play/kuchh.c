#include <stdio.h>
int main(){
    #ifdef VAR
        printf("Here\n");
    #endif
    #ifndef VAR
        printf("Now Here\n");
    #endif
    return 0;
}