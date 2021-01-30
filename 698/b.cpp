#include <bits/stdc++.h> 
#define int long long
const int mod = 1e9+7;
using namespace std;
void solve(){
    int n,l;
    cin >> n >> l;
    vector<int> a(n);
    for(int i=0;i<n;i++)
        cin >> a[i];
    map<int,int> st;
    for(int i=1;i<=9;i++){
        st[(l*i)%10] = i;
    }
    for(int a:a){
        if (a % l == 0) puts("YES");
        else {
            int r = a % l + l * 10;
            if (a >= r) puts("YES");
            else {
                bool fg = false;
                for (int i = 1; i <= 100; i ++) {
                    int r = a - l * i;
                    if (r >= 0 && r % 10 == 0) fg = true;
                }
                if (fg) puts("YES");
                else puts("NO");
            }
        }
    } 
}


int32_t main(){
    int t;
    ios_base::sync_with_stdio(true);
    cin.tie(0);
    cin >> t;
    while(t--) solve();
    return 0;
}