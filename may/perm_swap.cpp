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

int visited[200004];
void tswap(int &a,int &b,int &c){
    int temp=a;
    a=c;
    c=b;
    b=temp;
}
vector<int> find_cycle(vector<int> a,int start){
    vector<int> ans;
    ans.push_back(start);
    int j=a[start];
    visited[start]=1;
    while(a[j]!=a[start]){
        visited[j]=1;
        ans.push_back(j);
        j=a[j];
    }
    return ans;
}
int32_t main(){
    vector<int> a={0,12,2,3,4,5,6,7,8,9,10,1,11};
    vector<int> cycle = find_cycle(a,1);
    
    for(int i=0;i<cycle.size();i++){
        cout<<cycle[i]<<' ';
    }
    for(int i=1;i<cycle.size();i+=2){
        tswap(a[cycle[0]],a[cycle[i]],a[cycle[i+1]]);
    }
    cout(" ");
    for(int i=0;i<a.size();i++){
        cout<<a[i]<<' ';
    }
    cout("");
    return 0;
}