#include<stdio.h> 
#include <stdlib.h>
#include <time.h>
int cmp=0;
void swap(int* a, int* b){ 
	int t = *a; 
	*a = *b; 
	*b = t; 
} 
/*int partition (int arr[], int low, int high){ 
	int pivot = arr[high]; 
	int i = (low - 1); 
	for (int j = low; j <= high- 1; j++){ 
		if (cmp++ && arr[j] < pivot){ 
			i++; 
			swap(&arr[i], &arr[j]); 
		} 
	}
	swap(&arr[i + 1], &arr[high]); 
	return (i + 1); 
}*/
int partition(int arr[], int low, int high){
    int i=low,j=high-1;
    int pivot=arr[high];
    while(i<j){
        
    }
}
void quickSort(int arr[], int low, int high){ 
	if (low < high){
		int pi = partition(arr, low, high);	
		quickSort(arr, low, pi - 1); 
		quickSort(arr, pi + 1, high); 
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
    clock_t x=clock();
    int totalNoOfComparations=0;
    for(int i=0;i<noOfArrays;i++){
        for(int j=0;j<n;j++){
            srand((unsigned int)time(&x));
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
        quickSort(arr,0,n-1);
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
    /*int arr[10]={97,25,47,25,97,47,52,477,25,11};
    quickSort(arr,0,9);
    for(int j=0;j<10;j++)
            printf("%d ",arr[j]);*/
    
    return 0;
}