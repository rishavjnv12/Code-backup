#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    string s;
    cin >> n;
    cin >> s;
    int o=0,z=0,ans=0;
    for(char ch:s){
        if(ch == '1'){
            if(z==0){
                ans++;
                o++;
            }else{
                o++;
                z--;
            }
        }else{
            if(o==0){
                ans++;
                z++;
            }else{
                z++;
                o--;
            }
        }
    }
    cout << ans << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--) solve();
    return  0;
}