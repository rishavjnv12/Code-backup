#include<bits/stdc++.h>
using namespace std;
long long calc(long long a, long long b){
    return a*b/__gcd(a,b);
}
int main(){
    long long lcm=1;
    vector<long long> arr={34, 11, 57, 5, 81, 67, 99, 76, 19, 34, 12, 43, 4, 94, 41, 74, 41, 10, 22, 84, 20, 8, 30, 12, 91, 55, 66, 16, 55, 88, 69, 78, 64, 99, 56, 54, 3, 93, 39, 69, 45, 96, 51, 29, 21, 32, 5, 73, 84, 34};
    for(long long i=0;i<arr.size();i++){
        lcm=calc(lcm,arr[i]);
    }
    cout<<lcm<<endl;
    return 0;
}