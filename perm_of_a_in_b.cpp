#include <bits/stdc++.h> 
#define int int64_t
const int mod = 1e9+7;
using namespace std;
int solve(string a, string b){
    const int n = a.size(), m = b.size();
    vector<int> freq(26),curr(26);
    int ans = 0;
    for(int i=0;i<n;i++) {
        freq[a[i]-'a']++;
        curr[b[i]-'a']++;
    }
    if(freq == curr)
        ans++;
    for(int i=n;i<m;i++){
        curr[b[i-n]-'a']--;
        curr[b[i]-'a']++;
        if(curr == freq)
            ans++;
    }
    return ans;
}

int32_t main(){
    string a,b;
    cin >> a >> b;
    cout << solve(a,b) << endl;
    
    return 0;
}