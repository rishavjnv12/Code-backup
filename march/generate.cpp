#include <bits/stdc++.h>
#define int long long
using namespace std;
int randomNoGenerator(int limit) 
{ 
    random_device rd;  
    mt19937 gen(rd()); 
    uniform_int_distribution<> dis(1, limit); 
    return dis(gen); 
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n=100;
    cout<<n<<endl;
    while(n--){
        int r=randomNoGenerator(100000);
        cout<<r<<endl;
        for(int i=0;i<r;i++){
            int rn=randomNoGenerator(100000000);
            cout<<rn<<" ";
        }
        cout<<endl;
    }
    return 0;
}