#include <bits/stdc++.h>
#define mod 1000000007
#define INF 1000000000
#define endl '\n'
#define cin(t) cin>>t

using namespace std;
const int BLK = 1200;
const int maxN = 20;

vector<pair<int, int>> ar[1000001];
vector<int> adj[100001];
int val[100001] , tree[200002] , S[100001] , T[100001] , nodeF[100001] , eleF[1000001];
int LCA[100001][maxN] , level[100001] , ans[100001];
int inv[2000001];
int timer,res;

struct query{
    int l,r;
    int lca,idx;
    bool flag;
};

query Q[100001];

void init(){
    int N=1000000;
    ar[1].push_back(make_pair(1,0));
    for(int i=2;i<=N;i++){
        if(ar[i].size()==0){
            ar[i].push_back(make_pair(i,1));
            for(int j=2*i;j<=N;j+=i){
                int count=0;
                int x=j; 
                while(x%i==0){
                    count++;
                    x/=i;
                }
                ar[j].push_back(make_pair(i,count));
            }
        }
    }
    inv[0]=inv[1]=1;
    for(int i=2;i<=2000000;i++){
        inv[i]= (mod - (((mod/i) * 1LL *inv[mod % i])  % mod)) % mod;
    }
}

bool comp(query a,query b){
    int x=a.l/BLK;
    int y=b.l/BLK;

    if(x!=y){
        return x<y;
    }

    return x%2 ? a.r<b.r : a.r > b.r;
}

void reset(int n){
    for(int i=1;i<=n;i++){
        nodeF[i]=0;
        adj[i].clear();
        for(int j=0;j<maxN;j++){
            LCA[i][j]=-1;
        }
    }
    for(int i=1;i<=1000000;i++)
        eleF[i]=0;
}
int addLCA(int lca){
	int newRes = res;
	int ele = val[lca];
	
	for(auto d : ar[ele])
	{
		int pre = eleF[d.first];
		int curr = pre + d.second;
		
		newRes = (newRes * 1LL * (inv[pre + 1])) % mod;
		newRes = (newRes * 1LL * (curr + 1)) % mod;
	}
	
	int x = newRes - res;
	if(x < 0) x +=mod;
	return x;
}
void dfs(int node,int par,int lvl){
    level[node]=lvl;
    LCA[node][0]=par;
    tree[timer]=node;
    S[node]=timer++;

    for(int child:adj[node]){
        if(child!=par)
            dfs(child,node,lvl+1);
    }

    tree[timer]=node;
    T[node]=timer++;
}
void initLCA(int n){
    for(int j=1;j<maxN;j++){
        for(int i=1;i<=n;i++){
            if(LCA[i][j-1]!=-1)
                LCA[i][j]=LCA[LCA[i][j-1]][j-1];
        }
    }
}
int getLCA(int a,int b){

    if(level[a] > level[b]){
        swap(a,b);
    }
	
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
void add(int node){
	node = tree[node];
	nodeF[node]++;
	if(nodeF[node] == 1)
	{
		int ele = val[node];
		for(auto d : ar[ele])
		{
			int pre = eleF[d.first];
			eleF[d.first] += d.second;
			int curr = eleF[d.first];
			
			res = (res * 1LL * (inv[pre + 1])) % mod;
			res = (res * 1LL * (curr + 1)) % mod;
		}
	}
	else
	{
		int ele = val[node];
		for(auto d : ar[ele])
		{
			int pre = eleF[d.first];
			eleF[d.first] -= d.second;
			int curr = eleF[d.first];
			
			res = (res * 1LL * (inv[pre + 1])) % mod;
			res = (res * 1LL * (curr + 1)) % mod;
		}
	}
}
void remove(int node)
{
	node = tree[node];
	nodeF[node]--;
	
	if(nodeF[node] == 1)
	{
		int ele = val[node];
		for(auto d : ar[ele])
		{
			int pre = eleF[d.first];
			eleF[d.first] += d.second;
			int curr = eleF[d.first];
			
			res = (res * 1LL * (inv[pre + 1])) % mod;
			res = (res * 1LL * (curr + 1)) % mod;
		}
	}
	else
	{
		int ele = val[node];
		for(auto  d : ar[ele])
		{
			int pre = eleF[d.first];
			eleF[d.first] -= d.second;
			int curr = eleF[d.first];
			
			res = (res * 1LL * (inv[pre + 1])) % mod;
			res = (res * 1LL * (curr + 1)) % mod;
		}
	}
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,q,a,b,t; 
    cin(t);

    init();

    while(t--){
        cin>>n;
        timer=1;
        res=1;
        reset(n);
        for(int i=1;i<=n-1;i++){
            cin>>a>>b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        for(int i=1;i<=n;i++){
            cin>>val[i];
        }
        dfs(1,-1,0);
        initLCA(n);

        cin>>q;
        for(int i=1;i<=q;i++){
            cin>>a>>b;
            if(S[a]>S[b])
                swap(a,b);
            
            int lca=getLCA(a,b);
            if(a!=lca){
                Q[i].l=T[a];
                Q[i].r=S[b];
                Q[i].flag=1;
                Q[i].lca=lca;
                Q[i].idx=i;
            }else{
                Q[i].l=S[a];
                Q[i].r=S[b];
                Q[i].flag=0;
                Q[i].lca=lca;
                Q[i].idx=i;
            }
        }
        sort(Q+1,Q+q+1,comp);

        int ML=1,MR=0;
        for(int i=1;i<=q;i++){
            int L=Q[i].l;
            int R=Q[i].r;
            int idx=Q[i].idx;
            int lca=Q[i].lca;
            bool flag=Q[i].flag;

            while(MR<R){
                MR++;
                add(MR);
            }
            while(ML>L){
                ML--;
                add(ML);
            }
            while(MR>R){
                remove(MR);
                MR--;
            }
            while(ML<L){
                remove(ML);
                ML++;
            }
            ans[idx] = res;
            if(flag){
                ans[idx] += addLCA(lca);
				if(ans[idx] >= mod)
                    ans[idx] -= mod;
            }

        }
        
        for(int i=1;i<=q;i++){
            cout<<ans[i]<<endl;
        }

    }
    return 0;
}