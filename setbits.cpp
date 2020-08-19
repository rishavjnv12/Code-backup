#include <bits/stdc++.h>
#define mod 1000000007


int32_t main(){
    int ar[1001];
    ar[0]=0;
    for(int i=1;i<=1000;i++){
        ar[i]=ar[i-1]+__builtin_popcount(i);
    }
    for(int i=0;i<=1000;i++){
        std::cout<<ar[i]<<",";
    }
    return 0;
}