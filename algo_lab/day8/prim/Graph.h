#ifndef _GRAPH_H_
#define _GRAPH_H_

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

struct AdjListNode* newAdjListNode(int dest,int weight);
struct Graph* createGraph(int V);
void addEdge(struct Graph* graph,int src,int dest,int weight);


#endif