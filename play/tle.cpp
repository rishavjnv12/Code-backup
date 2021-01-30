#include <bits/stdc++.h>
using namespace std;
long long ans = 0;
int main(){
    vector<long long> a(1e8);
    iota(a.rbegin(),a.rend(),1);
    for(auto x:a)
        ans+=x;
    cout << ans << "\n";
    return 0;
}