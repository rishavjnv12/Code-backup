#include <bits/stdc++.h>
using namespace std;
string max(const string a,const string b){
    return a.size() > b.size() ? a:b;
}

// string largest(string s,int i,int j){
//     if(i>j){
//         return "";
//     }
//     if(i==j){
//         return to_string(s[i]);
//     }
//     if(s[i]==s[j]){
//         return s[i]+largest(s,i+1,j-1)+s[j];
//     }else{
//         return max(largest(s,i+1,j),largest(s,i,j-1));
//     }
// }

int main(){
    string s;
    cin>>s;
    // printf("%c ",s[0]);
    // cout<<largest(s,0,s.length()-1)<<endl;
    return 0;
}