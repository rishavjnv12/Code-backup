#include <bits/stdc++.h> 
using namespace std;
bool solve(string s){
    int mis_match = 0;
    int i = 0,j = s.size()-1;
    while(j>i){
        if(a[i]!=a[j])
            mis_match++;
        i++;
        j--;
    }
    return mis_match <= 1;
}

int32_t main(){
    string s = "abccba";
    return 0;
}