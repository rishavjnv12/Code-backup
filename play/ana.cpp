#include <bits/stdc++.h>
using namespace std;

int main(){
    string a,b;
    cin >> a;
    cin >> b;
    string af = "",bf = "";
    for(char &c:a){
        if('A'<=c<='Z' or 'a'<=c<='z'){
            af+=tolower(c);
        }
    }
    for(char &c:b){
        if('A'<=c<='Z' or 'a'<=c<='z'){
            bf+=tolower(c);
        }
    }
    vector<int> afreq(26),bfreq(26);
    for(char c:af)
        afreq[c-'a']++;
    for(char c:bf)
        bfreq[c-'a']++;
    
    if(afreq == bfreq){
        // ANAGRAM
    }else{
        // NOT ANAGRAM
    }

    return 0;
}