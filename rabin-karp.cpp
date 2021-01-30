#include <bits/stdc++.h>
using namespace std;
int rabin_karp(string text,string pat){
    const int p = 31;
    const int mod = 1e9+7;
    int s = pat.size(), t = text.size();
    vector<long long> p_pow(max(s,t));
    p_pow[0] = 1;
    for(int i=1;i<(int)p_pow.size();i++){
        p_pow[i] = (p_pow[i-1]*p) % mod;
    }
    vector<long long> h(t+1,0);
    for (int i = 0; i < t; i++)
        h[i+1] = (h[i] + (text[i] - 'a' + 1) * p_pow[i]) % mod;

    long long h_s = 0;
    for(int i = 0;i<s;i++)
        h_s = (h_s + (pat[i]-'a'+1)*p_pow[i])%mod;
    
    int ans = 0;
    for(int i = 0;i+s-1<t;i++){
        long long curr_hash = (h[i+s]+mod-h[i])%mod;
        if(curr_hash == h_s * p_pow[i] % mod)
            ans++;
    }
    return ans;
}
int main(){
    string text = "abababa";
    string pattern = "baba";
    cout << rabin_karp(text,pattern) << endl;
    return 0;
}