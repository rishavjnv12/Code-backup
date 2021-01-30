#include <bits/stdc++.h> 
#define int long long
#define all(x) x.begin(),x.end()
const int mod = 1e9+7;
using namespace std;
void solve(){
    int n,d;
    cin >> n >> d;
    vector<int> a(n);
    for(int i=0;i<n;i++)
        cin >> a[i];
    int ok = true;
    for(int x:a){
        if(x>d){
            ok = false;
            break;
        }
    }
    if(ok){
        cout << "YES" << endl;
        return;
    }
    if(n==1){
        if(a[0]>d){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
        return;
    }
    sort(a.begin(),a.end());
    if(a[0] + a[1] <= d){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
}

int32_t main(){
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}