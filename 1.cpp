#include <bits/stdc++.h>
#define int long long
using namespace std;

// 1 2 4

// 0-1-2-3
// 0-2-3
// 0-3
// 0-1-3



int32_t main(){
    int ar[61];
    ar[1] = 1;
    ar[2] = 2;
    ar[3] = 4;
    for(int i=4;i<=60;i++){
        ar[i] = ar[i-1]+ar[i-2]+ar[i-3];
    }
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << ar[n] << endl;
    }
    return 0;
}