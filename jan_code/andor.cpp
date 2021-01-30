#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n,m;
    scanf("%d%d",&n,&m);
    vector<int>a(n),b(m);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    for(int i=0;i<m;i++) scanf("%d",&b[i]);
    bitset<2048> bit;
    bit.set(0);
    while(true){
        for(int i=0;i<=2048;i++){
            bitset<2048> new_bs;
            for(int j=0;j<n;j++){
                if(bit[i]){
                    new_bs.set(i|a[j]);
                }
            }
            bit|=new_bs;
        }
        for(int i=0;i<=2048;i++){
            bitset<2048> new_bs;
            for(int j=0;j<m;j++){
                if(bit[i]){
                    new_bs.set(i&b[j]);
                }
            }
            if(bit == new_bs)
                break;
            bit|=new_bs;
        }
    }
    cout << bit.count() << endl;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--) solve();
    return 0;
}