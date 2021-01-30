#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n,m;
    cin >> n >> m;
    multiset<int> st;
    while(n--){
        int temp;
        cin >> temp;
        st.insert(temp);
    }
    while(m--){
        int temp;
        cin >> temp;
        st.insert(temp);
    }
    vector<int> s;
    for(int i:st) 
        s.push_back(i);
    int sz = s.size();
    float ans;
    if(sz&1)
        ans = s[sz/2];
    else
        ans = (s[sz/2 - 1] + s[sz/2])/2.0;
    
    printf("%.1f\n",ans);
}
int main(){
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}