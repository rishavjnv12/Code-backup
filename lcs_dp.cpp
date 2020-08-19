#include <bits/stdc++.h>

using namespace std;
int lcs(string s1,string s2,int m,int n){
    int L[m+1][n+1];
    for(int i=0;i<=m;i++){
        for(int j=0;j<=n;j++){
            if(i==0 or j==0){
                L[i][j]=0;
            }
            else if(s1[i-1]==s2[j-1])
                L[i][j]=1+L[i-1][j-1];
            else
                L[i][j]=max(L[i-1][j],L[i][j-1]);
        }
    }

    // for(int i=0;i<=m;i++){
    //     for(int j=0;j<=n;j++){
    //         cout<<L[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    return L[m][n];
}
int main(){
    string a="abc",b="fyufabyfyucygyudvhgfe";
    //string a="ab",b="ab";
    // cin>>a>>b;
    int ans=lcs(a,b,a.size(),b.size());
    cout<<ans<<endl;
    return 0;
}