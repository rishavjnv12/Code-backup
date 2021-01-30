#include <bits/stdc++.h> 
#define int long long
const int mod = 1e9+7;
using namespace std;
bool solve(){
    int n;
    cin >> n;
    vector<int> a(2*n);
    for(int i=0;i<2*n;i++){
        cin >> a[i];
    }
    
    for(int x:a){
        if(x&1) return false;
    }
    map<int,int> mp;
    vector<int> temp;
    for(int x:a)
        mp[x]++;
    for(auto p:mp)
        if(p.second!=2)
            return false;
    for(auto p:mp){
        for(int i=0;i<p.second/2;i++)
            temp.push_back(p.first);
    }
    a = temp;
    sort(a.begin(),a.end());
    assert(a.size() == n);
    int sum = 0;
    for(int &x:a) x/=2;
    for(int i=n-1;~i;i--){
        a[i]-=sum;
        // cout << a[i] << " ";
        if(a[i]<=0 or a[i]%(i+1)) return false;
        sum+=(a[i]/(i+1));
    }
    return true;
}

int32_t main(){
    int t;
    ios_base::sync_with_stdio(true);
    cin.tie(0);
    cin >> t;
    for(int i=1;i<=t;i++) {
        // cout << "CASE #:" << i << ":\n";
        if(solve()) puts("YES");
        else puts("NO");
    }
    return 0;
}