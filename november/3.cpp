#include <bits/stdc++.h>
using namespace std;
void pr(vector<int> &v){
    for(int x:v)
        cout << x << " ";
    cout << endl;
}
void solve(){
    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    int i=0;
    vector<int> previ(n),nexti(n),prevx(n),nextx(n),scount(n);
    int pos = -1;
    for(int i=0;i<n;i++){
        previ[i] = pos;
        if(s[i]=='I')
            pos = i;
    }
    pos = -1;
    for(int i=n-1;i>=0;i--){
        nexti[i] = pos;
        if(s[i]=='I')
            pos = i;
    }
    pos = -1;
    for(int i=0;i<n;i++){
        prevx[i] = pos;
        if(s[i]=='X')
            pos = i;
    }
}
int main(){
    int t;
    // cin >> t;
    t = 1;
    while(t--) solve();
    return 0;
}


// MIM_XII:M
// 10+1-|1-2|
// 10+1-|2-3|


