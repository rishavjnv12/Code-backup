#include <bits/stdc++.h>
#define print(x) cout<<x<<endl
using namespace std;
vector<int> compute_lps(string pattern){
    int n=pattern.length();
    vector<int> lps(n,0);
    int len=0;
    for(int i=1;i<n;){
        if(pattern[i]==pattern[len]){
            len++;
            lps[i]=len;
            i++;   
        }else{
            if(len)
                len=lps[len-1];
            else{
                lps[i]=0;
                i++;
            }
        }
    }
    return lps;
}
vector<int> kmp_search(string text,string pattern){
    int n=text.length();
    int m=pattern.length();
    vector<int> lps=compute_lps(pattern);
    vector<int> result;
    int i=0;
    int j=0;
    while(i<n){
        if(text[i]==pattern[j]){
            i++;
            j++;
        }
        if(j==m){
            result.push_back(i-j);
            j=lps[j-1];
        }else if(i<n and pattern[j]!=text[i]){
            if(j)
                j=lps[j-1];
            else i++;
        }
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
    ans=kmp_search(text,pattern);
    if(ans.size()==0){
        cout<<"Pattern not found."<<endl;
        return 0;
    }
    for(int i=0;i<ans.size();i++){
        cout<<"Patter found at index "<<ans[i]<<endl;
    }
    return 0;
}