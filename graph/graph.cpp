#include <bits/stdc++.h>
#define cout(x) cout<<x<<endl;
using namespace std;
class Graph{
    private:
        vector<vector<int>>g;
        int edges;
        int vertex;
        void dfsUtil(vector<bool>&,int at);
    public:
        void addEdge(int l,int r);
        int edge_count();
        int vertex_count();
        void print_adjacency_list();
        void dfs(int source);
        void bfs(int source);
        Graph(int n);
        Graph();
};
Graph::Graph(){
    vector<vector<int>> temp(100);
    this->g=temp;
    this->edges=0;
    this->vertex=99;
}
Graph::Graph(int n) {
    vector<vector<int>> temp(n);
    this->g=temp;
    this->edges=0;
    this->vertex=n-1;
}
void Graph::addEdge(int l,int r){
    if(l>vertex or r>vertex){
        cout<<"Invalid edge"<<endl;
    }else{
        vector<int>::iterator it1=upper_bound(g[l].begin(), g[l].end(),r);
        g[l].insert(it1,r);
        vector<int>::iterator it2=upper_bound(g[r].begin(), g[r].end(),l);
        g[r].insert(it2,l);
        edges++;
    }
}
int Graph::edge_count(){
    return edges;
}
int Graph::vertex_count(){
    return vertex+1;
}
void Graph::print_adjacency_list(){
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
void Graph::dfs(int source){
    vector<bool>visited(vertex+1,false);
    dfsUtil(visited,source);
    cout<<endl;
}
void Graph::dfsUtil(vector<bool>& visited,int at){
    if(visited[at])
        return;
    visited[at] = true;
    cout<<at<<" ";
    for(int i=0;i<g[at].size();i++){
        dfsUtil(visited,g[at][i]);
    }
}
void Graph::bfs(int source){
    vector<bool>visited(vertex+1,false);
    queue<int> q;
    q.push(source);
    while(!q.empty()){
        int c=q.front();
        q.pop();
        if(visited[c]==false)
            cout<<c<<" ";
        visited[c] = true;
        for(int i=0;i<g[c].size();i++){
            if(visited[g[c][i]]==false){
                q.push(g[c][i]);
            }
        }
    }
    cout<<endl;
}


void addsomeedges(Graph& g,int n){
    for(int i=0;i<n;i++){
        int l,r;
        //cout<<"Enter edge["<<i<<"]: ";
        cin>>l>>r;
        g.addEdge(l,r);
    }
}
int main(){
    Graph myg(13);
    addsomeedges(myg,15);
    myg.dfs(0);
    myg.print_adjacency_list();
    cout<<myg.vertex_count()<<endl;
    cout<<myg.edge_count()<<endl;
    myg.bfs(10);
   
    return 0;
}