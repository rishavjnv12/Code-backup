#include <bits/stdc++.h>

using namespace std;
int lcs(string s1,string s2,int m,int n){
    if(m==0 or n==0)
        return 0;
    if(s1[m]==s2[n])
        return 1+lcs(s1,s2,m-1,n-1);
    else{
        return max(lcs(s1,s2,m-1,n),lcs(s1,s2,m,n-1));
    }
}
int main(){
    string a="ajhhbhgycdekhh",b="fyufabyfyucygyudvhgfe";
    int ans=lcs(a,b,a.size(),b.size());
    cout<<ans<<endl;
    return 0;
}