#include <bits/stdc++.h>
using namespace std;
void test(int n){
    
    if(__builtin_popcount(n) == 1){
        printf("-1\n");
        return;
    }
    vector<int> v(n+1);
    for(int i=1;i<=n;i++){
        v[i] = i;
    }
    for(int i=1;i<n;i*=2){
        swap(v[i], v[i+1]);
    }
    for(int i=1;i<=n;i++){
        printf("%d ", v[i]);
    }
    for(int i=2;i<=n;i++){
        assert(v[i]&v[i-1]);
    }
    printf("\n");
}
int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        scanf("%d", &n);
        if(n==1)
            printf("1\n");
        else
        // for(int n=1;n<=1000;n++)
            test(n);
    }
    return 0;
}