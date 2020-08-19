#include <bits/stdc++.h>
#define ios ios_base::sync_with_stdio(false);cin.tie(NULL)
#define int long long
using namespace std;
const int MAX=2e5+1;
int n,q;
int a[MAX],h[MAX];


int left(int idx,int target,int ans){
    ans+=a[target];
    if(idx==target){
        return ans;
    }else{
        if(h[idx-1]>=h[idx]){
            return -1;
        }else{
            return left(idx-1,target,ans);
        }
    }
}

int right(int idx,int target,int ans){
    ans+=a[target];
    if(idx==target){
        return ans;
    }else{
        if(h[idx+1]>=h[idx]){
            return -1;
        }else{
            return right(idx+1,target,ans);
        }
    }
}

int32_t main(){
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>h[i];
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    
    while(q--){
        int qt,b,c;
        cin>>qt>>b>>c;
        if(qt==1){
            a[b]=c;
        }else{
            if(c>=b){
                int ans=(right(b,c,0));
                cout<<ans<<endl;
            }else{
                int ans=(left(b,c,0));
                cout<<ans<<endl;
            }
        }
    }
    return 0;
}