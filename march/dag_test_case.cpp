#include <bits/stdc++.h>
#define ios ios_base::sync_with_stdio(false);cin.tie(NULL)
#define int long long
#define cout(x) cout<<x<<endl
#define cin(x) cin>>x
#define cin2(x,y) cin>>x>>y
#define cin3(x,y,z) cin>>x>>y>>z

using namespace std;
int32_t main(){
    srand(time(NULL));
    int t=rand()%10;
    cout(t);
    while(t--){
        int n=1+rand()%9;
        int k=1+rand()%2;
        cout<<n<<" "<<k<<endl;
        vector<int>s(n);
        for(int i=0;i<n;i++){
            s[i]=i+1;
        }
        while(k--){
            unsigned seed = 0;
            shuffle(s.begin(), s.end(), default_random_engine(seed));
            //cout << "shuffled elements are:"; 
            for (int& i : s) 
                cout <<i<<" "; 
            cout << endl;
        }
    }
    return 0;
}