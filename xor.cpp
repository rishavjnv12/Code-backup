#include <bits/stdc++.h>
using namespace std;
int fun2(int x){
    int ans=0;
    for(int i=1;i<=x;i++){
        ans^=i;
    }
    return ans;
}
int fun(int t){
    if(t%2==0){
        if((t/2)%2==0)
            return t;
        else return (t+1);
    }else{
        if(((t+1)/2)%2==1)
            return 1;
        else return 0;
           
    }
}
int main(){
    int x=0;
    for(int i=0;i<100000;i++){
        x^=i;
        cout<<i<<":   "<<x<<","<<fun2(i)<<endl;
    }
    return 0;
}