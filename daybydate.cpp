#include <bits/stdc++.h> 
using namespace std; 
  
int dayofweek(int d, int m, int y)  {  
    static int t[] = {0,3,2,5,0,3,5,1,4,6,2,4};  
    y-=m<3;  
    return (y+y/4-y/100+y/400+t[m-1]+d)%7;  
}  
bool isleap(int year){
    return (((year % 4 == 0) && (year % 100 != 0)) || 
             (year % 400 == 0));
}
  
// Driver Code 
int main(){  
    for(int i=1;i<3000;i++){
        if(isleap(i)==false and (dayofweek(1,2,i)==0 or dayofweek(1,2,i)==6))
                cout <<i<<endl;
    }
    //cout<<dayofweek(11,2,2020);  
  
    return 0;  
} 