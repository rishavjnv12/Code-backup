#include <bits/stdc++.h>

using namespace std;

int fun(const vector<int> &A, int B) { 
    vector<int>::const_iterator itr1, itr2;
    itr1=lower_bound(A.begin(),A.end(),B);
    if(itr1==A.end() and A[A.size()-1]!=B)
        return 0;
    itr2=upper_bound(A.begin(),A.end(),B);
    return distance(itr1,itr2);
}
int main(){
    int arr[] = { 10, 20, 30,40,50,50,60,60,60,60,60,70,70,80,90,100,110,120,140,150,160,170,180 }; 
    int n = sizeof(arr) / sizeof(arr[0]);
    const vector<int>v(arr,arr+n);
    int x = fun(v,10);
    cout<<x<<endl;
    return 0;
}