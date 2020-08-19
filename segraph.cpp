#include <bits/stdc++.h>
#define ios ios_base::sync_with_stdio(false);cin.tie(NULL)
#define int long long
#define cout(x) cout<<x<<endl
#define cin(x) cin>>x
#define cin2(x,y) cin>>x>>y
#define cin3(x,y,z) cin>>x>>y>>z
using namespace std;

bool isBipartite(vector<vector<int>>G, int src) 
{  
    int V=G.size();
	int colorArr[V]; 
	for (int i = 0; i < V; ++i) 
		colorArr[i] = -1; 
	colorArr[src] = 1;  
	queue <int> q; 
	q.push(src); 
	while (!q.empty()){ 
		int u = q.front(); 
		q.pop(); 
		if (G[u][u] == 1) 
		return false; 
		for (int v = 1; v <= V; ++v) 
		{ 
			if (G[u][v] && colorArr[v] == -1){
				colorArr[v] = 1 - colorArr[u]; 
				q.push(v); 
			} 
			else if (G[u][v] && colorArr[v] == colorArr[u]) 
				return false; 
		} 
	}
	return true;
}


int32_t main()
{
    ios;
    int t;
    cin>>t;
    while(t--){
        int n,q;
        cin2(n,q);
        vector<vector<int>>g(n,vector<int>(n,0));
    
        while(q--){
            int x,u,v;
            cin3(x,u,v);
            if(x==1){
                g[u-1][v-1]=1;
                g[v-1][u-1]=1;
            }else{
                if(isBipartite(g,u-1))
                    cout("Yes");
                else cout("No");
            }
        }
    }
    return 0;
}