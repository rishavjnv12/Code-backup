#include <bits/stdc++.h>
using namespace std;

int main(){
    forward_list<int> a = {1,2,3,4,5,6,7};
    a.sort(greater<int>());
    for(auto x:a)
        cout << x << " ";
    cout << endl;
    return 0;
}