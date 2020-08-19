#ifndef _MINHEAP_H_
#define _MINHEAP_H_

struct MinHeapNode{
    int v;
    int key;
};

struct MinHeadNode{
    int v;
    int key;
};

struct MinHeap{
    int size;
    int capacity;
    int *pos;
    struct MinHeapNode **array;
};

struct MinHeapNode* newMinHeapNode(int v,int key);
int isInMinHeap(struct MinHeap *minHeap,int v);
struct MinHeap* createMinHeap(int capacity);
void swapMinHeapNode(struct MinHeapNode** a, struct MinHeapNode** b);
void minHeapify(struct MinHeap* minHeap,int idx);
int isEmpty(struct MinHeap* minHeap);
struct MinHeapNode* extractMin(struct MinHeap* minHeap);
void decreaseKey(struct MinHeap* minHeap,int v,int key);


#endif