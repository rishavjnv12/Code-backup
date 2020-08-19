#include <bits/stdc++.h>

using namespace std;
int mul(string s){
    int ans=1;
    for(int i=0;i<s.size();i++){
        ans*=(s[i]-'0');
    }
    return ans;
}
bool fun(int n){
    string num=to_string(n);
    int digit=num.size();
    set <int> st;
    for(int i=1;i<=num.size();i++){
        for(int j=0;j<=digit-i;j++){
            string temp;
            temp=num.substr(j,i);
            int x=mul(temp);
            if(st.find(x)!=st.end())
                return false;
            else
                st.insert(x);
        }
    }
    return true;
}
int main(){
    int n;
    cin>>n;
    cout<<fun(n)<<endl;
    return 0;
}