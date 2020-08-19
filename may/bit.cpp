#include <bits/stdc++.h>
#define ios ios_base::sync_with_stdio(false);cin.tie(NULL)
#define int long long
#define mod 1000000007
#define INF 1000000000
#define endl '\n'
#define cout(x) cout<<x<<" "
#define debug(x) cout<<x<<"\n\n"
#define cin(x) cin>>x
#define cin2(x,y) cin>>x>>y
#define cin3(x,y,z) cin>>x>>y>>z


using namespace std;
int fun(int x,int y,int z){
    return ((x&z)*(y&z));
}
int fun2(vector<int> v,int x,int y,int l,int r){
    int ans=fun(x,y,v[0]);
    int id=v[0];
    for(int i=1;i<v.size();i++){
        int temp=fun(x,y,v[i]);
        if(temp>ans){
            ans=temp;
            id=v[i];
        }else if(temp==ans and v[i]<id){
            ans=temp;
            id=v[i];
        }
    }
    return id;
}

int32_t main(){
    ios;
    int t;
    cin>>t;
    while(t--){
        int x,y,l,r;
        cin>>x>>y>>l>>r;
        if(!x or !y){
            cout<<l<<endl;
            continue;
        }

        int ans=x|y;
        
        if(ans<=r){
            cout<<ans<<endl;
            continue;
        }
        int max_bit=floor(log2(r)),ans_bit=floor(log2(ans));
        for(int i=ans_bit;i>max_bit;i--){
            if((ans & (1<<i))!=0){
                ans-=(1<<i);
            }
        }
        if(ans<=r){
            cout<<ans<<endl;
            continue;
        }

        int final=ans-(1<<max_bit);
        vector<int> pos;
        for(int i=max_bit;i>=0;i--){
            int check=(1<<i);
            if((r&check)!=0  and (ans&check)!=0){
                int temp=ans-check;
                if(temp<=r){
                    pos.push_back(temp);
                }       
            }else if((r&check)==0  and (ans&check)!=0){
                ans-=check;
                if(ans<=r)
                    pos.push_back(ans);
            }
        }
        cout<<fun2(pos,x,y,l,r)<<"\n";
        // for(auto i:pos){
        //     cout<<i<<" ";
        // }
        // cout<<endl;
    }
    return 0;
}