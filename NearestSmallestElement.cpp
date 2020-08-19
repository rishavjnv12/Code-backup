#include <bits/stdc++.h>

using namespace std;
vector<int> solve(vector<int> a){
    vector<int> ans;
    stack<int> stk;
    for(int i=0;i<a.size();i++){
        while(!stk.empty() and stk.top()>=a[i])
            stk.pop();
        if(stk.empty())
            ans.emplace_back(-1);
        else 
            ans.emplace_back(stk.top());
        stk.push(a[i]);
    }
    return ans;
}
int main(){
    vector<int> A={4, 5, 2, 10, 8};
    vector<int> ans=solve(A);
    for(auto i:ans){
        cout<<i<<" ";
    }
    cout<<endl;
    return 0;
}