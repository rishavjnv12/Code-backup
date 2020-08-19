#include <bits/stdc++.h>
#define ios ios_base::sync_with_stdio(false);cin.tie(NULL)
#define int long long
#define cout(x) cout<<x<<endl
#define cin(x) cin>>x
#define cin2(x,y) cin>>x>>y
#define cin3(x,y,z) cin>>x>>y>>z
#define for(i,n) for(int i=0;i<n;i++)


using namespace std;

int32_t main()
{
    ios;
    int t;
    int total=0;
    cin>>t;
    while(t--){
        int n;
        cin(n);
        //int profit=0;
        //int arr[4][4];
        vector<vector<int>>arr(4,vector<int>(4,0));
        for(i,n){
            char c;
            int st;
            cin2(c,st);
            arr[c-'A'][(st%12)/3]++;
        }
        /*for(i,4){
            for(j,4){
                cout<<arr[i][j]<<" ";
            }
            cout<<endl;
        }*/
        int profit=INT_MIN,ans;
        vector<int> perm{0,1,2,3};
        do{
            vector<int> v;
            ans=0;
            int id1,id2,id3;
            int maximum=INT_MIN;
            for(i,4){
                //cout(arr[i][0]);
                if(arr[i][perm[0]]>maximum){
                    maximum=arr[i][perm[0]];
                    id1=i;
                }
            }
            //cout(maximum);
            v.push_back(maximum);
            if(!maximum) id1=-1;
            maximum=INT_MIN;
            for(i,4){
                if(arr[i][perm[1]]>maximum and i!=id1){
                    maximum=arr[i][perm[1]];
                    id2=i;
                }
            }
            v.push_back(maximum);
            //(maximum)?ans+=50*maximum:ans-=25;
            if(!maximum) id2=-1;
            maximum=INT_MIN;
            for(i,4){
                if(arr[i][perm[2]]>maximum and i!=id1 and i!=id2){
                    maximum=arr[i][perm[2]];
                    id3=i;
                }
            }
            v.push_back(maximum);
            if(!maximum) id3=-1;
            //(maximum)?ans+=50*maximum:ans-=25;
            maximum=INT_MIN;
            for(i,4){
                if(arr[i][perm[3]]>maximum and i!=id1 and i!=id2 and i!=id3){
                    maximum=arr[i][perm[3]];
                }
            }
            v.push_back(maximum);
            //(maximum)?ans+=25*maximum:ans-=25;
            sort(v.begin(),v.end());
            /*int z=0;
            int i=0;
            for(i,4){
                cout<<v[i]<<" ";
            }*/
            int i=0;
            while(i<4 and v[i]==0) i++;
            ans=v[0]*25+v[1]*50+v[2]*75+v[3]*100;
            switch(i){
                case 0:ans=ans;break;
                case 1:ans=ans-100;break;
                case 2:ans=ans-200;break;
                case 3:ans=ans-300;break;
                case 4:ans=ans-400;break;
            }
            profit=max(profit,ans);
        }while(next_permutation(perm.begin(),perm.end()));
        
        cout(profit);
        total+=profit;
    }
    cout(total);
    return 0;
}