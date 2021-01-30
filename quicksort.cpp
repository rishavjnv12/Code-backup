#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &v,int low,int high){
    int pivot = v[high];
    int i = low-1;
    for(int j=low;j<high;j++){
        if(v[j] <= pivot){
            i++;
            swap(v[i],v[j]);
        }
    }
    swap(v[i+1],v[high]);
    return i+1;
}

void quicksort(vector<int>& v,int low,int high){
    if(low < high){
        int pi = partition(v,low,high);
        quicksort(v,low,pi-1);
        quicksort(v,pi+1,high);
    }
}
int main(){
    vector<int> a ={1,3,2,132,54,32,45,32,23,21,56,311,687};
    quicksort(a,0,a.size()-1);
    for(int x:a)
        cout << x << " ";
    cout << endl;
    return 0;
}