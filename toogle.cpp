#include <bits/stdc++.h> 
const int mod = 1e9+7;
using namespace std;
string solve(string &s){
    for(char &c:s) 
        c^=32;
    return s;
}

int32_t main(){
    int t;
    scanf("%d",&t);
    while(t--) solve();
    return 0;
}