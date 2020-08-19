
// An utility function to add an edge in an 
// undirected graph. 
void addEdge(vector<int> v[], 
			int x, 
			int y) 
{ 
	v[x].push_back(y); 
	v[y].push_back(x); 
} 

// A function to print the path between 
// the given pair of nodes. 
void printPath(vector<int> stack) 
{ 
	int i; 
	for (i = 0; i < (int)stack.size() - 1; 
		i++) { 
		cout << stack[i] << " -> "; 
	} 
	cout << stack[i]; 
} 

// An utility function to do 
// DFS of graph recursively 
// from a given vertex x. 
void DFS(vector<int> v[], 
		bool vis[], 
		int x, 
		int y, 
		vector<int> &stack) 
{ 
	stack.push_back(x); 
	if (x == y) { 

		// print the path and return on 
		// reaching the destination node 
		printPath(stack); 
		return; 
	} 
	vis[x] = true; 

	// A flag variable to keep track 
	// if backtracking is taking place 
	int flag = 0; 
	if (!v[x].empty()) { 
		for (int j = 0; j < v[x].size(); j++) { 
			// if the node is not visited 
			if (vis[v[x][j]] == false) { 
				DFS(v, vis, v[x][j], y, stack); 
				flag = 1; 
			} 
		} 
	} 
	if (flag == 0) { 

		// If backtracking is taking 
		// place then pop 
		stack.pop_back(); 
	} 
} 

// A utility function to initialise 
// visited for the node and call 
// DFS function for a given vertex x. 
void DFSCall(int x, 
			int y, 
			vector<int> v[], 
			int n, 
			vector<int> &stack) 
{ 
	// visited array 
	bool vis[n + 1]; 

	memset(vis, false, sizeof(vis)); 

	// DFS function call 
	DFS(v, vis, x, y, stack); 
} 

// Driver Code 
int32_t main() 
{ 
	int t;
	cin(t);
	while(t--){
	    int n;
	    cin(n);
	    vector<int> v[n], stack;
	    for(int i=0;i<n-1;i++){
	        int u,w;
	        cin2(u,w);
	        addEdge(v,u,w);
	    }
	    vector<int>cost(n);
	    for(int i=0;i<n;i++){
	        cin(cost[i]);
	    }
	    int q;
	    cin(q);
	    while(q--){
	        int u,w;
	        cin2(u,w);
	        DFSCall(u,w, v, n, stack); 
	    }
	}
	
	
	
	
	

	return 0; 
} 
