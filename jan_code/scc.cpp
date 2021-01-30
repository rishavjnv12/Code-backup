#include <bits/stdc++.h>
#define int long long
const int mod = 998244353;
using namespace std;
vector<vector<int>> g;
int m,n,k;
map<int,int> mp;
stack<pair<int,int>> st;
vector<vector<bool>> vis;
long long mul(long long a,long long b){
    return ((a%mod)*(b%mod))%mod;
}
long long add(long long a,long long b){
    return (a+b)%mod;
}
long long power(int x,int y){
    if(!x)
        return 0;
    if(!y)
        return 1;
    
    long long temp;
    if(y%2==0){
        temp = power(x,y/2);
        temp = mul(temp,temp);
    }else{
        temp = power(x,y/2);
        temp = mul(temp,temp);
        temp = mul(temp,x);
    }
    return temp;
}
int gcd(int a,int b,int *x,int *y){
    if(a == 0){
        *x = 0;
        *y = 1;
        return b;
    }
    int x1,y1;
    int g = gcd(b%a,a,&x1,&y1);
    if(g!=1)
        return -1;
    *x = y1-(b/a)*x1;
    *y = x1;
    
    return g;
}
int modinv(int a){
    int x,y;
    int g = gcd(a,mod,&x,&y);
    return (x%mod+mod)%mod;
}
void init(){
    for(int i=0;i<m;i++)
        g.push_back(vector<int>(n,1));
}

bool inc(){
    int carry = 1;
    for(int i=m-1;i>=0;i--){
        bool done = false;
        for(int j=n-1;j>=0;j--){
            // cout << i << " " << j << endl;
            if(g[i][j] == k){
                g[i][j] = 1;
            }else{
                g[i][j]++;
                carry = 0;
                done = true;
                break;
            }
        }
        if(done)
            break;
    }
    return carry == 0;
}

void print(){
    for(auto v:g){
        for(int x:v)
            cout << x << " ";
        cout << endl;
    }
}
void set_vis(){
    for(int i=0;i<m;i++)  
        for(int j=0;j<n;j++)
            vis[i][j] = 0;
}
bool in_range(int i,int j){
    bool ans = (i>=0 and i<m and j>=0 and j<n);
    return ans;
}

void dfs(int x,int y,int i,int j){
    if(vis[i][j])
        return;
    vis[i][j] = true;
    // cout << i << j << "From:" << x << y << endl;
    if(in_range(i+1,j) and g[i+1][j]>=g[i][j]) {
        // cout << __LINE__ << ":" << i << j << endl;
        dfs(i,j,i+1,j);
    }
    if(in_range(i-1,j) and g[i-1][j]>=g[i][j]) {
        // cout << __LINE__ << ":" << i << j << g[i][j] << g[i-1][j] << endl;
        dfs(i,j,i-1,j);
    }
    if(in_range(i,j+1) and g[i][j+1]>=g[i][j]) {
        // cout << __LINE__ << ":" << i << j << endl;
        dfs(i,j,i,j+1);
    }
    if(in_range(i,j-1) and g[i][j-1]>=g[i][j]){
        // cout << __LINE__ << ":" << i << j << endl;
        dfs(i,j,i,j-1);
    }
    st.push({i,j});
}
void dfs2(int i,int j){
    if(vis[i][j])
        return;
    vis[i][j] = true;
    if(in_range(i+1,j) and g[i+1][j]<=g[i][j]) dfs2(i+1,j);
    if(in_range(i-1,j) and g[i-1][j]<=g[i][j]) dfs2(i-1,j);
    if(in_range(i,j+1) and g[i][j+1]<=g[i][j]) dfs2(i,j+1);
    if(in_range(i,j-1) and g[i][j-1]<=g[i][j]) dfs2(i,j-1);
}

void work(){
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(vis[i][j] == false){
                dfs(-1,-1,i,j);
            }
        }
    }
    set_vis();
    int ans = 0;
    while(st.size()){
        auto curr = st.top();
        if(vis[curr.first][curr.second]==false){
            dfs2(curr.first,curr.second);
            ans++;
        }
        st.pop();
    }
    mp[ans]++;
}

void pascal_triangle_approach(){
    int total = power(k,n*m);
    int ans = 0;
    int factor = k;
    int prev = 1;
    ans = factor*prev;
    factor = mul(factor,k-1);
    for(int i=1;i<n;i++){
        int curr = mul(mul(prev,(n-i)),modinv(i));
        ans = add(ans,mul((i+1),mul(curr,factor)));
        factor = mul(factor,k-1+mod);
        prev = curr;
    }
    ans = mul(ans,modinv(total));
    cout << ans << "\n";
}

int32_t main(){
    cin >> m >> n >> k;

    // if(m==1){
    //     pascal_triangle_approach();
    //     return 0;
    // }
    vis.resize(m);
    for(auto &v:vis) v.resize(n);
    init();
    do{
        set_vis();
        work();
    }while(inc());

    int ans = 0;
    int total = pow(k,n*m);
    for(auto pp:mp){
        cout << pp.first << " " << pp.second << endl;
        ans = add(ans,mul(pp.first,pp.second));
    }
    ans = mul(ans,modinv(total));
    cout << ans << endl;
    return 0;
}

