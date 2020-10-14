#include <bits/stdc++.h>
using namespace std;

void west(int x, int y,int c){
    if(c==10)
        return;
    c++;
    int west_x = x-2*y,west_y = y;
    cout<<west_x<<" "<<west_y<<endl;
    west(west_x,west_y,c);
}

void east(int x, int y,int c){
    if(c==10)
        return;
    c++;
    int east_x = x+2*y,east_y = y;
    cout<<east_x<<" "<<east_y<<endl;
    east(east_x,east_y,c);
}
void south(int x, int y,int c){
    if(c==10)
        return;
    c++;
    int south_x = x,south_y = y - 2*x;
    if(south_y<0){
        south_x*=-1;
        south_y*=-1;
    }
    cout<<south_x<<" "<<south_y<<endl;
    south(south_x, south_y,c);
}
void north(int x,int y,int c){
    if(c==10)
        return;
    c++;
    int north_x = x,north_y = y + 2*x;
    if(north_y<0){
        north_x*=-1;
        north_y*=-1;
    }
    cout<<north_x<<" "<<north_y<<endl;
    north(north_x,north_y,c);
}


int main(){
    int x1,y1;
    cin>>x1>>y1;
    int x = 1;
    cout<<"North"<<endl;
    north(x1,y1,x);

    cout<<"\n\nSouth"<<endl;
    south(x1,y1,x);

    cout<<"\n\nEast"<<endl;
    east(x1,y1,x);


    cout<<"\n\nWest"<<endl;
    west(x1,y1,x);
    return 0;
}