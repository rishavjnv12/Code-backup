#include <bits/stdc++.h>
#define ios ios_base::sync_with_stdio(false);cin.tie(NULL)
#define mod 1000000007
#define INF INT_MAX
#define int long long
#define endl '\n'
#define cout(x) cout<<x<<'\n'
#define debug(x) cout<<x<<'\n\n'
#define cin(x) cin>>x
#define cin2(x,y) cin>>x>>y
#define cin3(x,y,z) cin>>x>>y>>z
int V;

using namespace std;
int fact(int n){
    return !n?1:n*fact(n-1);
}
string vectostr(vector<int> v){
    string ans="";
    for(int i=0;i<v.size();i++){
        ans+=to_string(v[i]);
    }
    return ans;
}
string source(int n){
    switch(n){
        case 0: return "";
        case 1: return "1";
        case 2: return "12";
        case 3: return "123";
        case 4: return "1234";
        case 5: return "12345";
    }
}
string swap_temp(string s,int i,int j){
    string temp=s;
    swap(temp[i],temp[j]);
    return temp;
}
void printSolution(int dist[]) 
{ 
    printf("Vertex \t\t Distance from Source\n"); 
    for (int i = 0; i < V; i++) 
        printf("%d \t\t %d\n", i, dist[i]); 
} 
int minDistance(int dist[], bool sptSet[]) 
{ 
    // Initialize min value 
    int min = INT_MAX, min_index; 
  
    for (int v = 0; v < V; v++) 
        if (sptSet[v] == false && dist[v] <= min) 
            min = dist[v], min_index = v; 
  
    return min_index; 
}
void dijkstra(vector<vector<int>>graph, int src,int target) 
{ 
    int dist[V]; 
  
    bool sptSet[V]; 
    for (int i = 0; i < V; i++) 
        dist[i] = INT_MAX, sptSet[i] = false; 


    dist[src] = 0; 
    for (int count = 0; count < V - 1; count++) { 
        int u = minDistance(dist, sptSet); 
        sptSet[u] = true; 
        for (int v = 0; v < V; v++) 
            if (!sptSet[v] && graph[u][v]!=INT_MAX && dist[u] != INT_MAX 
                && dist[u] + graph[u][v] < dist[v]) 
                dist[v] = dist[u] + graph[u][v]; 
    }  
    // printSolution(dist);
    cout<<dist[target]<<endl; 
}

int minSwaps(int arr[], int n) 
{ 
    // Create an array of pairs where first 
    // element is array element and second element 
    // is position of first element 
    pair<int, int> arrPos[n]; 
    for (int i = 0; i < n; i++) 
    { 
        arrPos[i].first = arr[i]; 
        arrPos[i].second = i; 
    } 
  
    // Sort the array by array element values to 
    // get right position of every element as second 
    // element of pair. 
    sort(arrPos, arrPos + n); 
  
    // To keep track of visited elements. Initialize 
    // all elements as not visited or false. 
    vector<bool> vis(n, false); 
  
    // Initialize result 
    int ans = 0; 
  
    // Traverse array elements 
    for (int i = 0; i < n; i++) 
    { 
        // already swapped and corrected or 
        // already present at correct pos 
        if (vis[i] || arrPos[i].second == i) 
            continue; 
  
        // find out the number of  node in 
        // this cycle and add in ans 
        int cycle_size = 0; 
        int j = i; 
        while (!vis[j]) 
        { 
            vis[j] = 1; 
  
            // move to next node 
            j = arrPos[j].second; 
            cycle_size++; 
        } 
  
        // Update answer by adding current cycle.  
        if (cycle_size > 0) 
        { 
            ans += (cycle_size - 1); 
        } 
    } 
  
    // Return result 
    return ans; 
}
int32_t main(){
    ios;
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        if(m==0){
            int arr[n];
            for(int i=0;i<n;i++){
                cin>>arr[i];
            }
            cout << minSwaps(arr, n)<<endl;
            continue;
        }
        int nodes=fact(n);
        V=nodes;
        vector<vector<int>> graph(nodes,vector<int>(nodes,INT_MAX));
        vector<int> perm(n);
        for(int i=0;i<perm.size();i++){
            cin(perm[i]);
        }
        vector<vector<int>>swap_info(n,vector<int>(n,0));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j) swap_info[i][j]=0;
                else swap_info[i][j]=1;
            }
        }
        while(m--){
            int u,v;
            cin2(u,v);

            swap_info[u-1][v-1]=0;
            swap_info[v-1][u-1]=0;
            
        }
        unordered_map<string,int> mp; //perm_to_node
        string source_string=source(n);
        string target_string=vectostr(perm);
        string temp=source_string;
        // cout(source_string);
        // cout(target_string);
        // mapping of node
        int i=0;
        do{
            mp[temp]=i;
            i++;
            // cout<<temp<<":"<<mp[temp]<<endl;
        }while(next_permutation(temp.begin(),temp.end()));
        // filling graph
        temp=source_string;
        do{
            for(int i=0;i<n;i++){
                for(int j=i;j<n;j++){
                    string reach=swap_temp(temp,i,j);
                    if(swap_info[i][j]==1){
                        graph[mp[temp]][mp[reach]]=1;
                        graph[mp[reach]][mp[temp]]=1;
                    }else{
                        graph[mp[temp]][mp[reach]]=0;
                        graph[mp[reach]][mp[temp]]=0;
                    }
                }
            }
        }while(next_permutation(temp.begin(),temp.end()));

        // for(int i=0;i<graph.size();i++){
        //     for(int j=0;j<graph[i].size();j++){
        //         cout<<graph[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }

        // cout<<"djkfh"<<mp[target_string]<<"hscg"<<endl;
        dijkstra(graph,mp[source_string],mp[target_string]);

    }
    return 0;
}