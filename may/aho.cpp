#include <bits/stdc++.h>
#define ios ios_base::sync_with_stdio(false);cin.tie(NULL)
#define mod 1000000007
#define INF 1000000000
#define endl '\n'
#define cout(x) cout<<x<<'\n'
#define debug(x) cout<<x<<'\n\n'
#define cin(x) cin>>x
#define cin2(x,y) cin>>x>>y
#define cin3(x,y,z) cin>>x>>y>>z


using namespace std;
const int MAXS = 1000; 

// Maximum number of characters in input alphabet 
const int MAXC = 26; 
int out[MAXS]; 
unordered_map<string,int> mpq;
int f[MAXS];
int g[MAXS][MAXC];
int buildMatchingMachine() 
{ 
	int k=mpq.size();
	// Initialize all values in output function as 0. 
	memset(out, 0, sizeof out); 

	// Initialize all values in goto function as -1. 
	memset(g, -1, sizeof g); 

	// Initially, we just have the 0 state 
	int states = 1; 
	int counter=0;
	for (auto i=mpq.begin(); i!=mpq.end(); ++i,counter++) 
	{ 
		const string &word = i->first; 
		int currentState = 0; 

		// Insert all characters of current word in arr[] 
		for (int j = 0; j < word.size(); ++j) 
		{ 
			int ch = word[j] - 'a';  
			if (g[currentState][ch] == -1) 
				g[currentState][ch] = states++; 

			currentState = g[currentState][ch]; 
		} 

		// Add current word in output function 
		out[currentState] |= (1 << counter); 
	} 

	// For all characters which don't have an edge from 
	// root (or state 0) in Trie, add a goto edge to state 
	// 0 itself 
	for (int ch = 0; ch < MAXC; ++ch) 
		if (g[0][ch] == -1) 
			g[0][ch] = 0; 
	memset(f, -1, sizeof f); 

	// Failure function is computed in breadth first order 
	// using a queue 
	queue<int> q; 
	for (int ch = 0; ch < MAXC; ++ch){
		if (g[0][ch] != 0) 
		{ 
			f[g[0][ch]] = 0; 
			q.push(g[0][ch]); 
		} 
	} 

	// Now queue has states 1 and 3 
	while (q.size()){ 
		int state = q.front(); 
		q.pop(); 
		for (int ch = 0; ch <= MAXC; ++ch){
			if (g[state][ch] != -1){ 
				int failure = f[state]; 
				while (g[failure][ch] == -1) 
					failure = f[failure]; 
				failure = g[failure][ch]; 
				f[g[state][ch]] = failure; 
				out[g[state][ch]] |= out[failure];  
				q.push(g[state][ch]); 
			} 
		} 
	} 
	return states; 
}
int findNextState(int currentState, char nextInput){ 
	int answer = currentState; 
	int ch = nextInput - 'a'; 
	while (g[answer][ch] == -1) 
		answer = f[answer];
	return g[answer][ch]; 
}
int searchWords(string text){ 
    int ans=0;
	int k=mpq.size();
	int currentState = 0; 
	for (int i = 0; i < text.size(); ++i){ 
		currentState = findNextState(currentState, text[i]);  
		if (out[currentState] == 0) 
			continue; 
		int counter=0;
		for (auto j = mpq.begin(); j!=mpq.end(); ++j,++counter){ 
			if(out[currentState]&(1<<counter)){ 
				ans+=mpq[j->first];
			} 
		} 
	} 
	return ans;
}
int32_t main(){
    ios;
    int t;
    cin>>t;
    while(t--){
        string a,b;
        cin2(a,b);
        int q;
        cin(q);
        for(int i=0;i<q;i++){
            string temp;
			int val;
			cin2(temp,val);
            mpq[temp]=val;
        }
		buildMatchingMachine(); 
		int max_pleasue=INT_MIN;
		string left="",right="";
        for(int i=0;i<a.size();i++){
			left=left+a[i];
			for(int j=b.size()-1;j>=0;j--){
				right=b[j]+right;
				cout<<left+right<<endl;
				max_pleasue=max(max_pleasue,searchWords(left+right));
			}
			right="";
		}
        cout(max_pleasue);
		mpq.clear();
    }
    return 0;
}