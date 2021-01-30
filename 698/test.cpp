#include <bits/stdc++.h> 
#define int long long
const int mod = 1e9+7;
using namespace std;
void solve(){
    int n;
    cin >> n;
    vector<int> a;
    for(int i=1;i<=n;i++){
        a.push_back(i);
        a.push_back(-i);
    }
    vector<int> f(2*n);
    for(int i=0;i<2*n;i++){
        int sum = 0;
        for(int x:a){
            sum+=abs(x-a[i]);
        }
        f[i] = sum;
    }
    sort(f.begin(),f.end());
    for(int x:f)
        cout << x << " ";
    cout << endl;
}

int32_t main(){
    int t;
    ios_base::sync_with_stdio(true);
    cin.tie(0);
    cin >> t;
    while(t--) solve();
    return 0;
}