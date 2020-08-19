#include <bits/stdc++.h>
#define ios ios_base::sync_with_stdio(false);cin.tie(NULL)
#define int long long


using namespace std;

char give_ver(int guess,int actual){
    if(guess<actual) return 'G';
    else if(guess>actual) return 'L';
    else return 'E';
}


int32_t main(){
    ios;
    int n;
    cin>>n;
    // n=10000;
    // int act=62333;

    int oddleft=1,oddright=n;
    int evenleft=1,evenright=n;
    int i=1;
    int ans;
    char ver;
    do{
        fflush(stdout);
        if(i%2){
            ans=(oddleft+oddright)/2;
            assert(ans<=n);
            cout<<ans<<endl;
            if(ver=='G') oddleft=ans+1;
            else if(ver=='L') oddright=ans-1;
        }else{
            ans=(evenleft+evenright)/2;
            assert(ans<=n);
            cout<<ans<<endl;
            cin>>ver;
            if(ver=='G') evenleft=ans+1;
            else if(ver=='L') evenright=ans-1;
        }
        i++;
    }while(ver!='E');
    return 0;
}