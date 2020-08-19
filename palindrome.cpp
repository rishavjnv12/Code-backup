#include <bits/stdc++.h>
using namespace std;
int fun(string A){
    for(int i=0;i<A.size();i++){
        if(A[i]<='Z'&&A[i]>='A')
            A[i]+=('a'-'A');
    }
    //cout<<A<<endl;
    vector<char> temp;
    for(int i=0;i<A.size();i++){
        if((A[i]<='z'&&A[i]>='a')||(A[i]>='0'&&A[i]<='9'))
            temp.push_back(A[i]);
    }
    for(int i=0,j=temp.size()-1;j>i;j--,i++){
        if(temp[i]!=temp[j])
            return 0;
    }
    // for(int i=0;i<temp.size();i++){
    //     cout<<temp[i];
    // }
    return 1;
}
int main(){
    string q="A man, a plan, a canal: Panama";
    cout<<fun(q)<<endl;
    return 0;
}