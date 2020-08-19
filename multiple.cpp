// https://codeforces.com/problemset/problem/1342/D
#include <bits/stdc++.h>
#define ios ios_base::sync_with_stdio(false);cin.tie(NULL)
// #define int long long
#define mod 1000000007
#define INF 1000000000
#define endl '\n'
#define cout(x) cout<<x<<'\n'
#define debug(x) cout<<x<<'\n\n'
#define cin(x) cin>>x
#define cin2(x,y) cin>>x>>y
#define cin3(x,y,z) cin>>x>>y>>z


using namespace std;

int32_t main(){
    ios;
    int n,k;
    cin2(n,k);
    vector<int> a(n),c(k+1);
    for(int i=0;i<n;i++){
        cin(a[i]);
    }
    for(int i=1;i<=k;i++){
        cin(c[i]);
    }
    sort(a.begin(),a.end());
    /**************************************************************/
	
	sort(a.begin(), a.end(), greater<int>());
	int ans = 0;
	for (int i = k, g = 0; i >= 1; --i){
		while (g < n && a[g] == i) ++g;
		ans = max(ans, (int)ceil((float)g / c[i]));
	}
	vector<vector<int>> res(ans);
	for(int i=0;i<n;i++) 
        res[i % ans].push_back(a[i]);
	
	printf("%d\n", ans);
	for(int i=0;i<ans;i++){
		printf("%d", int(res[i].size()));
		for (auto it : res[i])
			printf(" %d", it);
		puts("");
	}

    return 0;
}