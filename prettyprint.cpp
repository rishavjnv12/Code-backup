#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> prettyPrint(int A){
    int row=2*A-1;
    vector<vector<int>> ans;
    for(int i=0;i<A;i++){
        vector <int> temp(2*A-1);
        int curr=A;
        int mincurr=A-i;
        for(int i=0;i<=row/2;i++){
            temp[i]=curr;
            if(curr>mincurr)
                curr--;
        }
        for(int i=row/2+1;i<row;i++){
            temp[i]=temp[row-i-1];
        }
        ans.push_back(temp);
    }
    for(int i=A;i<row;i++){
        vector<int>temp;
        temp=ans[row-i-1];
        ans.push_back(temp);
    }
    return ans;
}
int main(){
    int n;
    vector<vector<int> >ans;
    cout<<"Enter n:";
    cin>>n;
    ans=prettyPrint(n);
    int d=floor(log10(n) + 1); 
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[0].size();j++){
            if(d==1)
                cout<<ans[i][j]<<" ";
            else if(d==2)
                printf("%2d ",ans[i][j]);
        }
        cout<<endl;
    }
    return 0;
}

// 0 1 2 3 4 

// 3 3 3 3 3 
// 3 2 2 2 3 
// 3 2 1 2 3 
// 3 2 2 2 3 
// 3 3 3 3 3 

//    0 1 2 3 4 5 6
// 0  4 4 4 4 4 4 4 
// 1  4 3 3 3 3 3 4 
// 2  4 3 2 2 2 3 4 
// 3  4 3 2 1 2 3 4 
// 4  4 3 2 2 2 3 4   i=4,row=7,A=4 row-i-1
// 5  4 3 3 3 3 3 4 
// 6  4 4 4 4 4 4 4 



