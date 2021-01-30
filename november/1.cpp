#include <bits/stdc++.h>

using namespace std;



void solve(){
    int n;
    cin >> n;
    vector<int> d(n);
    for(int &x:d) cin >> x;
    int upto = (1<<n);
    
    int diff = INT_MAX,ans = INT_MIN;
    for(int i=0;i<upto;i++){
        int sum1 = 0,sum2 = 0;
        for(int j=0;j<n;j++){
            if(i&(1<<j))
                sum1+=d[j];
            else 
                sum2+=d[j];
        }
        if(diff > abs(sum1-sum2)){
            diff = abs(sum1-sum2);
            ans =  max(sum1,sum2);
        }
    }
    cout << ans << endl;
}
int main(){
    
    // int t;
    // cin >> t;
    // while(t--) solve();
    return 0;
}

