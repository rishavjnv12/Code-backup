#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n,c0,c1,h;
    string s;
    cin >> n >> c0 >> c1 >> h;
    cin >> s;
    int one = 0, zero = 0;
    for(char ch:s){
        if(ch=='1') one++;
        else zero++;
    }
    int ans = one*c1 + zero*c0;
    ans = min({ans,h*one+(one+zero)*c0, zero*h+(one+zero)*c1} );
    cout << ans << endl;
}
int main(){
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}