#include <bits/stdc++.h>
using namespace std;
int findPeak(vector<int> &a){
    const int n = a.size();
    if(n==1)
        return a[0];
    if(a[0]>a[1])
        return a[0];
    if(a[n-1]>a[n-2])
        return a[n-1];
    int left = 0,right = n-1;
    while(left<=right){
        int mid = left+(right-left)/2;
        if(a[mid-1]<a[mid] and a[mid]>a[mid+1])
            return a[mid];
        else if(a[mid-1]>a[mid])
            right = mid-1;
        else
            left = mid+1;
    }
    assert(false);
    return -1;
}
int main(){
    vector<int> a(20);
    iota(a.begin(),a.end(),0);
    int n;
    cin >> n;
    while(n--)
        random_shuffle(a.begin(),a.end());
    a[0] = -10000;
    a[a.size()-1] = -100001;
    for(int &x:a)
        cout << x << " ";
    cout << endl;
    cout << "Peak element:" << findPeak(a) << endl;
    return 0;
}