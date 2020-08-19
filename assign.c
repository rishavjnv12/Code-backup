#include <stdio.h>
void swap(int *a,int *b){
    int temp = *a;
    *a=*b;
    *b=temp;
}
int main(){
    int n;
    printf("Enter size:");
    scanf("%d",&n);
    int arr[n];
    printf("Enter Elements:\n");
    for(int i=0;i<n;i++){  
        scanf("%d",&arr[i]);
    }
    int pos=0;
    for(int i=0;i<n;i++){
        if(arr[i]%3==0)
            swap(&arr[i],&arr[pos++]);
    }
    for(int i=0;i<n;i++){
        if(arr[i]%3==1)
            swap(&arr[i],&arr[pos++]);
    }
    
    printf("Final Array:\n");
    for(int i=0;i<n;i++){
        printf("%d,",arr[i]);
    }
    printf("\n");
    return 0;
}