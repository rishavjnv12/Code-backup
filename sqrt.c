#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(int argc,char** argv){
    if(argc<2){
        printf("Usage:<num>");
    }else{
        printf("%f\n",sqrt(atoi(argv[1])));
    }
    return 0;
}