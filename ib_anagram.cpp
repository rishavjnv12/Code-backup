#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> anagram(vector<string> s){
    vector<vector<int>> ans;
    for(size_t i=0;i<s.size();i++){
        sort(s[i].begin(),s[i].end());
    }
    map<string,vector<int>> mp;
    for(int i=0;i<s.size();i++){
        mp[s[i]].push_back(i+1);
    }
    for(auto itr=mp.begin();itr!=mp.end();itr++){
        ans.push_back(itr->second);
    }
    return ans;
}
int main(){
    vector<string> q={"cat","dog","god","tac"};
    auto ans=anagram(q);
    for(size_t i=0;i<ans.size();i++){
        for(size_t j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}