#include <bits/stdc++.h>
#define long long

using namespace std;
int32_t main(){
    int x,y;
    cin >> x >> y;
    assert(x>0 and x<=LLONG_MAX);
    assert(y>0 and y<=LLONG_MAX);
    assert(ceil(1.0*x/y)==((x+y-1)/y));
    return 0;
}