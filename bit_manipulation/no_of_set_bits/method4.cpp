//Brian Kernighans's algorithm
#include <bits/stdc++.h>
using namespace std;
int countSet(unsigned int n){
    int count=0;
    while(n){
        n&=(n-1);
        count++;
    }
    return count;
}
int main(){
    for(unsigned int i=0;i<=INT_MAX;i++){
        int ans=__builtin_popcount(i);
        if(ans==countSet(i))
            cout<<i<<":Correct "<<ans<<endl;
        else
            cout<<i<<":Wrong"<<ans<<endl;
    }
    return 0;
}