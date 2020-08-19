#include<stdio.h>
#include<stdlib.h>


int main(){
	int n;
	//printf("Enter Size of array:");
	scanf("%d",&n);
	int *arr=(int *)malloc(sizeof(int)*n);
	for(int i=0;i<n;i++)
		arr[i]=i+1;
	permute(arr,0,n-1);
	return 0;
}
