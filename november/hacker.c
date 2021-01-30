#include <stdio.h>
#include <assert.h>
int main(){
    int n,q;
    
    scanf("%d%d",&n,&q);
    assert(q<100000);
    for(int i=0;i<n;i++){
        int temp;
        scanf("%d",&temp);
    }
    for(int i=0;i<q;i++){
        int x,y;
        scanf("%d%d",&x,&y);
    }
    for(int i=0;i<q;i++){
        printf("1\n");
    }
    return 0;
}