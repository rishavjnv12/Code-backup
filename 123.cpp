#include <bits/stdc++.h>
using namespace std;
bool fun(string &s,int i){
    if (i == 0) 
        return true; 
    if (s[i - 1] == '-') 
        return false; 
    return true; 
}
vector<int> final(string &s){
    const int n = s.length();
    stack<bool> stk;
    vector<int> ans(26,0);
    stk.push(true);
    for(int i=0;i<n;i++){
        char c = s[i];
        if(c == '+' or c=='-')
            continue;
        else if(c == '('){
            if(fun(s,i)==1)
                stk.push(stk.top());
            else 
                stk.push(!stk.top());
        } else if(s[i]==')'){
            stk.pop();
        } else {
            if(stk.top()==true)
                ans[c-'a'] += fun(s,i)?1:-1;
            else ans[c-'a'] -= fun(s,i)?1:-1;
        }
    }
    return ans;
}
bool areSame(string a,string b){
    auto ans1 = final(a);
    auto ans2 = final(b);
    for(int i=0;i<26;i++)
        if(ans1[i]!=ans2[i])
            return false;
    return true;
}
int main(){
    string a = "-(a+b+c)";
    string b = "-a-b-c";
    auto a1 = final(b);
    for(int x:a1){
        cout << x << " ";
    }
    cout << endl;
    cout << areSame(a,b) << endl;
    return 0;
}