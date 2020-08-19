#include <bits/stdc++.h>
#define int long long

using namespace std;

const int MX = 1e12;

int optimal_z;
int result;
int x, y, l, r;

int f(int x, int y, int z) {
	return (x & z) * (y & z);
}

void update_ans(int z) {
	int cur = f(x, y, z);
	if (cur > result || (cur == result && z < optimal_z)) {
		optimal_z = z;
		result = cur;
	}
}

// void print_binary(int x) {
// 	string res = "";
// 	for (int i = 42; i >= 0; --i) {
// 		if (x & (1ll << i))
// 			res += "1";
// 		else
// 			res += "0";
// 	}
// 	cout << res << '\n';
// }



int32_t main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
    cin>>t;
    while(t--){
        optimal_z = r;
        result = f(x, y, optimal_z);
        update_ans(l);
        bool is_less = false;
        int bits_or = (x | y);

        for (int i = 42; i >= 0; --i) {
            int p = (1ll << i);
            if ((r & p) && (is_less || !(l & p))) {
                int cur = 0;
                for (int k = 42; k > i; --k) {
                    int p = (1ll << k);
                    if (r & p)
                        cur |= p;
                }
                bool is_bigger = is_less;
                for (int k = i - 1; k >= 0; --k) {
                    int p = (1ll << k);
                    if (!(l & p)) {
                        if (bits_or & p) {
                            cur |= p;
                            is_bigger = true;
                        }
                    } else {
                        if (!is_bigger || (bits_or & p))
                            cur |= p;
                    }
                }
                if (l <= cur && cur <= r)
                    update_ans(cur);
                is_less = true;
            }
        }
        printf("%lld\n", optimal_z);
    }
	return 0;
}