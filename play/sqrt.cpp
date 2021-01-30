#include <bits/stdc++.h>
using namespace std;
int sq(int n){
    int l = 0,r = n/2+1;
    while(l<=r){
        int mid = l+(r-l)/2;
        int curr = mid*mid;
        if(curr == n)
            return mid;
        else if(curr<n)
            l = mid+1;
        else
            r = mid-1;
    }
    return l-1;
}

int main(){
    int n;
    cin >> n;
    cout << sq(n) << endl;
    return 0;
}