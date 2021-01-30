#include <bits/stdc++.h>

using namespace std;
int dp[1001][1001];
int a[1001];
void compute(int n){
    for(int i=1;i<=n;i++){
        vector<int> res;
        for(int j=i; j<=n; j++) {
            auto it = lower_bound(res.begin(), res.end(), a[j]);
            if(it==res.end()) 
                res.push_back(a[j]);
            else *it = a[j];
            dp[i][j] = res.size();
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q,s;
    cin >> n >> q >> s;
    for(int i=1;i<=n;i++) cin >> a[i];
    compute(n);
    vector<int> ans(1,0);
    for(int i=0;i<q;i++){
        int x,y;
        cin >> x >> y;
        int l = (x+s*ans.back()-1)%n + 1;
        int r = (y+s*ans.back()-1)%n + 1;
        if(l>r)
            ans.push_back(dp[r][l]);
        else 
            ans.push_back(dp[l][r]);
    }
    for(int i=1;i<=q;i++)
            cout << ans[i] << endl;
    return 0;
}
