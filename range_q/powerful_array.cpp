// https://codeforces.com/problemset/problem/86/D

#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

const int BLK = 700;

struct query{
    int l;
    int r;
    int idx;
};

query q[200001];
int ans[200001];
int ar[200001];
int freq[1000001];
int power=0;

bool compare(query a,query b){
    if(a.l/BLK!=b.l/BLK){
        return a.l/BLK < b.l/BLK;
    }
    return a.r < b.r;
}
void add(int pos){
    int count=freq[ar[pos]];
    freq[ar[pos]]++;

    power-=(count*count)*ar[pos];
    count++;
    power+=(count*count)*ar[pos];
}

void remove(int pos){
    int count=freq[ar[pos]];
    freq[ar[pos]]--;

    power-=(count*count)*ar[pos];
    count--;
    power+=(count*count)*ar[pos];
    
}
int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,nq;
    cin>>n>>nq;
    for(int i=0;i<n;i++){
        cin>>ar[i];
    }
    for(int i=0;i<nq;i++){
        cin>>q[i].l>>q[i].r;
        q[i].l--;
        q[i].r--;
        q[i].idx=i;
    }
    sort(q,q+nq,compare);


    int ML=0,MR=-1;
    for(int i=0;i<nq;i++){
        int l=q[i].l;
        int r=q[i].r;

        while(ML>l){
            ML--;
            add(ML);
        }

        while(MR<r){
            MR++;
            add(MR);
        }

        while(ML<l){
            remove(ML);
            ML++;
        }

        while(MR>r){
            remove(MR);
            MR--;
        }

        ans[q[i].idx]=power;
    }

    for(int i=0;i<nq;i++){
        cout<<ans[i]<<endl;
    }
    return 0;
}
