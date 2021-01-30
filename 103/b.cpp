#include <bits/stdc++.h> 
#define int long long
const int mod = 1e9+7;
using namespace std;
bool check(vector<int> &a,int inc,int k){
    a[0]+=inc;
    int curr_price  = a[0];
    for(int i=1;i<a.size();i++){
        int inf = a[i];
        // double perc = inf/curr_price;
        if(inf*100 > k*curr_price){
            a[0]-=inc;
            return false;
        }
        else curr_price+=a[i];
    }
    a[0]-=inc;
    return true;
}
void solve(){
    int n,k;
    cin >> n >> k;
    vector<int> p(n);
    for(int i=0;i<n;i++){
        cin >> p[i];
    }
    int r = *max_element(p.begin(),p.end());
    r*=1000;
    int l = 0;
    int ans;
    while(l<=r){
        int mid = (l+r)/2;
        if(check(p,mid,k)){
            ans = mid;
            r = mid-1;
        }else{
            l = mid+1;
        }
    }
    cout << ans << endl;
}

int32_t main(){
    int t;
    ios_base::sync_with_stdio(true);
    cin.tie(0);
    cin >> t;
    while(t--) solve();
    return 0;
}