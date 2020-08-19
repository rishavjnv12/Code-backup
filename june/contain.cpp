#include <bits/stdc++.h>
#define ios ios_base::sync_with_stdio(false);cin.tie(NULL)
#define int long long
#define mod 1000000007
#define INF 1000000000
#define endl '\n'
#define cout(x) cout<<x<<'\n'
#define debug(x) cout<<x<<'\n\n'
#define cin(x) cin>>x
#define cin2(x,y) cin>>x>>y
#define cin3(x,y,z) cin>>x>>y>>z


using namespace std;

struct Point{
    int x,y;
};

int orientation(Point p, Point q, Point r){ 
    int val = (q.y - p.y) * (r.x - q.x) - 
              (q.x - p.x) * (r.y - q.y); 
  
    if (val == 0) return 0;  // colinear 
    return (val > 0)? 1: 2; // clock or counterclock wise 
}


vector<Point> convexHull(vector<Point>points) 
{ 
    // There must be at least 3 points 
    auto n=points.size();

    if (n < 3) return {}; 
  
    // Initialize Result 
    vector<Point> hull; 
  
    // Find the leftmost point 
    int l = 0; 
    for (int i = 1; i < n; i++) 
        if (points[i].x < points[l].x) 
            l = i; 
  
    // Start from leftmost point, keep moving counterclockwise 
    // until reach the start point again.  This loop runs O(h) 
    // times where h is number of points in result or output. 
    int p = l, q; 
    do
    { 
        // Add current point to result 
        hull.push_back(points[p]); 
  
        // Search for a point 'q' such that orientation(p, x, 
        // q) is counterclockwise for all points 'x'. The idea 
        // is to keep track of last visited most counterclock- 
        // wise point in q. If any point 'i' is more counterclock- 
        // wise than q, then update q. 
        q = (p+1)%n; 
        for (int i = 0; i < n; i++) 
        { 
           // If i is more counterclockwise than current q, then 
           // update q 
           if (orientation(points[p], points[i], points[q]) == 2) 
               q = i; 
        } 

        p = q; 
  
    } while (p != l);  

    return hull;
    // for (int i = 0; i < hull.size(); i++) 
    //     cout << "(" << hull[i].x << ", "
    //           << hull[i].y << ")\n"; 
}
int32_t main(){
    vector<Point> points={{0, 3}, {2, 2}, {1, 1}, {2, 1}, 
                      {3, 0}, {0, 0}, {3, 3}};
 

    auto ans=convexHull(points);
    for (int i = 0; i < ans.size(); i++) 
        cout << "(" << ans[i].x << ", "
              << ans[i].y << ")\n"; 

    return 0;
}