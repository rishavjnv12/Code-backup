#include "MinHeap.h"
#include <stdio.h>
#include <stdlib.h>

struct MinHeapNode* newMinHeapNode(int v,int key){
    struct MinHeapNode* minHeapNode=(struct MinHeapNode*)malloc(sizeof(struct MinHeapNode));
    minHeapNode->v=v;
    minHeapNode->key=key;
    return minHeapNode;
}
int isInMinHeap(struct MinHeap *minHeap,int v){
    return (minHeap->pos[v]<minHeap->size);
}
struct MinHeap* createMinHeap(int capacity){
    struct MinHeap* minHeap=(struct MinHeap*)malloc(sizeof(struct MinHeap));
    minHeap->pos = (int*)malloc(capacity * sizeof(int)); 
	minHeap->size = 0; 
	minHeap->capacity = capacity; 
	minHeap->array = (struct MinHeapNode**)malloc(capacity * sizeof(struct MinHeapNode*)); 
	return minHeap; 
}

void swapMinHeapNode(struct MinHeapNode** a, struct MinHeapNode** b){
    struct MinHeapNode* temp=*a;
    *a=*b;
    *b=temp;
}

void minHeapify(struct MinHeap* minHeap,int idx){
    int smallest=idx;
    int left=2*idx + 1;
    int right=2*idx+2;

    if(left<minHeap->size && minHeap->array[left]->key < minHeap->array[smallest]->key){
        smallest=left;
    }

    if(right<minHeap->size && minHeap->array[right]->key < minHeap->array[smallest]->key){
        smallest=right;
    }
    if(smallest!=idx){
        struct MinHeapNode* smallestNode=minHeap->array[smallest];
        struct MinHeapNode* idxNode=minHeap->array[idx];

        minHeap->pos[smallestNode->v]=idx;
        minHeap->pos[idxNode->v]=smallest;

        swapMinHeapNode(&minHeap->array[smallest],&minHeap->array[idx]);
        minHeapify(minHeap,smallest);
    }
}
int isEmpty(struct MinHeap* minHeap){
    return minHeap->size==0;
}
struct MinHeapNode* extractMin(struct MinHeap* minHeap){
    if(isEmpty(minHeap))
        return NULL;
    
    struct MinHeapNode* root = minHeap->array[0];
    struct MinHeapNode* lastNode=minHeap->array[minHeap->size-1];
    minHeap->array[0]=lastNode;

    --minHeap->size;
    minHeapify(minHeap,0);

    return root;
}

void decreaseKey(struct MinHeap* minHeap,int v,int key){
    int i=minHeap->pos[v];
    minHeap->array[i]->key=key;
    while(i && minHeap->array[i]->key < minHeap->array[(i-1)/2]->key){
        minHeap->pos[minHeap->array[i]->v] = (i - 1) / 2; 
		minHeap->pos[minHeap->array[(i - 1) / 2]->v] = i; 
		swapMinHeapNode(&minHeap->array[i], &minHeap->array[(i - 1) / 2]);

        i=(i-1)/2;
    }
}