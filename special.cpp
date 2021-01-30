#include <bits/stdc++.h> 
// #define int int64_t
const int mod = 1e9+7;
using namespace std;

bool is_possible(vector<int> &a,int k,int b){
    const int n = a.size();
    int curr_sum = 0;
    for(int i=0;i<k;i++){
        curr_sum +=a[i];
    }
    if(curr_sum > b)
        return false;
    for(int i=k;i<n;i++){
        curr_sum -= (a[i-k]);
        curr_sum += a[i];
        if(curr_sum > b)
            return false;
    }
    return true;
}


int solve(vector<int> &a,int b){
    int l = 1,r = a.size();
    int ans;
    while(l<=r){
        int mid = (l+r)/2;
        bool check = is_possible(a,mid,b);
        if(check){
            ans = mid;
            l = mid+1;
        }else{
            r = mid-1;
        }
    }
    return ans;
}

void solve(){
    int n;
    cin >> n;
    int b;
    cin >> b;
    vector<int> a(n);
    for(int &x:a) cin >> x;
    
    cout << solve(a,b)<< endl;
}

int32_t main(){
    int t;
    scanf("%d",&t);
    while(t--) solve();
    return 0;
}