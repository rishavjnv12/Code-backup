#include <bits/stdc++.h>
using namespace std;
0 1 2 3 4 5 6 7
bool check(vector<int> &a,int win,int l_sort,int r_sort){
    if(win-1 <= r_sort) return true;
    while(win )

}
int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &x:a) cin >> x;
    vector<int> b = a;
    int i = 0,j = n-1;;
    while(i<n-1 and a[i+1]>=a[i]) i++;
    // cout << i << endl;
    while(j>0 and a[j-1]<=a[j]) j--;
    // cout << j << endl;
    if(!j){
        cout << 0 << endl;
        return 0;
    }
    int l = 1,r = n;
    int ans;
    while(l<=r){
        int mid = l+(r-l)/2;
        if(check(a,mid,i,j)){
            ans = mid;
            r = mid-1;
        }else{
            l = mid+1;
        }
    }
    return 0;
}


// 1 2 4 3 5