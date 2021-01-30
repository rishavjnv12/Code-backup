#include <bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
    int k;
    cin >> k;
    int prev = 1;
    cout << 1 << " ";
    for(int i=1;i<k;i++){
        int curr = (prev*(k-i))/(i);
        cout << curr << " ";
        prev = curr;
    }
    return 0;
}