#include <bits/stdc++.h>
#define ios ios_base::sync_with_stdio(false);cin.tie(NULL)
#define int long long
#define cout(x) cout<<x<<"\n"
#define endl "\n"
#define cin(x) cin>>x
#define cin2(x,y) cin>>x>>y
#define cin3(x,y,z) cin>>x>>y>>z
#define MAX 10000001
#define MOD 998244353
#define mod 998244353
#define vi vector<int>

using namespace std;

int power(int a , int n){
	int res = 1;
	
	while(n)
	{
		if(n & 1)
			res = (res * a) % mod;
		
		n >>= 1;
		a = (a * a) % mod;
	}
	
	return res;
}
int add(int a , int b){
	return (a + b) % mod;
}

vi apply_operator(vi &a,vi &b, char &_operator){
    vi res(4,0);
	if(_operator == '|')
	{
		res[0] = add(res[0] , (a[0] * b[0]) % mod);
		res[1] = add(res[1] , (a[1] * b[0]) % mod);
		res[2] = add(res[2] , (a[2] * b[0]) % mod);
		res[3] = add(res[3] , (a[3] * b[0]) % mod);
		
		res[1] = add(res[1] , (a[0] * b[1]) % mod);
		res[1] = add(res[1] , (a[1] * b[1]) % mod);
		res[1] = add(res[1] , (a[2] * b[1]) % mod);
		res[1] = add(res[1] , (a[3] * b[1]) % mod);
		
		res[2] = add(res[2] , (a[0] * b[2]) % mod);
		res[1] = add(res[1] , (a[1] * b[2]) % mod);
		res[2] = add(res[2] , (a[2] * b[2]) % mod);
		res[1] = add(res[1] , (a[3] * b[2]) % mod);
		
		res[3] = add(res[3] , (a[0] * b[3]) % mod);
		res[1] = add(res[1] , (a[1] * b[3]) % mod);
		res[1] = add(res[1] , (a[2] * b[3]) % mod);
		res[3] = add(res[3] , (a[3] * b[3]) % mod);
	}
    if(_operator == '^')
	{
		res[0] = add(res[0] , (a[0] * b[0]) % mod);
		res[1] = add(res[1] , (a[1] * b[0]) % mod);
		res[2] = add(res[2] , (a[2] * b[0]) % mod);
		res[3] = add(res[3] , (a[3] * b[0]) % mod);
		
		res[1] = add(res[1] , (a[0] * b[1]) % mod);
		res[0] = add(res[0] , (a[1] * b[1]) % mod);
		res[3] = add(res[3] , (a[2] * b[1]) % mod);
		res[2] = add(res[2] , (a[3] * b[1]) % mod);
		
		res[2] = add(res[2] , (a[0] * b[2]) % mod);
		res[3] = add(res[3] , (a[1] * b[2]) % mod);
		res[0] = add(res[0] , (a[2] * b[2]) % mod);
		res[1] = add(res[1] , (a[3] * b[2]) % mod);
		
		res[3] = add(res[3] , (a[0] * b[3]) % mod);
		res[2] = add(res[2] , (a[1] * b[3]) % mod);
		res[1] = add(res[1] , (a[2] * b[3]) % mod);
		res[0] = add(res[0] , (a[3] * b[3]) % mod);
	}
    if(_operator == '&')
	{
		res[0] = add(res[0] , (a[0] * b[0]) % mod);
		res[0] = add(res[0] , (a[1] * b[0]) % mod);
		res[0] = add(res[0] , (a[2] * b[0]) % mod);
		res[0] = add(res[0] , (a[3] * b[0]) % mod);
		
		res[0] = add(res[0] , (a[0] * b[1]) % mod);
		res[1] = add(res[1] , (a[1] * b[1]) % mod);
		res[2] = add(res[2] , (a[2] * b[1]) % mod);
		res[3] = add(res[3] , (a[3] * b[1]) % mod);
		
		res[0] = add(res[0] , (a[0] * b[2]) % mod);
		res[2] = add(res[2] , (a[1] * b[2]) % mod);
		res[2] = add(res[2] , (a[2] * b[2]) % mod);
		res[0] = add(res[0] , (a[3] * b[2]) % mod);
		
		res[0] = add(res[0] , (a[0] * b[3]) % mod);
		res[3] = add(res[3] , (a[1] * b[3]) % mod);
		res[0] = add(res[0] , (a[2] * b[3]) % mod);
		res[3] = add(res[3] , (a[3] * b[3]) % mod);
	}
	
	return res;
}

vi get_res(string st){
    vi tmp(4,1);
    stack<vi> stk;
    stack<char> op_stack,par_stack;
    for(char ch:st){
        if(ch=='(')
            par_stack.push(ch);
        else if(ch=='&' or ch=='|' or ch=='^')
            op_stack.push(ch);
        else if(ch=='#')
            stk.push(tmp);
        else{
            vi a=stk.top();
            stk.pop();

            vi b=stk.top();
            stk.pop();

            char _operator=op_stack.top();
            op_stack.pop();
            par_stack.pop();

            stk.push(apply_operator(a,b,_operator));
        }
    }
    return stk.top();
}
int32_t main(){
    int t;
    cin(t);
    while(t--){
        string str;
        cin(str);
        int hash_count=0;
        for(auto i: str){
            hash_count+=(i=='#');
        }
        vi res=get_res(str);
        int d=power(power(4,hash_count),MOD-2);

        cout<<(res[0]*d)%MOD<<" "<<(res[1]*d)%MOD<<" "<<(res[2]*d)%MOD<<" "<<(res[3]*d)%MOD<<"\n";

    }
    return 0;
}