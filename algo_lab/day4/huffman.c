#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

struct MinHeapNode{
    char data;
    int freq;
    struct MinHeapNode *left,*right;
};

struct MinHeap{
    int size;
    int capacity;
    struct MinHeapNode **array;
};

struct MinHeap* createMinHeap(int capacity){
    struct MinHeap * minheap=(struct MinHeap *)malloc(sizeof(struct MinHeap));
    minheap->capacity=capacity;
    minheap->size=0;
    minheap->array=(struct MinHeapNode **)malloc(sizeof(struct MinHeapNode *)*capacity);
    return minheap;
}
struct MinHeapNode* newNode(char data,int freq){
    struct MinHeapNode * temp=(struct MinHeapNode *)malloc(sizeof(struct MinHeapNode));
    temp->left=NULL;
    temp->right=NULL;
    temp->data=data;
    temp->freq=freq;
    //printf("From new node\n");
    return temp;
}
void swap(struct MinHeapNode **a,struct MinHeapNode **b){
    struct MinHeapNode* temp=*a;
    *a=*b;
    *b=temp;
}
void MinHeapify(struct MinHeap*minheap,int i){
    int smallest=i;
    int left=i*2+1;
    int right=(i+1)*2;

    if(left<minheap->size && minheap->array[left]->freq<minheap->array[smallest]->freq){
        smallest=left;
    }
    if(right<minheap->size && minheap->array[right]->freq<minheap->array[smallest]->freq){
        smallest=right;
    }
    if(smallest!=i){
        swap(&minheap->array[smallest],&minheap->array[i]);
        MinHeapify(minheap,smallest);
    }
}
 
struct MinHeapNode* extractMin(struct MinHeap* minheap){
    struct MinHeapNode * temp=minheap->array[0];
    minheap->array[0]=minheap->array[minheap->size-1];
    minheap->size=minheap->size-1;
    MinHeapify(minheap,0);
    return temp;
}
void insertMinHeap(struct MinHeap *minHeap,struct MinHeapNode* minHeapNode){
    minHeap->size=minHeap->size+1;
    int i=minHeap->size-1;
    while(i && minHeapNode->freq<minHeap->array[(i-1)/2]->freq){
        minHeap->array[i]=minHeap->array[(i-1)/2];
        i=(i-1)/2;
    }

    minHeap->array[i]=minHeapNode;
}
struct MinHeap* createAndBuildMinHeap(char data[],int freq[],int size){
    struct MinHeap* minheap = createMinHeap(size);
    for(int i=0;i<size;i++){
        minheap->array[i]=newNode(data[i],freq[i]);
    }
    minheap->size=size;
    //printf("%d\n",minheap->size);
    int n=minheap->size-1;
    for(int i=(n-1)/2;i>=0;i--){
        MinHeapify(minheap,i);
    }
    return minheap;
}
struct MinHeapNode* buildHuffmanTree(char data[], int freq[], int size){ 
	struct MinHeapNode *left, *right, *top; 
	struct MinHeap* minHeap = createAndBuildMinHeap(data, freq, size); 
	while (minHeap->size!=1) { 
		left = extractMin(minHeap); 
		right = extractMin(minHeap); 
		top = newNode('$', left->freq + right->freq); 
		top->left = left; 
		top->right = right; 
		insertMinHeap(minHeap, top); 
	}
	return extractMin(minHeap); 
} 
void printCodes(struct MinHeapNode *root,int arr[],int top){
    if(root->left){
        arr[top]=0;
        printCodes(root->left,arr,top+1);
    }
    if(root->right){
        arr[top]=1;
        printCodes(root->right,arr,top+1);
    }
    if(!(root->left) && !(root->right)){
        printf("%c: ",root->data);
        for(int i=0;i<top;i++){
            printf("%d",arr[i]);
        }
        printf("\n");
    }
}

void HuffmanCodes(char data[],int freq[],int size){
    struct MinHeapNode*root = buildHuffmanTree(data,freq,size);
    int arr[MAX_SIZE],top=0;
    printCodes(root,arr,top);
}
int main(){
    char arr[]={'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[]={5,9,12,13,16,45};
    int size=sizeof(arr)/sizeof(arr[0]);
    HuffmanCodes(arr,freq,size);
    return 0;
}