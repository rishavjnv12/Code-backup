#include <bits/stdc++.h>
using namespace std;

int get_edge_weight(vector<int> a,vector<int> b){
    int n = a.size();
    int ans = 0;
    for(int i=0;i<n;i++){
        ans+=abs(a[i]-b[i]);
    }
    return ans;
}
int main() {
	int n,d;
	cin>>n>>d;
	vector<vector<int>> g(n,vector<int> (d));
	for(int i=0;i<n;i++){
	    for(int j=0;j<d;j++)
	        cin>>g[i][j];
	}
	vector<vector<int>> graph(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            graph[i][j] = get_edge_weight(g[i],g[j]);
        }
    }
    
	return 0;
}
