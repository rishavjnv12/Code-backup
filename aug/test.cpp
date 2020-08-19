#include <bits/stdc++.h>

using namespace std;

int main(){
    cout<<100<<endl;
    int t=100;
    while(t--){
        int n=100+rand()%50;
        int k=rand()%50;

        cout<<n<<" "<<k<<endl;
        for(int i=0;i<n;i++){
            cout<<1+rand()%100<<" ";
        }
        cout<<endl;
    }

    return 0;
}