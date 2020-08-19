#include<stdio.h>
#include<stdlib.h>

void heapsort(int *,int);
void heapify(int *,int,int);
void swap(int *,int *);

float count=0.0,count2=0.0;

int main()
{
	int j=0,n,k;
	printf("Enter the size of Array: ");
	scanf("%d",&n);
	printf("Enter the elements: ");
	int i,m,l;
	int *arr=(int*)malloc(n*sizeof(int));
	for(i=0;i<n;i++)
		scanf("%d",&arr[i]);
	heapsort(arr,n);
	printf("\nSorted Array is: ");
	for(m=0;m<n;m++)
		printf("%d\t",arr[m]);
	printf("\nNumber of Comparison: %f\n",count);
	count2=count2+count;
	count=0.0;
	return 0;
}

void heapsort(int *arr,int n)
{
	int i;
	for(i=n/2-1;i>=0;i--)
		heapify(arr,n,i);
	for(i=n-1;i>=0;i--)
	{
		swap(&arr[0],&arr[i]);
		heapify(arr,i,0);
	}
}
void heapify(int *arr,int n,int i)
{
	int largest=i,left,right;
	left=2*i+1;
	right=2*i+2;
	if(left<n && count++ && arr[left]>arr[largest])
		largest=left;
	if(right<n && count++ && arr[right]>arr[largest])
		largest=right;
	if(largest!=i)
	{
		swap(&arr[i],&arr[largest]);
		heapify(arr,n,largest);
	}
}
void swap(int *a,int *b)
{
	int t;
	t=*a;
	*a=*b;
	*b=t;
}
