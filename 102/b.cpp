#include <bits/stdc++.h> 
#define int long long
#define all(x) x.begin(),x.end()
const int mod = 1e9+7;
using namespace std;
string add(string& s,int x){
    string ans = "";
    while(x--) ans+=s;
    return ans;
}
void solve(){
    string s,t;
    cin >> s;
    cin >> t;
    if(s.length() > t.length())
        swap(s,t);
    const int n = s.length();
    int i=0;
    while(i<n and s[i]==t[i]) i++;
    if(i<n){
        cout << -1 << endl;
        return;
    }
    const int m = t.length();
    int lcm = m*n/__gcd(m,n);
    s = add(s,lcm/n);
    t = add(t,lcm/m);
    if(s == t){
        cout << s << endl;
    }else{
        cout << -1 << endl;
    }
}

int32_t main(){
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}