#include<bits/stdc++.h>
#define int long long int
using namespace std;
#define num_after suff
#define my_line last_line
int32_t main(){
        int t;
        cin >> t;
        while(t--){
            int n; 
        cin>>n;
        vector<vector<int>> ants(n);
        vector<vector<int>> pos(n), neg(n);
        int ans_no_col = 0;
        map<int,int> mp;   
        set<int> pnt;
        map<int,int> last_line;
        for(int i=0;i<n;i++){
            int m;
            cin >> m;
            ants[i].resize(m);
            for(int j=0;j<m;j++){
                cin >> ants[i][j];
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<ants[i].size();j++){
                int x=ants[i][j]; 
                if(x<0) {
                    neg[i].push_back(-x);
                    mp[-x]++;
                    pnt.insert(-1*x);
                    last_line[-x] = -i;
                }else{
                    pos[i].push_back(x);
                    mp[x]++; 
                    pnt.insert(x);
                    last_line[x] = i;
                }
            }
        }
        for(int i=0;i<n;i++){
            ans_no_col+=(pos[i].size()*neg[i].size());
        }
        for(int i=0;i<n;i++){
            sort(pos[i].begin(),pos[i].end());
            sort(neg[i].begin(),neg[i].end());
        }
        map<pair<int, int>, int> findpos,findneg; 
        for(int l=0;l<n;l++){
        vector<int> p = pos[l];
        vector<int> n = neg[l];
            int i=0,j=0;
        int ps = p.size(), ng = n.size();
        while(i<ps && j<ng){
                findpos[{l,p[i]}] = 0;
                findneg[{-l,n[j]}] = 0;
                if(n[j]>p[i]){
                    findpos[{l,p[i]}] = ng-j;
                    i++;
                } else if(n[j]==p[i]) {
                    i++, j++;
                } else {
                    findneg[{-l,n[j]}] = ps-i;
                    j++;
                }
            }
        }
        map<int,int> suff;
        for(int i=0;i<n;i++){
            int sz = pos[i].size()-1;
            for(int x: pos[i]){
                if(sz<0) break;
                suff[x]+=sz;
                sz--;
            }
            sz = neg[i].size()-1;
            for(int x: neg[i]){
                if(sz<0) break;
                suff[x]+=sz;
                sz--;
            }

        }
        int ans = 0;
        // for(int p: pnt){
        //     if(mp[p]>1){
        //         ans++;
        //         int line_with_one = suff[p];
        //         ans+=line_with_one;
        //     } else {
        //     int line = last_line[p];
        //     int v;
        //     if(line<0) {
        //         int modLine = -line;
        //         int curr = 0;
        //             curr = findneg[{line,p}];            
        //         if(curr>=1){
        //             ans+=curr;
        //         }
        //     } else {
        //         int curr = 0;
        //             curr = findpos[{line,p}]; 
        //         if(curr>=1){
        //             ans+=curr;
        //         }
        //     }
        //     }
        // }
        for(int p: pnt){
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

    cout<<ans<<"\n";
        cout<<ans<<"\n";
    }
    return 0;
}