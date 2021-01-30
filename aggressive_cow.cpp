#include <bits/stdc++.h>
using namespace std;
int count_cow(vector<int> &a,int k){
    const int n = a.size();
    if(n==0) 
        return 0;
    int ans = 1;
    int curr = a[0];
    for(int i=1;i<n;i++){
        if(a[i]>=(curr+k)){
            ans++;
            curr = a[i];
        }
    }
    return ans;
}
void solve(){
    int n,c;
    cin >> n >> c;
    vector<int> stall(n);
    for(int &x:stall) cin >> x;
    sort(stall.begin(),stall.end());
    int lo = 0;
    int hi = 1000000000;
    int ans;
    while(lo<=hi){
        int mid = lo+(hi-lo)/2;
        int count = count_cow(stall,mid);
        if(count >= c){
            ans = mid;
            lo = mid+1;
        }else{
            hi = mid-1;
        }
    }
    cout << ans << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--) solve();    
    return 0;
}

