#include <bits/stdc++.h>
#define int long long
#define cout(x) std::cout<<x<<'\n'
inline int fun(int n,int k){return (k>=n)?(k-n):(((n-k)%2!=0));}
int32_t main(){
    int t;
    std::cin>>t;
    while(t--){       
        int n,k;
        std::cin>>n>>k;
        cout(fun(n,k));
    }
    return 0;
}