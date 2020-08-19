#include <bits/stdc++.h>
#define ios ios_base::sync_with_stdio(false);cin.tie(NULL)
#define int long long
#define cout(x) cout<<x<<endl
#define cin(x) cin>>x
#define cin2(x,y) cin>>x>>y
#define cin3(x,y,z) cin>>x>>y>>z


using namespace std;
int32_t main()
{
    ios;
    int t,s;
    cin>>t>>s;
    while(t--){
        if(s==1){
            int n;
            cin(n);
            multiset<int>a;
            multiset<int>b;
            map<int,bool> ontable;
            for(int i=0;i<n;i++){
                int temp;
                cin(temp);
                a.insert(temp);
            }
            for(int i=0;i<n;i++){
                int temp;
                cin(temp);
                b.insert(temp);
            }
            bool aa=true;
            ontable.insert(make_pair(*(a.begin()),true));
            a.erase(a.begin());
            for(int i=0;i<n;i++){
                auto itr1=b.begin();
                while(*(itr1)<=(*(ontable.end())).first){
                    itr1++;
                    if(itr1==b.end()){
                        break;
                    }
                }
                if(itr1==b.end()){
                    aa=false;
                    break;
                }else{
                    
                }
            }
            
        }


    }
    return 0;
}









//1 1 2
//2 3 3