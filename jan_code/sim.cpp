#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &x:a) cin>>x;
    sort(a.begin(),a.end());
    vector<string> d(n);
    for(int i=0;i<n;i++){
        if(a[i] < 0) d[i] = "LTR";
        else d[i] = "RTL";
    }
    int count = 0;
    int curr = 0;
    
    do{
        curr = 0;
        for(int i=0;i<n-1;i++){
            if(d[i]=="LTR" and d[i+1]=="RTL"){
                curr++;
                swap(d[i],d[i+1]);
                i++;
            }
        }
        count+=curr;
    }while(curr>0);
    for(int i=0;i<n;i++){
        cout << d[i] << " ";
    }
    cout << endl;
    cout << count << endl;
    return 0;
}