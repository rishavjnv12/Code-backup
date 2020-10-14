#include <bits/stdc++.h>
#define ios ios_base::sync_with_stdio(false);cin.tie(NULL)
#define int int64_t


using namespace std;


int32_t main(){
    ios;
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int> a(n);
        for(int i=0; i<n; i++){
            cin>>a[i];
        }
        int curr = 0;
        int ans = -1;
        for(int i=0; i<n; i++){
            curr += a[i];
            if(curr < k){
                ans = i+1;
                break;
            }
            curr-=k;
        }
        if(ans == -1)
            cout<<n+(curr/k)+1<<endl;
        else
            cout<<ans<<endl;
        

    }
    return 0;
}