#include <bits/stdc++.h>
#define ios ios_base::sync_with_stdio(false);cin.tie(NULL)
#define int long long
#define mod 1000000007
#define INF 1000000000
#define endl '\n'
#define cout(x) cout<<x<<'\n'
#define debug(x) cout<<x<<'\n\n'
#define cin(x) cin>>x
#define cin2(x,y) cin>>x>>y
#define cin3(x,y,z) cin>>x>>y>>z


using namespace std;

int32_t main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        vector<int> b(n);
        int x=0;
        for(int i=0; i<n; i++){
            cin(a[i]);
            x^=a[i];
        }
        for(int i=0; i<n; i++){
            cin(b[i]);
            x^=b[i];
        }
        // cout(x);
        if(x){
            cout(-1);
            continue;
        }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        int amin=a[0];
        int bmin=b[0];
        int aptr=0,bptr=0;
        int cost=0;
        int tmin;
        // cout("hello");
        if(bmin==amin){
            tmin=amin;
            aptr=n-1;
            bptr=n-1;
            while(true){
                if(a[aptr]==b[bptr]){
                    aptr--;
                    bptr--;
                }
                

            }
            
            cout(cost);


        }else{
            
            if(amin>bmin){
                swap(a,b);
                swap(amin,bmin);
            }
            while(b[bptr]!=b[bptr+1]){
                bptr++;
            }
            cost+=a[0];
            
            swap(b[bptr],a[0]);
            sort(a.begin(),a.end());
            sort(b.begin(),b.end());
            for(auto i:a){
                cout<<i<<" ";
            }
            cout("");
            for(auto i:b){
                cout<<i<<" ";
            }
            cout("");
            tmin=a[0];
            aptr++;
            bptr++;

            while(true){
                if(aptr>=a.size()-1 or bptr>=b.size()-1) break;
                
                while(a[aptr]==b[bptr]){
                    aptr++;
                    bptr++;
                }
                while(a[aptr]!=a[aptr+1]) aptr++;
                while(b[bptr]!=b[bptr+1]) bptr++;
                if(aptr>=a.size()-1 or bptr>=b.size()-1) break;
                
                if(min(a[aptr],b[bptr])<=2*tmin){
                    cout(cost);
                    cost+=min(a[aptr],b[bptr]);
                    cout<<","<<cost<<endl;
                    aptr+=2;
                    bptr+=2;
                }else{
                    cout(aptr);
                    cout(bptr);
                    cout(tmin);
                    cout(a[aptr]);
                    cout(min(a[aptr],b[bptr]));
                    cost+=(2*tmin);
                    aptr+=2;
                    bptr+=2;
                    
                }

            }
            cout(cost);

        }

    }

    return 0;
}