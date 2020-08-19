#include <bits/stdc++.h>
using namespace std;
int matrix_search(vector<vector<int> > A, int B){
    int low=0;
    int high=A.size()-1;
    while(high>=low){
        int mid=(high+low)/2;
        if(A[mid][0]>B and A[mid][A[mid].size()-1]>B){
            high=mid-1;
        }else if(A[mid][0]<B and A[mid][A[mid].size()-1]<B){
            low=mid+1;
        }else{
            return binary_search(A[mid].begin(),A[mid].end(),B);
        }
    }
    return 0;
}
int main(){
    vector<vector<int>> A= { {1,   3,  5,  7},
      {10, 11, 16, 20},
      {23, 30, 34, 50}  };
    int n=11;
    cout<<matrix_search(A,n)<<endl;
    return 0;
}