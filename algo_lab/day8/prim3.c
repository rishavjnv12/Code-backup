#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define true 1
#define false 0


struct AdjListNode{
    int dest;
    int weight;
    struct AdjListNode* next;
};

struct AdjList{
    struct AdjListNode* head;
};

struct Graph{
    int V;
    struct AdjList* array;
};

struct AdjListNode* newAdjListNode(int dest,int weight){
    struct AdjListNode* newNode = (struct AdjListNode*)malloc(sizeof(struct AdjListNode));
    newNode->dest = dest;
    newNode->weight = weight;
    newNode->next = NULL;
    return newNode;
}

struct Graph* createGraph(int V){
    struct Graph *graph=(struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->array = (struct AdjList*)malloc(V*sizeof(struct AdjList));
    for(int i=0;i<V;i++){
        graph->array[i].head = NULL;
    }
    return graph;
}

void addEdge(struct Graph* graph,int src,int dest,int weight){
    struct AdjListNode* newNode = newAdjListNode(dest,weight);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    newNode=newAdjListNode(src,weight);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

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
void printArr(int arr[],int n){
    for(int i=1;i<n;i++){
        printf("%d - %d\n",arr[i],i);
    }
}

void PrimMST(struct Graph* graph){
    int V=graph->V;
    int parent[V];
    int key[V];

    struct MinHeap* minHeap=createMinHeap(V);
    for(int v=1;v<V;v++){
        parent[v]=-1;
        key[v]=INT_MAX;
        minHeap->array[v] = newMinHeapNode(v, key[v]); 
		minHeap->pos[v] = v; 
    }
    key[0] = 0; 
	minHeap->array[0] = newMinHeapNode(0, key[0]); 
	minHeap->pos[0] = 0; 
    minHeap->size = V; 
    while(!isEmpty(minHeap)){
        struct MinHeapNode* minHeapNode = extractMin(minHeap); 
        int u=minHeapNode->v;
        struct AdjListNode* pCrawl = graph->array[u].head; 
		while (pCrawl != NULL) { 
			int v = pCrawl->dest;
            if (isInMinHeap(minHeap, v) && pCrawl->weight < key[v]) { 
				key[v] = pCrawl->weight; 
				parent[v] = u; 
				decreaseKey(minHeap, v, key[v]); 
			} 
			pCrawl = pCrawl->next;
        }
    }
    printArr(parent,V);
}

int main(){
    int V = 9; 
	struct Graph* graph = createGraph(V); 
	addEdge(graph, 0, 1, 4); 
	addEdge(graph, 0, 7, 8); 
	addEdge(graph, 1, 2, 8); 
	addEdge(graph, 1, 7, 11); 
	addEdge(graph, 2, 3, 7); 
	addEdge(graph, 2, 8, 2); 
	addEdge(graph, 2, 5, 4); 
	addEdge(graph, 3, 4, 9); 
	addEdge(graph, 3, 5, 14); 
	addEdge(graph, 4, 5, 10); 
	addEdge(graph, 5, 6, 2); 
	addEdge(graph, 6, 7, 1); 
	addEdge(graph, 6, 8, 6); 
	addEdge(graph, 7, 8, 7); 
	PrimMST(graph); 
    return 0;
}