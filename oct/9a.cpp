#include <bits/stdc++.h>

using namespace std;

vector<vector<long long>> graph(5001,vector<long long>(5001,INT_MAX));

int get_node(int x,int y){
    x+=10;
    return x*11 + y;
}
void util(int x,int y){
    if(x<0 or y<0)
        return;
    graph[x][y] = graph[y][x] = 1;
}
void fill_edge(int x,int y){
    int n = get_node(x,y);
    graph[n][n] = 0;
    int north_x = x,north_y = y + 2*x;
    int south_x = x,south_y = y - 2*x;
    int east_x = x+2*y,east_y = y;
    int west_x = x-2*y,west_y = y;
    if(north_y<0){
        north_x*=-1;
        north_y*=-1;
    }
    if(south_y<0){
        south_x*=-1;
        south_y*=-1;
    }
    int north = get_node(north_x, north_y);
    int south = get_node(south_x, south_y);
    int east = get_node(east_x, east_y);
    int west = get_node(west_x, west_y);
    util(n,north);
    util(n,south);
    util(n,east);
    util(n,west);
    
    
}
void pre(){
    for(int x=-10;x<=10;x++){
        for(int y=0;y<=10;y++){
            if(x%2 and y%2 and __gcd(x,y)==1)   
            // cout<< x<<":"<<y<<":->"<<get_node(x,y)<<endl;
                fill_edge(x,y);
        }
    }
    for(int k = 0;k<500;k++){
        for(int i = 0;i<500;i++){
            for(int j = 0;j<500;j++){
                if(graph[i][k]+graph[k][j] < graph[i][j])
                    graph[i][j] = graph[i][k] + graph[k][j];
            }
        }
    }
}
void solve(){
    int x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    int src = get_node(x1,y1);
    int dest = get_node(x2,y2);
    // cout<<src<<" "<<dest<<endl;
    cout<<graph[src][dest]<<endl;
}

int32_t main(){
    pre();
    int t;
    cin>>t;
    while (t--)
        solve();
    return 0;
}