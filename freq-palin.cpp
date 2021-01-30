#include <bits/stdc++.h> 

using namespace std;
vector<int> count(int x,int y,vector<vector<int>> &freq){
    vector<int> cnt(26);
    if(!x){
        for(int i=0;i<26;i++) cnt[i] = freq[y][i];
    }else{
        for(int i=0;i<26;i++) cnt[i] = freq[y][i]-freq[x-1][i];
    }
    return cnt;
}

int32_t main(){
    string s;
    ios_base::sync_with_stdio(true);
    cin.tie(0);
    cin >> s;
    const int n = s.length();
    vector<vector<int>> freq(n,vector<int>(26,0));
    for(int i=0;i<n;i++){
        freq[i][s[i]-'a']++;
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<26;j++)
            freq[i][j]+=freq[i-1][j];
    }
    int q;
    cin >> q;
    while(q--){
        int x,y;
        cin >> x >> y;
        int sz = y-x+1;
        int mid;
        vector<int> left,right;
        if(sz%2 == 0){
            mid = (x+y)/2;
            left = count(x,mid,freq);
            right = count(mid+1,y,freq);
        }else{
            mid = (x+y)/2;
            left = count(x,mid-1,freq);
            right = count(mid+1,y,freq);
        }
        char ch = 'a';
        if(left == right) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}