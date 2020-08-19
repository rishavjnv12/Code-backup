#include <bits/stdc++.h>
using namespace std;
vector<int> naive(string text,string patt){
    vector<int> result;
    int m=text.length();
    int n=patt.length();
    for(int i=0;i<=m-n;i++){
        int j;
        for(j=0;j<n;j++){
            if(text[i+j]!=patt[j])
                break;
        }
        if(j==n)
            result.push_back(i);
    }
    return result;
}
int main(){
    string text,pattern;
    vector<int> ans;
    cout<<"Enter text:"<<endl;
    getline(cin, text);
    cout<<"Enter pattern:"<<endl;
    getline(cin, pattern);
    ans=naive(text,pattern);
    if(ans.size()==0){
        cout<<"Pattern not found."<<endl;
        return 0;
    }
    for(int i=0;i<ans.size();i++){
        cout<<"Patter found at index "<<ans[i]<<endl;
    }
    return 0;
}