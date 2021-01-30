#include <bits/stdc++.h> 
const int mod = 1e9+7;
using namespace std;
int atoi(string s){
    int n = s.size();
    if(!n)
        return 0;
    int state = 'A';
    bool negative = false;
    bool overflow = false;
    long long ans = 0;
    if(s[0] == '-'){
        negative = true;
        state = 'B';
    }else if(s[0]=='+'){
        state = 'B';
    }else if(s[0]<='9' and s[0]>='0'){
        ans = (s[0]-'0');
        state = 'C';
    }else{
        state = 'D';
        return ans;
    }
    for(int i=1;i<n;i++){
        if(s[i]<='9' and s[i]>='0'){
            ans = (ans*10) + (s[i]-'0');
            state = 'C';
        }else{
            state = 'D';
            break;
        }

        if(ans>INT_MAX){
            overflow = true;
            break;
        }
    }
    if(overflow){
        if(negative)
            return INT_MIN;
        return INT_MAX;
    }
    if(negative) ans*=-1;
    return ans;
}

int32_t main(){
    int t;
    cin >> t;
    // while(t--){
    //     string s;
    //     cin >> s;
    //     cout << atoi(s) << endl;
    // }
    cout << atoi("") << endl;
    return 0;
}

