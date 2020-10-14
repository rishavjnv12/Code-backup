#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using namespace boost::multiprecision;

int128_t get_dist(int128_t x1,int128_t y1,int128_t x2,int128_t y2,int128_t dist){

    if(x1==x2 and y1==y2)
        return 0;

    if(dist > 7)
        return INT_MAX;
    int128_t north_x = x1;
    int128_t north_y = y1+2*x1;
    int128_t south_x = x1;
    int128_t south_y = y1-2*x1;

    int128_t east_x = x1 + 2*y1;
    int128_t east_y = y1;
    int128_t west_x = x1 - 2*y1;
    int128_t west_y = y1;

    if(north_y <0){
        north_x *= -1;
        north_y *= -1;
    }

    if(south_y < 0){
        south_x *= -1;
        south_y *= -1;
    }
    dist++;
    int128_t north = get_dist(north_x, north_y,x2,y2,dist);
    int128_t south = get_dist(south_x, south_y,x2,y2,dist);
    int128_t east = get_dist(east_x, east_y,x2,y2,dist);
    int128_t west = get_dist(west_x, west_y,x2,y2,dist);

    return (int128_t)1+min({north, south,east,west});
}

void solve(){
    int128_t x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    int dist = 0;
    int128_t ans = get_dist(x1,y1,x2,y2,dist);
    cout<<ans<<endl;
}
int32_t main(){
    int t;
    cin>>t;
    while(t--)
        solve();
    return 0;
}