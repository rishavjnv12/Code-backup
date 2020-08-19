#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "Graph.h"
#include "MinHeap.h"

#define true 1
#define false 0

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