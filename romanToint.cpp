#include <bits/stdc++.h>

using namespace std;

int toDecimal(string s){
    if(s=="") return 0;
    if(s=="I") return 1;
    if(s=="II") return 2;
    if(s=="III") return 3;
    if(s[0]=='I') return -1+toDecimal(s.substr(1));
    if(s[0]=='V') return 5+toDecimal(s.substr(1));
    if(s[0]=='X' and (s[1]=='L' or s[1]=='C')) return -10+toDecimal(s.substr(1));
    if(s[0]=='X') return 10+toDecimal(s.substr(1));
    if(s[0]=='L') return 50+toDecimal(s.substr(1));
    if(s[0]=='C' and (s[1]=='D' or s[1]=='M')) return -100+toDecimal(s.substr(1));
    if(s[0]=='C') return 100+toDecimal(s.substr(1));
    if(s[0]=='D') return 500+toDecimal(s.substr(1));
    if(s[0]=='M') return 1000+toDecimal(s.substr(1));
    else return INT_MIN;
}

int main(){
    string roman;
    cin>>roman;
    int dec=toDecimal(roman);
    cout<<"Decimal equivalent is "<<dec<<endl;
    main();
    return 0;
}
