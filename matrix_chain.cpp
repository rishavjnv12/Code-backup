#include <bits/stdc++.h>
#define INF INT_MAX

using namespace std;
void print(vector<vector<int>> s,int i,int j){
    if(i==j){
        cout<<i+1;
    }else{
        cout<<"(";
        print(s,i,s[i][j]);
        print(s,s[i][j]+1,j);
        cout<<")";
    }
}
void matrix_chain_order(vector<int> p){
    int n=p.size()-1;//n=6
    vector<vector<int>>m(n,vector<int>(n,0));
    vector<vector<int>>s(n,vector<int>(n,0));
    for(int i=0;i<n;i++){
        m[i][i]=0;
    }
    for(int l=2;l<=n;l++){
        for(int i=0;i<n-l+1;i++){
            int j=i+l-1;
            m[i][j]=INF;
            for(int k=i;k<j;k++){
                int q=m[i][k]+m[k+1][j]+p[i]*p[k+1]*p[j+1];
                if(q<m[i][j]){
                    m[i][j]=q;
                    s[i][j]=k;
                }
            }
        }
    }

    print(s,0,n-1);
    cout<<endl;
    // for(int i=0;i<m.size();i++){
    //     for(int j=0;j<m[i].size();j++){
    //         cout<<m[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }

    // for(int i=0;i<m.size();i++){
    //     for(int j=0;j<m[i].size();j++){
    //         cout<<s[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
}
int main(){
    // int n=6;
    vector<int> dimension={30,35,15,5,10,20,25};
    matrix_chain_order(dimension);
    return 0;
}   