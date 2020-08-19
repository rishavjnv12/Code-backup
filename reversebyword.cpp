#include <bits/stdc++.h>
using namespace std;
string reverse(string str){
    if(str.size()==0) return "";
    int n=str.size()-1,i=0;
    while(str[i]==' ') i++;
    while(str[n]==' ') n--;
    string result="",temp="";
    for(;i<=n;i++){
        if(str[i]!=' ')
            temp+=str[i];
        else{
            result=temp+" "+result;
            temp="";
        }
    }
    result=temp+" "+result;
    return result;
} 
int main(){
    string q;
    getline(cin,q);
    cout<<reverse(q)<<endl;
    return 0; //
}