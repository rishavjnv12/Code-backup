#include <bits/stdc++.h>
#define ios ios_base::sync_with_stdio(false);cin.tie(NULL)
#define int long long
#define cout(x) cout<<x<<endl
#define cin(x) cin>>x
#define cin2(x,y) cin>>x>>y
#define cin3(x,y,z) cin>>x>>y>>z
#define all(x) x.begin(),x.end()
#define sort(x) sort(x.begin(),x.end())


using namespace std;
int a(int x){
    return -1*x;
}
void pr(vector<int> a){
    for(auto i = 0; i < a.size();i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
int32_t main()
{
    ios;
    int t;
    cin>>t;
    while(t--){
        int m,n;
        cin2(m,n);
        vector<int>px;
        vector<int>nx;
        vector<int>py;
        vector<int>ny;
        bool zx=false,zy=false;
        for(int i=0;i<m;i++){
            int x;
            cin(x);
            if(!x)
                zx=true;
            else if(x<0)
                nx.push_back(x);
            else
                px.push_back(x);
            
            
        }
        for(int i=0;i<n;i++){
            int x;
            cin(x);
            if(!x)
                zy=true;
            else if(x<0)
                ny.push_back(x);
            else
                py.push_back(x);
        }
        int ans=0;
        if(zx and zy){
            ans=(m-1)*(n-1);
        }else if(zx){
            ans=n*(m-1);
        }else if(zy){
            ans=(n-1)*m;
        }
        // cout("origin");
        // cout(ans);
        vector<int>hypx;
        vector<int>hypy;
        for(int i = 0; i <nx.size(); i++){
            for(int j = 0; j <px.size(); j++){
                int x=(-1)*nx[i]*px[j];
                if(ceil(sqrt(x))==floor(sqrt(x)))
                    hypx.push_back(x);
            }
        }
        for(int i = 0; i <ny.size(); i++){
            for(int j = 0; j <py.size(); j++){
                int x=(-1)*ny[i]*py[j];
                if(ceil(sqrt(x))==floor(sqrt(x)))
                    hypy.push_back(x);
            }
        }
        transform(all(nx),nx.begin(),a);
        transform(all(ny),ny.begin(),a);
        px.insert(px.end(),all(nx));
        py.insert(py.end(),all(ny));
        sort(px);
        sort(py);
        sort(hypx);
        sort(hypy);
        int i=0,j=0;
        pr(hypy);
        pr(px);
        while(i<hypx.size() and j<py.size()){
            if(hypx[i]==py[j]*py[j]){
                ans++;
                j++;
            }else if(hypx[i]<py[j]*py[j]){
                i++;
            }else{
                j++;
            }
        }
        i=j=0;
        while(i<hypy.size() and j<px.size()){
            if(hypy[i]==px[j]*px[j]){
                ans++;
                j++;
            }else if(hypy[i]<px[j]*px[j]){
                i++;
            }else{
                j++;   
            }
        }
        cout(ans);
    }
    return 0;
}