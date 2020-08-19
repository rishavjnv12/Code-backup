//directed acyclic graphs
//directed cyclic graphs cannot have any topological ordering
#include <bits/stdc++.h>
using namespace std;
class Graph{
    private:
        vector<vector<int>> g;
        vector<int>topological;
        int vertex;
        int edges;
        void topologicalSortUtil(int,vector<bool>&,stack<int>&);
    public:
        void add_edge(int,int);
        const int edge_count();
        const int vertex_count();
        const void print_adjacency_list();
        void top_sort();
        Graph();
        Graph(int);
};
Graph::Graph(){
    vertex=100;
    edges=0;
    g=vector<vector<int>>(100);
    topological=vector<int>(100);
}

Graph::Graph(int n){
    vertex=n;
    edges=0;
    g=vector<vector<int>>(n);
    topological=vector<int>(n);
}
const int Graph::vertex_count(){
    return vertex;
}
void Graph::add_edge(int source,int target){
    if(source>=vertex or target>=vertex)
        cout<<"Invalid edge"<<endl;
    else{
        vector<int>::iterator it=upper_bound(g[source].begin(), g[source].end(),target);
        g[source].insert(it,target);
    }
}
const int Graph::edge_count(){
    return edges;
}
const void Graph::print_adjacency_list(){
    for(int i=0;i<g.size();i++){
        if(g[i].size()>0){        
            cout<<i<<"->";
            for(int j=0;j<g[i].size();j++){
                cout<<g[i][j]<<" ";
            }
            cout<<endl;
        }
    }
}
void Graph::topologicalSortUtil(int v, vector<bool>&visited,stack<int>& Stack){ 
    visited[v] = true; 
    vector<int>::iterator i; 
    for (i = g[v].begin(); i != g[v].end(); ++i) 
        if (!visited[*i]) 
            topologicalSortUtil(*i, visited, Stack); 
    Stack.push(v); 
} 
void Graph::top_sort(){
    vector<bool>visited(vertex,false);
    stack<int> Stack; 
    for (int i = 0; i < vertex; i++) 
        if (visited[i] == false) 
            topologicalSortUtil(i, visited, Stack); 
    int i=0;
    while (Stack.empty() == false) { 
        topological[i]=Stack.top();
        Stack.pop(); 
        i++;
    } 
    for(auto i:topological){
        cout<<i<<" ";
    }
    cout<<endl;
}
void addsomeedges(Graph& g,int n){
    for(int i=0;i<n;i++){
        int l,r;
        //cout<<"Enter edge["<<i<<"]: ";
        cin>>l>>r;
        g.add_edge(l,r);
    }
}
int main(){
    Graph myg(13);
    addsomeedges(myg,15);
    myg.print_adjacency_list();
    cout<<myg.vertex_count()<<endl;
    cout<<myg.edge_count()<<endl;
    myg.top_sort();
    return 0;
}