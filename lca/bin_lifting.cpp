#include <bits/stdc++.h>
#define maxN 3

using namespace std;
vector<int> t[9];
int level[9];
int parent[9];
int LCA[9][maxN+1];
void dfs(int node,int par,int curr_level){
    level[node] = curr_level;
    LCA[node][0]=par;
    for(int child:t[node]){
        if(child!=par){
            dfs(child,node,curr_level+1);
        }
    }
}
void initLCA(){
    for(int i=1;i<9;i++){
        for(int j=0;j<=maxN;j++){
            LCA[i][j]=-1;
        }
    }
    dfs(1,0,-1);

    for(int j=1;j<=maxN;j++){
        for(int i=1;i<9;i++){
            int par=LCA[i][j-1];
            if(par!=-1){
                LCA[i][j]=LCA[par][j-1];
            }
        }
    }
}

int get_lca(int a,int b){
    if(level[a] > level[b])
        swap(a , b);
	
	int d = level[b] - level[a];
	int f = 0;
	while(d>0){
		if(d & 1)
            b = LCA[b][f];
		
		d >>= 1;
		f++;
	}
	
	if(a == b) return a;
	
	for(int j=maxN-1;j>=0;j--){
	    if(LCA[a][j] != -1 && (LCA[a][j] != LCA[b][j])){
            a = LCA[a][j];
            b = LCA[b][j];
        }
	}       
	
	return LCA[a][0];
}
void add_edge(int a, int b){
    t[a].push_back(b);
    t[b].push_back(a);
}

int main(){
    
    add_edge(1,2);
    add_edge(4,2);
    add_edge(3,2);
    add_edge(3,7);
    add_edge(7,8);
    add_edge(4,5);
    add_edge(4,6);
    // for(int i=1;i<9;i++){
    //     cout<<i<<":";
    //     for(int j=0;j<t[i].size();j++){
    //         cout<<t[i][j]<<",";
    //     }
    //     cout<<endl;
    // }
    cout<<endl;
    initLCA();
    // for(int i=1;i<9;i++){
    //     cout<<"parent["<<i<<"] = "<<parent[i]<<endl;
    // }
    // for(int i=1;i<9;i++)
    //     cout<<"level["<<i<<"] = "<<level[i]<<endl;
    cout<<get_lca(3,4)<<endl;
    cout<<get_lca(3,5)<<endl;
    cout<<get_lca(7,8)<<endl;

    return 0;
}