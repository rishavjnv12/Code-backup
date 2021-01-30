#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main(){
    int t = 100;
    cout << t << endl;
    while(t--){
        int n = 1+rand()%10000;
        vector<int> v(n);
        int start = 1+rand()%100000000;
        iota(v.begin(),v.end(),start);
        random_shuffle(v.begin(),v.end());
        cout << n << endl;
        for(int x:v)
            cout << x << " ";
        cout << endl;
        int q = 100+rand()%1000;
        cout << q << endl;
        while(q--){
            cout << 1+rand()%100000000 << endl;
        }
    }
    return 0;
}