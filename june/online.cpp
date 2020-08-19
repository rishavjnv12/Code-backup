#include <bits/stdc++.h>

using namespace std;

struct Point{
    int x,y;
};
int sqdistance(Point p,Point q){
    return (p.x-q.x)*(p.x-q.x) + (p.y-q.y)*(p.y-q.y);
}
bool online(Point a,Point b,Point q){
    return sqdistance(a,q)+sqdistance(b,q)==sqdistance(a,b);
}
int32_t main(){
    Point p1,p2;
    Point q;
    p1={2,3},p2={4,5};
    q={3,4};

    cout<<online(p1,p2,q);
    return 0;
}