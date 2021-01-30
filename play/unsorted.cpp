#include <bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> v){
    if(is_sorted(v.begin(),v.end()))
        return {-1};
    
	int n = v.size();
	int i = 0, j = n-1;
	while(v[i] <= v[i + 1]){
		i++;
	}
	while(v[j] >= v[j - 1]){
		j--;
	}

	int mn = v[i + 1], mx = v[i + 1];
	for(int k = i; k <= j; k++){
		mx = max(mx, v[k]);
		mn = min(mn, v[k]);
	}
	int l = 0, r = n - 1;
	while(v[l] <= mn and l <= i){
	   	l++;
	}
	while(v[r] >= mx and r >= j){
		r--;
	}
	return {l,r};
}

int main(){
    vector<int> v = {4, 15, 4, 4, 15, 18, 20};
    auto ans = solve(v);
    for(int x:ans)
        cout << x << " ";
    cout << endl;
    return 0;
}