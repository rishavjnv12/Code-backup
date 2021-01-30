#include <bits/stdc++.h>
#define int long long
const int mod = 1e9+7;
using namespace std;
inline int add(int a,int b){
    return ((a%mod)+(b%mod))%mod;
}
inline int mul(int a,int b){
    return ((a%mod)*(b%mod))%mod;
}
inline int sub(int a,int b){
    return (a-b+mod)%mod;
}
int get_idx(int &prev,int r,int n){
    if(r%n == 0){
        prev = sub(r/n,1);
        return n-1;
    }else{
        prev = r/n;
        return r%n - 1;
    }
}
void special(vector<int> &a){
    int q;
    cin >> q;
    while(q--){
        int x;
        cin >> x;
        cout << x%mod << endl;
    }
}
void first_one(vector<int> &a){
    const int n = a.size();
    int q;
    cin >> q;
    while(q--){
        int x;
        cin >> x;
        int ans;
        
        if(x==1)
            cout << "1" << endl;
        else{
            x--;
            // cout << "Hello" << endl;
            // cout << x << endl;
            int prev = x/n;
            if(x%n == 0)
                cout << prev%mod << endl;
            else
                cout << add(prev,1) << endl;
        }

    }
}
void single(vector<int> &a){
    if(a[0]==1)
        special(a);
    else{
        int preq;
        if(a[0]%2==0)
            preq = a[0]-1;
        else preq = a[0];
        int q;
        cin >> q;
        while(q--){
            int x;
            cin >> x;
            int ans = mul(preq,x-1);
            ans = add(ans,a[0]);
            cout << ans%mod << endl;
        }
    }
}
void last_one(vector<int> &a){
    const int n = a.size();
    int preq = 1;
    int i;
    for(i=0;i<n-1;i++){
        int x = a[i];
        if(x%2)
            preq = add(preq,x-1);
        else preq = add(preq,x);
    }
    vector<int> rem(n);
    int curr = 0;
    for(int i=0;i<n;i++){
        int x = a[i];
        curr = add(curr,x);
        rem[i] = curr;
        if(x%2)
            curr = sub(curr,1);
    }
    int q;
    cin >> q;
    for(int i = 0;i<q;i++){
        int prev,r;
        cin >> r;
        int idx = get_idx(prev,r,n);
        int ans = mul(prev,preq);
        ans = add(ans,rem[idx]);
        cout << ans%mod << endl;
    }
}
void yes_one(vector<int> &a,int one_idx){
    int preq = 0;
    const int n = a.size();
    for(int i=0;i<n;i++){
        int x = a[i];
        if(i==one_idx)
            continue;
        else if(i==one_idx-1 or i==n-1){
            if(x%2==0)
                x--;
            preq = add(preq,x);
        }else{
            if(x%2)
                x--;
            preq = add(preq,x);
        }
    }

    vector<int> rem(n);
    int curr = 0;
    for(int i=0;i<n;i++){
        curr = add(curr,a[i]);
        rem[i] = curr;
        if(i == one_idx-1){
            if(a[i]%2==0){
                curr = sub(curr,1);
            }
        }else if(i==one_idx){
            if(a[i-1]%2){
                curr = rem[i-1];
            }else{
                curr = rem[i-1]-1;
            }
        }else{
            if(a[i]%2)
                curr = sub(curr,1);
        }
    }
    if(a[one_idx-1]%2==0)
        rem[one_idx] = add(rem[one_idx-1],1);
    else{
         rem[one_idx] = rem[one_idx-1];
    }
    int q;
    cin >> q;
    for(int i = 0;i<q;i++){
        int prev,r;
        cin >> r;
        int idx = get_idx(prev,r,n);
        int ans = mul(prev,preq);
        ans = add(ans,rem[idx]);
        cout << ans%mod << endl;
    }
}
void no_one(vector<int> &a){
    const int n = a.size();
    int preq = 0;
    for(int i=0;i<n;i++){
        int x = a[i];
        if(i!=n-1){
            if(x%2)
                x--;
            preq = add(preq,x);
        }else{
            if(x%2==0)
                x--;
            preq = add(preq,x);
        }
    }
    
    vector<int> rem(n);
    int curr = 0;
    for(int i=0;i<n;i++){
        int x = a[i];
        curr = add(curr,x);
        rem[i] = curr;
        if(x%2)
            curr = sub(curr,1);
    }
    int q;
    cin >> q;
    for(int i = 0;i<q;i++){
        int prev,r;
        cin >> r;
        int idx = get_idx(prev,r,n);
        int ans = mul(prev,preq);
        ans = add(ans,rem[idx]);
        cout << ans%mod << endl;
    }
}

void general(vector<int> &a){
    const int n = a.size();
    int one_idx = -1;
    for(int i=0;i<n;i++){
        if(a[i] == 1){
            one_idx = i;
            break;
        }
    }
    if(one_idx == -1)
        no_one(a);
    else 
        yes_one(a,one_idx);

}
void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &x:a) cin >> x;
    if(n==1){
        single(a);
    }else if(a[0]==1){
        first_one(a);
    }else if(a[n-1]==1){
        last_one(a);
    }else 
        general(a);

}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}