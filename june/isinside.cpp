// A C++ program to check if a given point lies inside a given polygon 
// Refer https://www.geeksforgeeks.org/check-if-two-given-line-segments-intersect/ 
// for explanation of functions onSegment(), orientation() and doIntersect() 
#include <bits/stdc++.h> 
using namespace std; 

// Define Infinite (Using INT_MAX caused overflow problems) 
#define INF 10000 
struct Point {
   int x, y;
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

// Driver program to test above functions 
int main() 
{ 
	vector<Point> polygon1 = {{0, 0},{-1,2},{5,0},{6,4}}; 
	// int n = sizeof(polygon1)/sizeof(polygon1[0]); 
	Point p = {3,1}; 
	isInside(polygon1, p)? cout << "Yes \n": cout << "No \n"; 
	// Point p={0,0},q={6,0};
	// Point a={1,1};
	// cout<<online(p,q,a)<<endl;


	return 0; 
}
