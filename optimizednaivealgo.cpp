//this works only when all characters of pattern are different
#include<bits/stdc++.h>
using namespace std;
vector<int> optimizednaive(string text,string patt){
    int m=patt.size();
    int n=text.size();
    int i=0;
    vector<int> result;
    while(i<=n-m){
        int j;
        for(j=0;j<m;j++){
            if(text[i+j]!=patt[j]){
                break;
            }
        }
        if(j==m){
            result.push_back(i);
            i+=m;
        }else if(j==0)
            i++;
        else 
            i+=j;
    }
    return result;
}
int main(){
    string text,pattern;
    vector<int> ans;
    cout<<"Enter text:"<<endl;
    getline(cin, text);
    cout<<"Enter pattern(all character different):"<<endl;
    getline(cin, pattern);
    ans=optimizednaive(text,pattern);
    if(ans.size()==0){
        cout<<"Pattern not found."<<endl;
        return 0;
    }
    for(int i=0;i<ans.size();i++){
        cout<<"Patter found at index "<<ans[i]<<endl;
    }
    return 0;
}