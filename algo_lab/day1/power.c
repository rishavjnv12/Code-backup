#include <stdio.h>
int cmp1=0;
int cmp2=0;
int power1(int x,int n){
    if(n==0){
        cmp1++;
        return 1;
    }else{
        cmp1++;
        return x*power1(x,n-1);
    }
}
int power2(int x,int n){
    if(!n){ 
        cmp2++;
        return 1;
    }
    int temp=power2(x,n/2);
    if(n%2){
        cmp2++;
        return x*temp*temp;
    }
    else {
        cmp2++;
        return temp*temp;
    }
}
int main(){
    int x,n;   
    printf("Enter x and n: ");
    scanf("%d%d", &x, &n);
    printf("With O(n) time complexity:\n%d^%d=%d\n",x,n,power1(x,n));
    printf("No. of comparison = %d\n\n",cmp1);
    printf("With O(log2(n)) time complexity:\n%d^%d=%d\n",x,n,power2(x,n));
    printf("No. of comparison = %d\n\n",cmp2);
    return 0;
}