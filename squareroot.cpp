#include <bits/stdc++.h>
using namespace std;
long long sqroot(long long A){
    if(A==0 or A==1) return A;
    long long start=1,end=A,ans;
    while(end>=start){
        long long mid=(start+end)/2;
        if(mid*mid==A)
            return mid;
        else if(mid*mid<A){
            start=mid+1;
            ans=mid;
        }else{
            end=mid-1;
        }
    }
    return ans;
}
int main(){
    long long num;
    cout << "num :";
    cin>>num;
    cout<<sqroot(num)<<endl;
    return 0;//
}