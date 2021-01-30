#include <bits/stdc++.h>
using namespace std;

void subtask_one(){
    int m;
    cin >> m;
    vector<int> neg,pos;
    while(m--){
        int x;
        cin >> x;
        if(x<0)
            neg.push_back(x);
        else pos.push_back(x);
    }
    int ans = neg.size()*pos.size();
    cout << ans << endl;
}

void solve(){
    int n;
    cin >> n;
    if(n==1){
        subtask_one();
        return;
    }
    vector<vector<int>> ants(n+1);
    for(int i=1;i<=n;i++){
        int m;
        cin >> m;
        while(m--){
            int x;
            cin >> x;
            ants[i].push_back(x);
        }
    }
    vector<vector<int>> pos(n+1),neg(n+1);
    map<int,int> mp,pnt;
    vector<int> points;
    map<int,int> my_line;
    for(int i=1;i<=n;i++){
        for(int j=0;j<(int)ants[i].size();i++){
            if(ants[i][j]>0){
                pos[i].push_back(ants[i][j]);
                mp[ants[i][j]]++;
                if(!pnt.count(ants[i][j])){
                    points.push_back(ants[i][j]);
                    pnt[ants[i][j]] = 1; 
                }
                my_line[ants[i][j]] = i;
            }else{
                neg[i].push_back(abs(ants[i][j]));
                mp[abs(ants[i][j])]++;
                if(!pnt.count(abs(ants[i][j]))){
                    points.push_back(abs(ants[i][j]));
                    pnt[-1*ants[i][j]] = 1; 
                }
                my_line[-1*ants[i][j]] = -1*i;
            }
        }
    }
    for(auto &v:neg){
        reverse(v.begin(),v.end());
    }
    map<pair<int,int>,int> findpos,findneg;
    for(int l=1;l<=n;l++){
        auto &p = pos[l],n=neg[l];
        int i = 0,j = 0;
        int ps = p.size(), ng = n.size();
        while(i<ps and j< ng){
            findpos[{l,p[i]}] = 0;
           if(n[j]>p[i]){
               findpos[{l,p[i]}] = ng-j;
               i++;
           }
           else if(n[j]==p[i]) {
               i++, j++;
           }
           else {
               j++;
           }
        }
        i=0, j=0;
        while(i<ps && j<ng){
            findneg[{-l,n[j]}] = 0;
            if(n[j]<p[i]){
                findneg[{-l,n[j]}] = ps-i;
                j++;
            }
            else if(n[j]==p[i]) {
                i++, j++;
            }
            else {
                i++;
            }
        }
    }
    map<int,int> num_after;
    for(int i=1;i<=n;i++){
        // pos
        auto& v = pos[i];
        int sz = pos[i].size();
        sz--;
        for(int x: v){
            if(sz<0) break;
            num_after[x]+=(sz--);
        }
        
        // neg
        auto& t = neg[i];
        sz = neg[i].size();
        sz--;
        for(int x: t){
            if(sz<0) break;
            num_after[x]+=(sz--);
        }

    }
    int ans = 0;

    for(int p: points){
        if(mp[p]>1){
            ans++;
            int line_with_one = num_after[p];
            ans+=line_with_one;
        }
         else {
           int line = my_line[p];
           int v;
           if(line<0) {
               int modLine = -line;
               int have = 0;
                   have = findneg[{line,p}];
                 // no. of values greater than p in this opposite vector             
               if(have>=1){
                   ans++;
                   ans+=have-1;
               }
           }
           else {
               int have = 0;
                   have = findpos[{line,p}]; 
               if(have>=1){
                   ans++;
                   ans+=have-1;
               }
           }
         }
    }

}




int32_t main(){
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}