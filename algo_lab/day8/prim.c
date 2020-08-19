#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define true 1
#define false 0
#define INF INT_MAX
#define V 5

int printMST(int parent[], int graph[V][V]) { 
    printf("Edge \tWeight\n"); 
    for (int i = 1; i < V; i++) 
        printf("%d - %d \t%d \n", parent[i], i, graph[i][parent[i]]); 
} 
int minKey(int key[],int mstSet[]){
    int min=INF,min_index;
    for(int i=0;i<V;i++){
        if(mstSet[i]==false && key[i]<min){
            min=key[i];
            min_index=i;
        }
    }
    return min_index;
}
void primMST(int graph[][V]){
    int parent[V]; //arrau to store constructed MST
    int key[V];
    int mstSet[V];
    for(int i=0;i<V;i++){
        key[i]=INF;
        mstSet[i]=false;
    }
    key[0]=0;
    parent[0]=-1;
    for(int count=0;count<V-1;count++){
        int u=minKey(key,mstSet);
        mstSet[u]=true;
        for(int v=0;v<V;v++){
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v]) 
                parent[v] = u, key[v] = graph[u][v];
        }
    }
    printMST(parent, graph);
}


int main(){
    int graph[V][V]={ { 0, 2, 0, 6, 0 }, 
                        { 2, 0, 3, 8, 5 }, 
                        { 0, 3, 0, 0, 7 }, 
                        { 6, 8, 0, 0, 9 }, 
                        { 0, 5, 7, 9, 0 } };

    primMST(graph);
    return 0;
}