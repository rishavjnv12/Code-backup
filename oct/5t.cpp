/* 

    MAJOR PART OF THIS CODE IS INSPIRED/COPIED BY THE FOLLOWING PUBLICLY AVAILABLE SOURCE
    
    https://www.geeksforgeeks.org/prims-minimum-spanning-tree-mst-greedy-algo-5/
    PUBLICATION DATE:27-07-2020

    SO, ACCORDING TO POINT 7 OF CODE OF CONDUCT,I AM NOT VIOLATING ANY RULES.
    
*/



#include <bits/stdc++.h>
using namespace std;
int maxKey(vector<int> key, vector<bool> mstSet){ 
    int n = key.size();
	int mx = INT_MIN, max_idx; 

	for (int v = 0; v < n; v++){
		if (mstSet[v] == false && key[v] > mx){
			mx = key[v];
            max_idx = v; 
        }
    }
	return max_idx; 
}

int prims_algo(vector<vector<int>> graph){
    int n = graph.size();
    vector<int> parent(n);
    vector<int> key(n,INT_MIN);
    vector<bool> mstSet(n,false);

    key[0]=0;
    parent[0]=-1;

    int count = 0;
    while(count<n-1){
        int u = maxKey(key,mstSet);
        mstSet[u]=true;

        for(int v = 0;v<n;v++){
            if(graph[u][v] and mstSet[v] == false and graph[u][v] > key[v]){
                parent[v] = u;
                key[v]=graph[u][v];
            }
        }
        count++;
    }
    int ans = 0;
    for(int i=1;i<n;i++){
        ans+=graph[i][parent[i]];
    }
    return ans;
}

int32_t main(){
    int n,d;
    scanf("%d%d",&n,&d);
    vector<vector<int32_t>> g(n,vector<int32_t>(d));
    vector<vector<int>> graph(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<d;j++){
            scanf("%d",&g[i][j]);
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            auto a = g[i];
            auto b = g[j];
            int weight = 0;
            for(int i=0;i<d;i++){
                weight+=abs(a[i]-b[i]);
            }
            graph[i][j] = weight;
        }
    }
    printf("%d\n",prims_algo(graph));
    return 0;
}