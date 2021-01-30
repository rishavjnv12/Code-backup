#include <bits/stdc++.h>
using namespace std;
int solve(string &s){
    int o = 0,z = 0;
    for(char c:s){
        if(c == '0') o++;
        else z++;
    }
    int ans1 = 0;
    for(int i=0;i<o;i++){
        if(s[i]=='1')
            ans1++;
    }
}

int main(){
    string s = "1110101";
    return 0;
}