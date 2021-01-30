#include <bits/stdc++.h>
using namespace std;
bool is_pos(string &s,int len,int k){
    int a = 0,b = 0;
    for(int i=0;i<len;i++){
        if(s[i] == 'a') a++;
        else b++;
    }
    if(min(a,b)<=k)
        return true;
    for(int i=len;i<(int)s.size();i++){
        if(s[i-len]=='a') a--;
        else b--;
        if(s[i] == 'a') a++;
        else b++;
        if(min(a,b)<=k){
            return true;
        }
    }
    return false;
}
int main(){
    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    // vector<int> a_cnt(n),b_cnt(n);
    // for(int i=0;i<n;i++){
    //     if(i==0){
    //         if(s[i]=='a'){
    //             a_cnt[0] = 1;
    //             b_cnt[0] = 0;
    //         }else{
    //             a_cnt[0] = 0;
    //             b_cnt[0] = 1;
    //         }
            
    //     }else if(s[i] == 'a'){
    //         a_cnt[i] = 1+a_cnt[i-1];
    //         b_cnt[i] = b_cnt[i-1];
    //     }else{
    //         a_cnt[i] = a_cnt[i-1];
    //         b_cnt[i] = 1 + b_cnt[i-1];
    //     }
    // }

    int l = 0,r = n;
    int ans;
    while(l<=r){
        int mid = l+(r-l)/2;
        bool check = is_pos(s,mid,k);
        if(check){
            ans = mid;
            l = mid+1;
        }else{
            r = mid-1;
        }
    }
    // cout << is_pos(s,7,1) << endl;
    cout << ans << endl;
    return 0;
}