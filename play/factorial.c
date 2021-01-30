#include <stdio.h>
int main(){
    int num;
    printf("Enter a number: ");
    scanf("%d",&num);
    long long int fact = 1;
    for(int i=1;i<=num;i++){
        fact = fact * i;
    }
    printf("Factorial of %d is %lld\n",num,fact);
    return 0;
}