// https://www.spoj.com/problems/FREQ2/

#include <bits/stdc++.h>


using namespace std;
struct query{
    int l;
    int r;
    int idx;
};
bool comp(query a,query b){

}
int a[100001];
query qs[100001];
int main(){
    int n,q;
    cin>>n>>q;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<q;i++){
        cin>>qs[i].l>>qs[i].r;
        qs[i].idx=i;
    }
    return 0;
}