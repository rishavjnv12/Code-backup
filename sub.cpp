#include <bits/stdc++.h>
using namespace std;

void solve(){
	int n;
	cin >> n;
	vector<int> a(n);
	for(int &x:a) cin >> x;
	for(int i=1;i<n;i++) a[i]+=a[i-1];
	int m;
	cin >> m;
	vector<int> b(m);
	for(int &x:b) cin >> x;
	for(int i=1;i<m;i++) b[i]+=b[i-1];
	int ans = max(0,*max_element(a.begin(),a.end()));
	ans +=max(0,*max_element(b.begin(),b.end()));
	cout << ans << endl;
}
int main() {
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}

