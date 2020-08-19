// https://www.spoj.com/problems/UPDATEIT/

#include <bits/stdc++.h>
#define ios ios_base::sync_with_stdio(false);cin.tie(NULL)
#define int long long
#define cout(x) cout<<x<<endl
#define cin(x) cin>>x
#define cin2(x,y) cin>>x>>y
#define cin3(x,y,z) cin>>x>>y>>z
#define debug(x) cout<<x<<endl
#define nl cout<<endl

using namespace std;

int bit[10001];
int n;
void add(int idx, int val) {
    for (++idx; idx <= n; idx += idx & -idx)
        bit[idx] += val;
}

int point_query(int idx) {
    int ret = 0;
    for (++idx; idx > 0; idx -= idx & -idx)
        ret += bit[idx];
    return ret;
}

int32_t main(){
    ios;
    int t;
    cin>>t;
    while(t--){
        int u;
        cin>>n>>u;
        while(u--){
            int l,r,val;
            cin>>l>>r>>val;
            add(l,val);
            add(r+1,-val);
        }
        int q;
        cin>>q;
        while(q--){
            int i;
            cin>>i;
            cout<<point_query(i)<<endl;
        }
        memset(bit, 0, sizeof(bit));
    }
    return 0;
}