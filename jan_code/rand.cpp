#include <bits/stdc++.h>
using namespace std;
const int upto = 1<<10;
int main(){
    int t = 5;
    cout << t << endl;
    while(t--){
        int n = rand()%upto;
        cout << n << endl;
        while(n--){
            int m = rand()%upto;
            cout << m << " ";
            while(m--){
                int x = -1000 + rand()%2000;
                cout << x << " ";
            }
            cout << endl;
        }
    }
    return 0;
}