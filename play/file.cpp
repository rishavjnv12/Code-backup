#include <bits/stdc++.h>
using namespace std;
bool solve(string &s){
    int left,right;
    const int n = s.size();
    for(int i=0;i<n;i++){
        if(s[i] == '(') left = i;
        if(s[i] == ')') right = i;
    }
    // cout << left << " " << right << endl;
    if(right<left){
        if((right%2)==((n-left+1+2)%2) and (left-right-1)%2==0) return true;
        else return false;
    }else{
        if((left%2)==((n-1-right)%2) and (right-left-1+2)%2==0) return true;
        return false;
    }
    
}
int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        bool ans = solve(s);
        if(ans) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}