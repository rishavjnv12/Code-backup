#include <bits/stdc++.h>
using namespace std;

int main(){
    int n = 20;
    vector<int> ar(n);
    for(int &x:ar)
        x = rand()%50;
    
    for(int x:ar)
        cout << x << " ";
    cout << endl;
    nth_element(ar.begin(),ar.begin()+10,ar.end());
    for(int x:ar)
        cout << x << " ";
    cout << endl;
    return 0;
}