#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n,x,y;
    vector<int> a(n);
    unordered_multiset<int> st;
    int sum = 0;
    bool zero_swap = 0;
    for(int i=0;i<n;i++){
        cin >> a[i];
        st.insert(a[i]);
        sum+=a[i];
        if(sum<=y and sum>=x){
            zero_swap = true;
        }
    }
    if(zero_swap){
        cout << 0 << endl;
        return;
    }
    for(int i=0;i<)
}

int32_t main(){
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}