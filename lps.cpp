#include <bits/stdc++.h>
using namespace std;
string lps(string s){
    const int n = s.size();
    bool dp[n][n];
    memset(dp,false,sizeof dp);
    for(int i=0;i<n;i++)
        dp[i][i] = true;
    int mx = 1;
    pair<int,int> ans = {0,0};
    for(int i=n-1;i>=0;i--){
        for(int j=i+1;j<n;j++){
            if(s[i]==s[j] and (dp[i+1][j-1]==true or j-i<3))
                dp[i][j] = true;
            if(dp[i][j]){
                if(mx < j-i+1){
                    mx = j-i+1;
                    ans = {i,j};
                }
            }
        }
    }
    return s.substr(ans.first,ans.second-ans.first+1);
}
int main(){
    string s = "forgeekskeegfor";
    cout << lps(s) << endl;
    return 0;
}