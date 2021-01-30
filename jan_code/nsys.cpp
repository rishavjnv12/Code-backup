#include <bits/stdc++.h>
using namespace std;
vector<int> a = {1,1,1};
int bit = 3;
void inc(){
    int n = a.size();
    int carry = 1;

    for(int i=n-1;i>=0;i--){
        if(a[i] == bit){
            a[i] = 1;
        }else{
            a[i]++;
            break;
        }
    }
}

int main(){
    int n = 27;
    while(n--){
        cout << a[0] << a[1] << a[2] << endl;
        inc();
        
    }
    return 0;
}