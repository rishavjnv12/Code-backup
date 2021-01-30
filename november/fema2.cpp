#include <bits/stdc++.h>

using namespace std;
int get_ans(string &s,int k,vector<int> &cnt){
    int ans = 0;
    const int n = s.size();
    int i = 0,j=0;
    while(i<n and j<n){
        if(s[i]=='X'){
            j = i+1;
            i++;
        }
        if(s[j]=='X'){
            i = j+1;
            j++;
        }
        if(s[i]!='I'){
            i++;
            continue;
        }
        if(s[j]!='M'){
            j++;
            continue;
        }
        int p = k+1-abs(i-j)-abs(cnt[i]-cnt[j]);
        // cout << p << " " << i << " " << j << endl;
        if(p>0){
            ans++;
            i++;
            j++;
        }else{
            if(i<j){
                i++;
            }else{
                j++;
            }
        }
    }
    return ans;
}
void solve(){
    int n,k;
    cin >> n >>k;
        // cin >> n >> k;
    string s;
    cin >> s;
    vector<int> cnt(n);
    for(int i=0;i<n;i++){
        if(s[i]==':')
            cnt[i] = 1;
        else 
            cnt[i] = 0;
    }
    for(int i=1;i<n;i++){
        cnt[i]+=cnt[i-1];
    }
    // for(int i=0;i<n;i++){
    //     cout << cnt[i] << " ";
    // }
    // cout << endl;
    s+='X';
    // vector <string> sp;
    // string temp = "";
    // for(char c:s){
    //     if(c == 'X'){
    //         sp.push_back(temp);
    //         temp = "";
    //     }else{
    //         temp+=c;
    //     }
    // }
    int ans = get_ans(s,k,cnt);
    cout << ans << endl;
}
int32_t main(){
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}