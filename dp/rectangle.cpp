#include <bits/stdc++.h>
using namespace std;
int minPathSum(vector<vector<int>>& g){
    int m=g.size();
    int n=g[0].size();
    for(int i=1;i<m;i++){
        if(g[i][])
    }
    for(int i=1;i<n;i++){
    }
    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            dp[i][j]=min(g[i][j]+dp[i][j-1],g[i][j]+dp[i-1][j]);
            // dp[i][j]=g[i][j]+min(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[m-1][n-1];
}
int main(){
    vector<vector<int>> g={{1,3,1},{1,5,1},{4,2,1}};
    printf("%d\n",minPathSum(g));
    return 0;
}