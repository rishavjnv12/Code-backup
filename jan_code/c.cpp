#include <bits/stdc++.h>
#define int long long
using namespace std;

void solve(){
    int n;
    cin >> n;
    assert(n==1);
    int m;
    cin >> m;
    vector<int> neg,pos;
    while(m--){
        int x;
        cin >> x;
        if(x<0)
            neg.push_back(x);
        else pos.push_back(x);
    }
    int ans = neg.size()*pos.size();
    cout << ans << endl;
}

int32_t main(){
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}