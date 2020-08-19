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

struct Point {
   int x, y;
   bool operator<(const Point &p) const{
       if(this->x == p.x){
           return this->y < p.y;
       }
       return this->x < p.x;
   }
};

struct line {
   Point p1, p2;
};
bool online(Point a,Point b,Point q){
    if((q.x==a.x and q.y==a.y) or (q.x==b.x and q.y==b.y)) return true;

	if(	(q.y-a.y)*(b.x-a.x)	==	(q.x-a.x)*(b.y-a.y)	){
		if(
			((q.x>=a.x and q.x<=b.x) or (q.x<=a.x and q.x>=b.x)) and
			((q.y>=a.y and q.y<=b.y) or (q.y<=a.y and q.y>=b.y))
		){
			return true;
		}else{
			// printf("h");
			return false;
		}
	}else{
		// printf("i");
		return false;
	}
}

bool onLine(line l1, Point p) {        //check whether p is on the line or not
   if(p.x <= max(l1.p1.x, l1.p2.x) && p.x <= min(l1.p1.x, l1.p2.x) &&
      (p.y <= max(l1.p1.y, l1.p2.y) && p.y <= min(l1.p1.y, l1.p2.y)))
         return true;

   return false;
}

int direction(Point a, Point b, Point c) {
   int val = (b.y-a.y)*(c.x-b.x)-(b.x-a.x)*(c.y-b.y);
   if (val == 0)
      return 0;           //colinear
   else if(val < 0)
      return 2;    
	  
	      //anti-clockwise direction
    return 1;          //clockwise direction
}

bool isIntersect(line l1, line l2) {
   //four direction for two lines and points of other line
   int dir1 = direction(l1.p1, l1.p2, l2.p1);
   int dir2 = direction(l1.p1, l1.p2, l2.p2);
   int dir3 = direction(l2.p1, l2.p2, l1.p1);
   int dir4 = direction(l2.p1, l2.p2, l1.p2);

   if(dir1 != dir2 && dir3 != dir4)
      return true;           //they are intersecting
   if(dir1==0 && onLine(l1, l2.p1))        //when p2 of line2 are on the line1
      return true;
   if(dir2==0 && onLine(l1, l2.p2))         //when p1 of line2 are on the line1
      return true;
   if(dir3==0 && onLine(l2, l1.p1))       //when p2 of line1 are on the line2
      return true;
   if(dir4==0 && onLine(l2, l1.p2)) //when p1 of line1 are on the line2
      return true;
   return false;
}

bool isInside(vector<Point> polygon, Point p) {

	int n=polygon.size();
    polygon.push_back(polygon[0]);
    for(int i=1;i<=n;i++){
        if(online(polygon[i], polygon[i-1], p)){
            // printf("h");
            return false;
        }
    }
    polygon.pop_back();


   if(n < 3)
      return false;                  //when polygon has less than 3 edge, it is not polygon
   line exline = {p, {9999, p.y}};   //create a point at infinity, y is same as point p
   int count = 0;
   int i = 0;
   do {
      line side = {polygon[i], polygon[(i+1)%n]};     //forming a line from two consecutive points of poly
      if(isIntersect(side, exline)) {          //if side is intersects exline
         if(direction(side.p1, p, side.p2) == 0)
            return onLine(side, p);

         count++;
      }
      i = (i+1)%n;
   } while(i != 0);

      return count&1;             //when count is odd
}
vector<Point> convexHull(vector<Point>points) { 
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
    int t;
    cin>>t;
    while(t--){
        int n,q;
        cin>>n>>q;
        vector<Point> points(n);
        vector<Point> query(n);
        set<Point> st;

        vector<int> ans(q,0);
        for(int i=0;i<n;i++){
            Point p;
            cin>>p.x>>p.y;
            points[i]=p;
            st.insert(p);
        }
        for(int i=0;i<q;i++){
            cin>>query[i].x>>query[i].y;
        }
        bool allout=false;
        // for(auto i=st.begin();i!=st.end();i++){
        //     cout<<i->x<<" "<<i->y<<endl;
        // }
        vector<Point> temp;
        for(auto i=st.begin();i!=st.end();++i){
            temp.push_back(*i);
        }

        auto hull=convexHull(temp);
        for(auto i=hull.begin();i!=hull.end();i++){
            cout<<i->x<<" "<<i->y<<endl;
        }

        bool h=isInside(hull,{3,0});
        cout(h);
        // while(allout==false){
        //     vector<Point> temp;
        //     for(auto i=st.begin();i!=st.end();++i){
        //         temp.push_back(*i);
        //     }
        //     auto hull=convexHull(temp);
        //     if(hull.size()>=3){
        //         allout=false;
        //     }else{
        //         allout=true;
        //     }
        //     for(auto i:hull){
        //         // cout<<i.x<<" "<<i.y<<" "<<endl;
        //         st.erase(st.find(i));
        //     }
        //     for(int i=0;i<q; i++){
        //         if(isInside(hull,query[i])){
        //             // printf("h");
        //             ans[i]++;
        //         }
        //     }
        // }
        // for(int i=0;i<q;i++){
        //     cout<<ans[i]<<endl;
        // }
    }
    return 0;
}