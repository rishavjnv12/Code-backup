#include <stdio.h>
#include <stdlib.h>
int cmp=0;
void merge(int *arr,int l,int m,int r){
    int i,j,k;
    int n1=m-l+1;
    int n2=r-m;
    int left[n1],right[n2];

    for(i=0;i<n1;i++)
        left[i]=arr[l+i];
    for(j=0;j<n2;j++)
        right[j]=arr[m+1+j];

    i=j=0;
    k=l;
    while(i<n1 && j<n2){
        if(cmp++ && left[i]<right[j]){
            arr[k]=left[i];
            i++;
        }else{
            arr[k]=right[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        arr[k]=left[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k]=right[j];
        j++;
        k++;
    }
}
void mergesort(int *arr,int l,int r){
    if(l<r){
        int mid=l+(r-l)/2;
        mergesort(arr,l,mid);
        mergesort(arr,mid+1,r);
        merge(arr,l,mid,r);
    }
}
int main(){
    FILE* fileptr=fopen("input.txt","w+");
    if(fileptr==NULL){
        printf("Error opening input file\n");
        exit(1);
    }
    int noOfArrays=5;
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
        mergesort(arr,0,n-1);
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