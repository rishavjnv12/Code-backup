#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n,m;
    scanf("%d%d",&n,&m);
    vector<int>a(n),b(m);
    for(int i=0;i<n;i++) scanf("%d",&a[i]);
    for(int i=0;i<m;i++) scanf("%d",&b[i]);
    bitset<2049> bit;
    bit.set(0);
    for(int i=0;i<=2049;i++){
        bitset<2049> new_bs;
        for(int j=0;j<n;j++){
            if(bit[i]){
                new_bs.set(i|a[j]);
            }
        }
        bit|=new_bs;
    }
    for(int i=0;i<=2049;i++){
        bitset<2049> new_bs;
        for(int j=0;j<m;j++){
            if(bit[i]){
                new_bs.set(i&b[j]);
            }
        }
        bit|=new_bs;
    }
    // for(int i=0;i<=2049;i++)
    //     if(bit[i])
    //         cout << i << " ";
    // cout << endl;
    cout << bit.count() << endl;
}
int main(){
    int t;
    scanf("%d",&t);
    while(t--) solve();
    return 0;
}