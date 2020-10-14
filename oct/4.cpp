#include <bits/stdc++.h>
using namespace std;
int n,x,p,k;

void solve1(vector<int> &a){
    //p==k
    if(x==a[k]){
        printf("0\n");
        return;
    }
    int ans = 0;
    if(a[k]>x){
        if(a[1]>x){
            printf("%d\n",k);
            return;
        }
        while(a[k] > x){
            ans++;
            k--;
        }
        printf("%d\n",ans);
    }else{
        if(a[n]<x){
            printf("%d\n",n-k+1);
            return;
        }
        while(a[k]<x){
            ans++;
            k++;
        }
        printf("%d\n",ans);
    }
}

void solve2(vector<int> &a){
    //p<k
    if(a[p] == x){
        printf("0\n");
        return;
    }
    int ans = 0;
    if(a[p]>x){
        if(a[0] > x){
            printf("%d\n",p);
            return;
        }
        while(a[p] > x){
            p--;
            ans++;
        }
        printf("%d\n",ans);
    }else{
        if(a[p] == a[k]){
            if(a[n]<x){
                printf("%d\n",n-p+1);
                return;
            }
            int ans = 0;
            while(a[p] > x){
                p++;
                ans++;
            }
            printf("%d\n",ans);
        }else{
            printf("-1\n");
        }
    }
}


void solve3(vector<int> &a){
    //p>k
    if(a[p] == x){
        printf("0\n");
        return;
    }
    if(a[p] < x){
        if(a[n] < x){
            printf("%d\n",n-p+1);
            return;
        }
        int ans = 0;
        while(a[p] < x){
            ans++;
            p++;
        }
        printf("%d\n",ans);
    }else{
        printf("-1\n");
    }
}
void test(){
    scanf("%d%d%d%d", &n,&x,&p,&k);
    vector<int> a(n+1);
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    sort(a.begin()+1,a.end());
    if(p==k){
        solve1(a);
    }else if(p<k){
        solve2(a);
    }else{
        solve3(a);
    }
    
}
int32_t main(){
    int t;
    scanf("%d", &t);
    while(t--) test();
    return 0;
}


// n=5
// k=3
// p=3
// x=7

// 1 2 3 5 6