#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int cmp=0;
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void heapify(int *arr,int n,int i){
    int largest=i;
    int l=2*i+1;
    int r=(i+1)*2;
    if(l<n && cmp++ && arr[l]>arr[largest])
        largest=l;
    if(r<n && cmp++ && arr[r]>arr[largest])
        largest=r;
    if(largest!=i){
        swap(arr+i,arr+largest);
        heapify(arr,n,largest);
    }
}
void heapsort(int *arr,int n){
    for(int i=n/2-1;i>=0;i--){
        heapify(arr,n,i);
    }
    for(int i=n-1;i>=0;i--){
        swap(arr+0,arr+i);
        heapify(arr,i,0);
    }
}
int main(){
    FILE* fileptr=fopen("input.txt","w+");
    if(fileptr==NULL){
        printf("Error opening input file\n");
        exit(1);
    }
    int noOfArrays=100;
    int n=1000;
    int totalNoOfComparations=0;
    for(int i=0;i<noOfArrays;i++){
        for(int j=0;j<n;j++){
            fprintf(fileptr, "%d ",rand()%n);
        }
        fprintf(fileptr,"\n\n");
    }
    fseek(fileptr,0,SEEK_SET);
    
    FILE * fileptr2=fopen("output.txt","w");
    if(fileptr2==NULL){
        printf("Error!");
        exit(1);
    }

    for(int i=0;i<noOfArrays;i++){
        int *arr=(int *)malloc(sizeof(int)*n);
        for(int j=0;j<n;j++)
            fscanf(fileptr, "%d", &arr[j]);
        heapsort(arr,n);
        totalNoOfComparations+=cmp;
        cmp=0;
        for(int j=0;j<n;j++)
            fprintf(fileptr2,"%d ",arr[j]);
        fprintf(fileptr2,"\n\n");
        free(arr);
    }

    fclose(fileptr);
    fclose(fileptr2);

    printf("Total no. of comparison is %d\n",totalNoOfComparations);
    float avgcmps=(float)totalNoOfComparations/noOfArrays;
    printf("Average number of comparisons is %.2f\n",avgcmps);
    
    return 0;
}