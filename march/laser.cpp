#include <bits/stdc++.h>
#define int long long
#define ui unsigned
#define cout(x) cout<<x<<endl
#define cin(x) cin>>x
#define cin2(x,y) cin>>x>>y
#define cin3(x,y,z) cin>>x>>y>>z
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL)

using namespace std;
bool intersect(int x1,int y1,int x2,int y2,int xx1,int xx2,int y){
    if(x1==xx1 and y1==y) return true;
    if(xx2==x2 and y==y2) return true;
    if(xx2==x1 and y==y1) return false;
    if(x2==xx1 and y==y2) return false;
    double x=((double)(y-y2)*(x1-x2))/(y1-y2)+(double)x2;
    return ((x>x1 and x<x2) and (x>xx1 and x<xx2));
}
int32_t main(){
    fastio;
    int t;
    cin(t);
    while(t--){
        int n,q;
        cin2(n,q);
        vector<int> p(n);
        for(ui i=0;i<n;i++){
            cin(p[i]);
        }
        
        while(q--){
            int xx1,xx2,y;
            cin3(xx1,xx2,y);
            int ans=0;
            for(int i=0;i<n-1;i++){
                if(intersect(i+1,p[i],i+2,p[i+1],xx1,xx2,y))
                    ans++;
            }
            cout(ans);
        }
    }
    return 0;
}