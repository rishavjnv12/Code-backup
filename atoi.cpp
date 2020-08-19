#include <bits/stdc++.h>
using namespace std;
int atoi(const string A) {
    int i=0;
    bool neg=false;
    while(A[i]==' ') i++;
    if(A[i]!='-' and !(A[i]<='9' and A[i]>='0') and A[i]!='+') return 0;
    if(A[i]=='-'){
        neg=true;
        i++;
    }
    if(A[i]=='+') i++;
    //cout<<"i is "<<i<<endl;
    long long num=0;
    for(;i<A.length();i++){
        if(num>INT_MAX){
            return neg?INT_MIN:INT_MAX;
        }
        if(!(A[i]<='9' and A[i]>='0')){
            return neg?num*(-1):num;
        }
        num=num*10+(A[i]-'0');
    }
    return neg?num*(-1):num;
}
int main(){
    string q;
    cin>>q;
    cout<<atoi(q)<<endl;
    return 0;
}