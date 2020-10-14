#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,b;
    cin>>a>>b;
    int q=0;
    while(a>b){
        for(int i=0;i<31;i++){
            if(b*(1<<i) < a){
                a-=(1<<i);
            }else{
                q+=(1<<(i-1));
            }
        }
        
    }
    return 0;
}
