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
void remove(vector<int> &a,vector<int> &b){
    vector<int> ans_a,ans_b;
    int i=0,j=0;
    while(i<a.size() and j<b.size()){
        if(a[i]==b[j]) {
            i++;
            j++;
            continue;
        }
        else if(a[i]>b[j]){
            ans_b.push_back(b[j]);
            j++;
        }else{
            ans_a.push_back(a[i]);
            i++;
        }
    }
    while(i<a.size()){
        ans_a.push_back(a[i]);
        i++;
    }
    while(j<b.size()){
        ans_b.push_back(a[j]);
        j++;
    }
    // for(auto i:ans_a){
    //     cout <<i<<" ";
    // }
    // cout<<endl;
    // for(auto i:ans_b){
    //     cout <<i<<" ";
    // }
    // cout<<endl;
    a=ans_a;
    b=ans_b;
}

int32_t main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n),b(n);
        for(int i=0;i<n;i++){
            cin(a[i]);
        }
        for(int i=0;i<n;i++){
            cin(b[i]);
        }
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        stack<int> as,bs;
        vector<int> d_a,d_b;
        for(int i=0;i<n;i++){
            if(as.empty()){
                as.push(a[i]);
            }else{
                if(as.top()==a[i]){
                    d_a.push_back(a[i]);
                    as.pop();
                }else{
                    as.push(a[i]);
                }
            }
        }
        for(int i=0;i<n;i++){
            if(bs.empty()){
                bs.push(b[i]);
            }else{
                if(bs.top()==b[i]){
                    d_b.push_back(b[i]);
                    bs.pop();
                }else{
                    bs.push(b[i]);
                }
            }
        }

        vector<int> rem_a,rem_b;
        
        while(as.empty()==false){
            rem_a.push_back(as.top());
            as.pop();
        }
        while(bs.empty()==false){
            rem_b.push_back(bs.top());
            bs.pop();
        }
        
        if(rem_a.size()!=rem_b.size()){
            cout(-1);
            continue;
        }

        bool possible=true;
        for(int i=0;i<rem_a.size();i++){
            if(rem_a[i]!=rem_b[i]){
                possible=false;
                break;
            }
        }
        assert(d_a.size()==d_b.size());
        if(!possible){
            cout(-1);
            continue;
        }
        int ans=0;
        remove(d_a,d_b);
        int x=d_a.size();
        for(int i=0;i<x;i++){
            ans+=min(d_a[i],d_b[x-i-1]);
        }
        cout(ans);
    }
    return 0;
}