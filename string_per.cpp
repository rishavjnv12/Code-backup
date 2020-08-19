#include<bits/stdc++.h>
using namespace std;
int main(){
    string str="ABCZ";
    sort(str.begin(),str.end());
    do{
        for(auto i:str){
            cout<<i<<" ";
        }
        cout<<endl;
    }while(next_permutation(str.begin(),str.end()));
    return 0 ;
}