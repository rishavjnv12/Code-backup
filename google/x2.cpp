#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <array>
using namespace std;
typedef long long ll;
#define SZ(a) (int)(a).size()
 
const int maxp = 20;
 
struct Trie {
	vector<array<int,2>> t;
	Trie() {
		t.assign(1, {-1, -1});
	}
	int query(int x) {
		int ret = 0;
		int d = 0;
		for (int i = maxp-1; i >= 0; i--) {
			ret <<= 1;
			int b = x>>i & 1;
			if (t[d][b ^ 1] == -1) {
				d = t[d][b];
			}
			else {
				d = t[d][b ^ 1];
				ret++;
			}
		}
		return ret;
	}
	void insert(int x) {
		int d = 0;
		for (int i = maxp-1; i >= 0; i--) {
			int b = x>>i & 1;
			if (t[d][b] == -1) {
				t[d][b] = SZ(t);
				t.push_back({-1, -1});
			}
			d = t[d][b];
		}
	}
};
 
struct Sg {
	int n;
	vector<Trie> t;
	Sg(int n) : n(n) {
		t.resize(2*n);
	}
	int query(int l, int r, int x) {
		int ret = 0;
		for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
			if (l & 1) ret = max(ret, t[l++].query(x));
			if (r & 1) ret = max(ret, t[--r].query(x));
		}
		return ret;
	}
	void insert(int i, int x) {
		for (i += n; i > 0; i >>= 1) {
			t[i].insert(x);
		}
	}
};
 
 
void solve() {
	cin.sync_with_stdio(false);
	int n;
	cin >> n;
    vector<int> a(n);
    for(int i;i<n;i++){
        cin>>a[i];
    }
    sort(a.begin(),a.end());
	Sg sg(n);
	for (int i = 0; i < n; i++) {
		sg.insert(i, a[i]);
	}
	int nq;
	cin >> nq;
	for (int iq = 0; iq < nq; iq++) {
		int x,m;
        cin>>x>>m;
        int i=0;
        for(;i<n;i++){
            if(a[i]>m){
                break;
            }
        }

		auto ans = sg.query(0, i-1, x);
		printf("%d\n", ans^x);
	}
}
 

int main(){
    int t;
    cin>>t;
    while(t--) solve();
    return 0;
}