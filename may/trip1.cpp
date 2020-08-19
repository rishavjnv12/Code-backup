#include <bits/stdc++.h>
#define ios ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define int long long
#define mod 1000000007
#define INF 1000000000
#define endl '\n'
#define cout(x) cout<<x<<'\n'
#define debug(x) cout<<x<<endl
#define cin(x) cin>>x
#define cin2(x,y) cin>>x>>y
#define cin3(x,y,z) cin>>x>>y>>z


using namespace std;
int visited[200001];
int ans;
vector<int> final;

void tswap(int &a,int &b,int &c){
    int temp=a;
    a=c;
    c=b;
    b=temp;
}
vector<int> find_cycle(vector<int> a,int start){
    vector<int> ans;
    int inf=0;
    ans.emplace_back(start);
    int j=a[start];
    visited[start]=1;
    while(a[j]!=a[start]){
        inf++;
        assert(inf<20000001);
        visited[j]=1;
        ans.emplace_back(j);
        j=a[j];
    }
    visited[a[j]]=1;
    return ans;
}
void fun(vector<vector<int> > cycles){
    for(int j=0;j<cycles.size();j++){
        for(int i=1;i<cycles[j].size();i+=2){
            final.push_back(cycles[j][0]);
            final.push_back(cycles[j][i]);
            final.push_back(cycles[j][i+1]);
        }
    }
}
int32_t main(){
    ios;
    int t;
    cin>>t;
    while(t--){
        int n,k;
        memset(visited, false, sizeof(visited));
        final.clear();
        ans=0;
        cin2(n,k);
        vector<int> ar(n+1);
        for(int i=1;i<=n;i++){
            cin(ar[i]);
            if(ar[i]==i){
                visited[ar[i]]=1;
            }
        }
        vector<vector<int>> odd,even;
        /***********For subtask one only****************/
        // if(n%4==2 or n%4==3){
        //     cout<<-1<<endl;
        // }else{
        //     if(k<n/2){
        //         cout(-1);
        //     }else{
        //         cout(n/2);
        //         int i2=1,i3=0;
        //         for(int i=1;i<=n/2;i++){
        //             cout<<i<<" "<<n-i2<<" "<<n-i3<<endl;
        //             if(i%2==0){
        //                 i2+=2;
        //                 i3+=2;
        //             }
        //         }
        //     }
        // }
        /***********************************************/
        for(int i=1;i<=n;i++){
            vector<int> temp;
            if(!visited[i]){
                temp = find_cycle(ar,i);
                if(temp.size()%2==0){
                    even.emplace_back(temp);
                }else if(temp.size()%2==1){
                    odd.emplace_back(temp);
                }
            }
        }
        // debug(even.size());
        // for(int i=0;i<even.size();i++){
        //     for(int j=0;j<even[i].size();j++){
        //         cout << even[i][j] << " ";
        //     }
        //     cout<<endl;
        // }
        if(even.size()%2){
            cout<<-1<<endl;
            continue;
        }
        // debug("here");
        for(int i=0;i<even.size();i+=2){
            final.push_back(even[i][0]);
            final.push_back(even[i][1]);
            final.push_back(even[i+1][0]);
            ans++;
            // for(auto i:even[i]){
            //     cout<<i<<" ";
            // }
            // cout<<endl;
            // for(auto i:even[i+1]){
            //     cout<<i<<" ";
            // }
            // cout<<endl;
            vector<int> temp;
            temp.push_back(even[i][0]);
            for(int j=1;j<even[i+1].size();j++){
                temp.push_back(even[i+1][j]);
            }
            temp.push_back(even[i+1][0]);
            for(int j=2;j<even[i].size();j++){
                temp.push_back(even[i][j]);
            }
            odd.push_back(temp);
        }
        for(int i=0;i<odd.size();i++){
            ans+=odd[i].size()/2;
        }
        fun(odd);
        cout<<ans<<endl;
        for(int i=0;i<final.size();i+=3){
            cout<<final[i]<<" "<<final[i+1]<<" "<<final[i+2]<<endl;
        }
    }
    return 0;
}