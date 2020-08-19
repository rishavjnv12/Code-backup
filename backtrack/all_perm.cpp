#include <bits/stdc++.h>

using namespace std;

void allPerm(string str,int l,int r){
    if(l==r){
        cout<<str<<endl;
    }
    else
        for(int i=l;i<=r;i++){
            swap(str[i],str[l]);
            allPerm(str,l+1,r);
            swap(str[i],str[l]);
        }
}

int main(){
    string str="0123";
    allPerm(str,0,str.size()-1);
    return 0;
}