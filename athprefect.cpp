#include <bits/stdc++.h>

using namespace std;
vector<string> a(100001);
void prec(){
    a[0] = "";
    a[1] = "11";
    a[2] = "22";
    int prev = 2;
    int n = 4;
    int cnt = 1;
    for(int i=3;i<a.size();i++){
        if(cnt <= n/2){
            a[i] = '1' + a[i-prev] +'1';
            cnt++;
        } else {
            cnt++;
            a[i] = '2' + a[i-2*prev] + '2';
        }
        if(cnt > n){
            cnt = 1;
            n*=2;
            prev*=2;
        }
    }
}

string ath_perfect(int n){
    return a[n];
}
int main(){
    prec();
    int n;
    cin >> n;
    cout << ath_perfect(n) << endl;
    // for(auto x:a)
    //     cout << x << endl;
    return 0;
}
// 11,22,1111,1221,2112,2222