#include <bits/stdc++.h>

using namespace std;
vector<int> t[9];
int level[9];
int parent[9];
void dfs(int node,int curr_level){
    level[node]=curr_level;
    // cout<<node<<" ";
    for(int child:t[node]){
        if(level[child]==INT_MIN){
            parent[child]=node;
            dfs(child,curr_level+1);
        }
    }
}
void add_edge(int a, int b){
    t[a].push_back(b);
    t[b].push_back(a);
}
int lca(int a,int b){
    if(level[a]>level[b])
        swap(a,b);
    int d=level[b]-level[a];
    while(d>0){
        b=parent[b];
        d--;
    }
    if(a==b) return a;
    while(parent[a]!=parent[b]){
        a=parent[a],b=parent[b];
    }
    return parent[a];
}
int main(){
    
    add_edge(1,2);
    add_edge(4,2);
    add_edge(3,2);
    add_edge(3,7);
    add_edge(7,8);
    add_edge(4,5);
    add_edge(4,6);
    for(int i=0;i<9;i++){
        level[i]=INT_MIN;
    }
    // for(int i=1;i<9;i++){
    //     cout<<i<<":";
    //     for(int j=0;j<t[i].size();j++){
    //         cout<<t[i][j]<<",";
    //     }
    //     cout<<endl;
    // }
    dfs(1,0);
    cout<<endl;
    // for(int i=1;i<9;i++){
    //     cout<<"parent["<<i<<"] = "<<parent[i]<<endl;
    // }
    // for(int i=1;i<9;i++)
    //     cout<<"level["<<i<<"] = "<<level[i]<<endl;
    cout<<lca(3,4)<<endl;
    cout<<lca(3,5)<<endl;
    cout<<lca(7,8)<<endl;

    return 0;
}