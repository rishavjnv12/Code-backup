//nlogn
#include<bits/stdc++.h>
using namespace std;
int search(vector<int> arr){
    unordered_set<int> S;
    for(int i=0; i<arr.size();i++){
        S.insert(arr[i]);
    }
    int sum=accumulate(S.begin(),S.end(),0);
    int realsum=accumulate(arr.begin(),arr.end(),0);
    return (sum*3-realsum)/2;
}
int main(){
    vector<int>arr={1,1,1,2,3,4,2,3,5,3,4,4,2};
    cout<<search(arr)<<endl;
    return 0;
}