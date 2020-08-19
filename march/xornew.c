#include <stdio.h>
#include <stdlib.h>
int fastscan(int *a)
{
    
}
int main(){
    int t;
    
    fastscan(&t);
    //printf("%d\n",t);
    while(t--){
        int n,q;
        scanf("%d %d",&n,&q);
        int odd=0,even=0;
        int temp;
        for(int i=0;i<n+1;i++){
            fastscan(&temp);
            //printf("%d ",temp);
            if(i){
                if(__builtin_popcount(temp)%2) odd++;
                else even++;
            }
        }
        //printf("\n");
        while(q--){
            int p;
            fastscan(&p);
            if(__builtin_popcount(p)%2==0){
                printf("%d %d\n",even,odd);
            }else{
                printf("%d %d\n",odd,even);
            }
        }
    }
    return 0;
}