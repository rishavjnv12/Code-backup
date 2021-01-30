#include <bits/stdc++.h>
using namespace std;
const int mx = static_cast<int>(1e6);
vector<int> spf(mx+1,-1);
void seive(){
    for(int i=2;i<=mx;i++){
        if(spf[i]==-1){
            for(int j=1;i*j<=mx;j++){
                if(spf[i*j]==-1)
                    spf[i*j] = i;
            }
        }
    }
}

// Return a list of all prime factors of the number
vector<int> get_prime_factors(int n){
    vector<int> ans;
    while(n!=1){
        int sp = spf[n];
        ans.push_back(sp);
        while(n%sp==0)
            n/=sp;
    }
    return ans;
}
int main(){
    seive();
    /*
    while(true){
        int n;
        cin>>n;
        auto ans = get_prime_factors(n);
        cout << n << ":";
        for(int x:ans){
            cout << x << " ";
        }
        cout << endl;
    }
    */
    return 0;
}