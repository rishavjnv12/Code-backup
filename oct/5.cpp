// A C++ program for Prim's Minimum 
// Spanning Tree (MST) algorithm. The program is 
// for adjacency matrix representation of the graph 
#include <bits/stdc++.h>
using namespace std;

int get_edge_weight(vector<int> a,vector<int> b){
    int n = a.size();
    int ans = 0;
    for(int i=0;i<n;i++){
        ans+=abs(a[i]-b[i]);
    }
    return ans;
}
// Number of vertices in the graph 

// A utility function to find the vertex with 
// minimum key value, from the set of vertices 
// not yet included in MST 
int minKey(int key[], bool mstSet[], int V) 
{ 
	// Initialize min value 
	int min = INT_MIN, min_index; 

	for (int v = 0; v < V; v++) 
		if (mstSet[v] == false && key[v] > min) 
			min = key[v], min_index = v; 

	return min_index; 
} 

// A utility function to print the 
// constructed MST stored in parent[] 
void printMST(int parent[], vector<vector<int>> graph) 
{ 
    int V = graph.size();
    int ans = 0;
	// cout<<"Edge \tWeight\n"; 
	for (int i = 1; i < V; i++) {
        ans += graph[i][parent[i]];
		cout<<parent[i]<<" - "<<i<<" \t"<<graph[i][parent[i]]<<" \n"; 
	}
    cout<<ans<<endl;
} 

// Function to construct and print MST for 
// a graph represented using adjacency 
// matrix representation 
void primMST(vector<vector<int>> graph)
{ 
	// Array to store constructed MST 
    int V = graph.size();
	int parent[V]; 
	
	// Key values used to pick minimum weight edge in cut 
	int key[V]; 
	
	// To represent set of vertices included in MST 
	bool mstSet[V]; 

	// Initialize all keys as INFINITE 
	for (int i = 0; i < V; i++) 
		key[i] = INT_MIN, mstSet[i] = false; 

	// Always include first 1st vertex in MST. 
	// Make key 0 so that this vertex is picked as first vertex. 
	key[0] = 0; 
	parent[0] = -1; // First node is always root of MST 

	// The MST will have V vertices 
	for (int count = 0; count < V - 1; count++)
	{ 
		// Pick the minimum key vertex from the 
		// set of vertices not yet included in MST 
		int u = minKey(key, mstSet, V); 

		// Add the picked vertex to the MST Set 
		mstSet[u] = true; 
		for (int v = 0; v < V; v++) 

			// graph[u][v] is non zero only for adjacent vertices of m 
			// mstSet[v] is false for vertices not yet included in MST 
			// Update the key only if graph[u][v] is smaller than key[v] 
			if (graph[u][v] && mstSet[v] == false && graph[u][v] > key[v]) 
				parent[v] = u, key[v] = graph[u][v]; 
	} 

	// print the constructed MST 
	printMST(parent, graph); 
} 

// Driver code
// int main() 
// { 

// 	int graph[V][V] = { { 0, 2, 0, 6, 0 }, 
// 						{ 2, 0, 3, 8, 5 }, 
// 						{ 0, 3, 0, 0, 7 }, 
// 						{ 6, 8, 0, 0, 9 }, 
// 						{ 0, 5, 7, 9, 0 } }; 

// 	// Print the solution 
// 	primMST(graph); 

// 	return 0; 
// } 

int main(){
    int n,d;
    scanf("%d%d", &n,&d);
    vector<vector<int>> g(n,vector<int>(d));
    for(int i=0; i < n; i++){
        for(int j=0; j < d; j++)
            cin>>g[i][j];
    }
    vector<vector<int>> graph(n,vector<int>(n,0));
    for(int i = 0;i<n;i++){
        for(int j = 0; j < n;j++){
            graph[i][j] = get_edge_weight(g[i],g[j]);
        }
    }
    primMST(graph);
}
// This code is contributed by rathbhupendra
