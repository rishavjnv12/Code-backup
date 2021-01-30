#include <bits/stdc++.h>
#define int long long
using namespace std;
int32_t main(){
    int n,k;
    cin >> n >> k;
    vector<int> a(n);
    for(int i=0;i<n;++i)
        cin >> a[i];
    sort(a.rbegin(),a.rend());
    int sum = accumulate(a.begin(),a.end(),0);
    int mean = sum/n+1;
    int x = 0;
    int i = 0;
    while(x<k and i<n){
        if(a[i]<mean){
            int to_add = min(mean-a[i],k-x);
            a[i]+=to_add;
            i++;
            x+=to_add;
        }else{
            int to_sub = min(mean-a[i],k-x);
            a[i]-=to_sub;
            i++;
            x+=to_sub;
        }
    }
    auto pp = minmax_element(a.begin(),a.end());
    cout << abs(pp.first-pp.second) << endl;
    return 0;
}

// 7
// 2 3 7 7 8  -> 5.4