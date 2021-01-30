#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9+7;
#define int long long
inline int sub(int a,int b){
    return (a-b+mod)%mod;
}
int32_t main(){
    for(int i=0;i<4;i++){
        for(int j=0;j<5;j++){
            cout << i << "-" << j << sub(i,j) << endl;
        }
    }
    return 0;
}