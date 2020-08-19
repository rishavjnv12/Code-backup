#include <bits/stdc++.h>
#define cout(x) cout<<x<<"\n"
#define pr(x) cout<<x<<" "
#define int long long
using namespace std;
int32_t main(){
    vector<int>v={1,5,1,9,16,4,7};
    vector<int>m(v.size());
    for(size_t i=0,mul=1;i<m.size();i++){
        mul*=v[i];
        m[i]=mul;
    }
    for(size_t i=0;i<v.size();i++){
        pr(m[i]);
    }
    return 0;
}