#include <bits/stdc++.h>
#include<stdio.h>
#define ios ios_base::sync_with_stdio(false);cin.tie(NULL)
#define cout(x) cout<<x<<'\n'

using namespace std;

int a,b,c,p,q,r;
int atleastone(){
        // fine
        if(a==p and b==q and c==r){
            //printf("1here");
            return 0;
        }else if((a==p and b==q) or (a==p and c==r) or (b==q and c==r)){
            //printf("2here");
            return 1;
        }else if(a==p){
            if(!b){
                if(!c){
                    //a 0 0
                    //a q r
                    if(q==r){
                        //printf("5here");
                        return 1;
                    }else{
                         //printf("6here");
                        return 2;
                    }
                }else{
                    //a 0 c
                    //a q r
                    if(r-c == q){
                         //printf("7here");
                        return 1;
                    }else{
                         //printf("8here");
                        return 2;
                    }
                }
            }else{
                if(!c){     //a b 0
                            //a q r
                    if(r==(q-b)){
                         //printf("9here");
                        return 1;
                    }else{
                         //printf("10here");
                        return 2;
                    }
                }else{
                    //a b c
                    //a q r
                    if(r-c == q-b){
                         //printf("11here");
                        return 1;
                    }else if(q%b==0 and r%c==0 and q/b==r/c){
                         //printf("12here");
                        return 1;
                    }else{
                         //printf("13here");
                        return 2;
                    }
                }
            }
        }else if(b==q){
            swap(a,b);
            swap(p,q);
            if(!b){
                if(!c){
                    if(!q and !r){
                         //printf("14here");
                        cout(0);
                        
                    }else if(q==r){
                         //printf("15here");
                        return 1;
                        
                    }else{
                         //printf("16here");
                        return 2;
                        
                    }
                }else{
                    if(r-c == q){
                         //printf("17here");
                        return 1;
                        
                    }else{
                         //printf("18here");
                        return 2;
                        
                    }
                }
            }else{
                if(!c){     //a b 0
                            //a q r
                    if(r==(q-b)){
                         //printf("19here");
                        return 1;
                        
                    }else{
                         //printf("20here");
                        return 2;
                        
                    }
                }else{
                    //a b c
                    //a q r
                    if(r-c == q-b){
                         //printf("21here");
                        return 1;
                        
                    }else if(q%b==0 and r%c==0 and q/b==r/c){
                         //printf("22here");
                        return 1;
                        
                    }else{
                         //printf("23here");
                        return 2;
                        
                    }
                }
            }
        }else if(c==r){
            swap(a,c);
            swap(p,r);
            if(!b){
                if(!c){
                    if(!q and !r){
                         //printf("24here");
                        cout(0);
                        
                    }else if(q==r){
                         //printf("25here");
                        return 1;
                        
                    }else{
                         //printf("26here");
                        return 2;
                        
                    }
                }else{
                    if(r-c == q){
                         //printf("27here");
                        return 1;
                        
                    }else{
                         //printf("28here");
                        return 2;
                        
                    }
                }
            }else{
                if(!c){     //a b 0
                            //a q r
                    if(r==(q-b)){
                         //printf("29here");
                        return 1;
                        
                    }else{
                         //printf("30here");
                        return 2;
                        
                    }
                }else{
                    //a b c
                    //a q r
                    if(r-c == q-b){
                         //printf("31here");
                        return 1;
                        
                    }else if(q%b==0 and r%c==0 and q/b==r/c){
                         //printf("32here");
                        return 1;
                        
                    }else{
                         //printf("33here");
                        return 2;
                        
                    }
                }
            }
        }
}

int abc_zero(){
    // fine
    if(p==q and q==r){
        //printf("34here");
        return 1;
        
    }else if(p==q or q==r or p==r){
        //printf("35here");
        return 2;
        
    }else if(p+q==r or p+r==q or q+r==p){
        //printf("36here");
        return 2;
        
    }else{
        //printf("37here");
        return 3;      
    }
}


int ab_zero(){
    //Fine
    if(p==q and q==r-c){
        //printf("38here");
        return 1;
        
    }else if(p==q or q==(r-c) or p==(r-c)){
        //0 0 2
        //1 -1 3
        //printf("39here");
        return 2;
        
    }else if(p+q==(r-c) or p==(r-c)+q or q==(r-c)+p){
        //0 0 3
        //3 7 7
        //printf("40here");
        return 2;
        
    }else if(r%c==0 and r/c and q%(r/c)==0 and q/(r/c)==p){
        //printf("1debug");
        return 2;
        
    }else if(r%c==0 and r/c and p%(r/c)==0 and p/(r/c)==q){
        //printf("12debug");
        return 2;
        
    }else if(q%p==0 and (q/p)*(c+p)==r){
        return 2;
    }else if(p%q==0 and (p/q)*(c+q)==r){
        return 2;
    }else{
        //printf("41here");
        return 3;
        
    }
}

int a_zero(){
    // return -1;
    assert(!b and !c);
    if(p==q-b and p==r-c){
        return 1;
    }
    if(p==q-b or p==r-c or r-c==q-b){
        return 2;
    }
    if(r%c==0 and q%b==0 and q/b==c/r){
        return 2;
    }
    return -1;
    if(!q){
        if(p==r){
            return 2;
        }else return 3;
    }else if(!r){
        if(q==p){
            return 2;
        }else return 3;
    }
    if(r%c==0 and (b+p)*(r/c)==q){
        // k=p
        // (b+k)*x=q
        // c*x=r
        return 2;
    }
    if(q%b==0 and (c+p)*(q/b)==r){
        // k*x=p
        // (b+k)=q
        // c*x=r
        return 2;
    }

    if(r%c==0 and (q-b)*(r/c)==p){

        // k*x=p
        // (b+k)=q
        // c*x=r
        return 2;
    }
    if(q%b==0 and (r-c)*(q/b)==p){
        // k*x=p
// b*x=q
// c+k=r
        return 2;
    }
    if(q%b==0 and (p/(q/b)+c)*(q/b)==r){
//         k*x=p
// (b)*x=q
// (c+k)*x=r
        return 2;
    }
    return 3;
    if(p%(r-c)==0 and (b+(r-c))*(p/(r-c))==q){
//         k*x=p
// (b+k)*x=q
// (c+k)=r
        return 2;
    }
    if(p%(q-b)==0 and (c+(q-b))*(p/(q-b))==r){
//         k*x=p
// (b+k)=q
// (c+k)*x=r
        return 2;
    }

    if(b+p and c+p and q%(b+p)==0 and r%(c+p)==0 and q/(b+p)==r/(c+p)){
// k*x=p
// (b+k)=q
// (c+k)*x=r

        return 2;
    }
    return 7;
}

int abc_equal(){
    return -1;
    if(p==q and q==r){
        return 1;
    }else if(p==q or q==r or p==r){
        return 2;
    }else if(!p or !q or !r){
        if(!p){
            if(c-a==q or q-a==c){
                return 2;
            }else{
                return 3;
            }
        }else if(!q){
            swap(p,q);
            return abc_equal();
        }else{
            swap(p,r);
            return abc_equal();
        }
    }
    
    else if((r%a==0 and q%(r/a)==0 and q/(r/a)==p) or
            (q%a==0 and r%(q/a)==0 and r/(q/a)==p)  or
            (r%a==0 and p%(r/a)==0 and p/(r/a)==q) or
            (q%a==0 and p%(q/a)==0 and p/(q/a)==r) or
            (p%a==0 and r%(p/a)==0 and r/(p/a)==q) or
            (p%a==0 and q%(p/a)==0 and q/(p/a)==r) or

            (p%a==0 and (q-p+a)==r) or
            (p%a==0 and (r-p+a)==q) or
            (q%a==0 and (p-q+a)==r) or
            (r%a==0 and (p-r+a)==q) or
            (r%a==0 and (q-r+a)==p) or
            (q%a==0 and (r-q+a)==p)){
        return 2;
    }else{
        return 3;
    }
}

int ab_equal(){
    return -1;
    if(!p){
        if(q==r-c){
            return 2;
        }else if(r==q-a){
            return 2;
        }else if(q==r){
            return 2;
        }else if(q%a==0 and c-a==r){
            return 2;
        }
    }
    if(!q){
        swap(p,q);
        return ab_equal();
    }
    if(!r){
        if(p-a==q or q-a==p){
            return 2;
        }
    }
    
    if(q==r){
        if(p==0)
            return 2;
        if((q%c==0 and q/(q/c)==p) or (p%a==0 and q-p+c==q)){
            return 2;
        }else return 3;
    }else if(p==r){
        swap(p,q);
        return ab_equal();
    }else{
        if((q%p==0 and (c+(q-a))*(q/p)==r) or (p%q==0 and (c+(p-a))*(p/q)==r)){
            return 2;
        }
        if(p/a and p%a==0 and q%(p/a)==0 and ((q/(p/a)-a)+c)*(p/a)==r){
            return 2;
        }else if(q/a and q%a==0 and p%(q/a)==0 and ((p/(q/a)-a)+c)*(q/a)==r){
            return 2;
        }else if((q-(p-a))%a==0 and c*((q-(p-a))/a)+(p-a)==r){
            return 2;
        }else if((p-(q-a))%a==0 and c*((p-(q-a))/a)+(q-a)==r){
            return 2;
        }
        return 3;
    }
}

int pq_equal(){
    return -1;
    if(!r){
        return 2;
    }else if((r%c==0 and ((p-a)*(r/c)+b)==p) or (r%c==0 and (p-b)*(r/c)+a==p) or (p%b==0 and (p-a)*(p/b)+c==r) or (p%a==0 and (p-b)*(p/a)+c==r)){
        return 2;
    }else if((b%a==0 and c*(b/a)+(p-b)==r) or (a%b==0 and c*(a/b)+(p-a)==r)){
        return 2;
    }else if((p%b==0 and a*(p/b)+(r-c)==p) or (p%a==0 and b*(p/a)+(r-c)==p)){
        return 2;
    }else{
        return 3;
    }
}

int pqr_diff(){
    return -1;
    //(a+k)x=p
    //(b+k)x=q
    //(c+k)x=r
    int u=b-a,v=c-b,w=c-a;
    int u1=q-p,v1=r-q,w1=r-p;
    if(u1%u==0 and v1%v==0 and w1%w==0 and u1/u==v1/v and v1/v==w1/w){
        int x=u1/u;
        if(p%x==0 and q%x==0 and r%x==0 and p/x-a==q/x-b and r/x-c==p/x-a){
            //printf("83here");
            return 2;
        }

    }
    //(a+k)x=p
    //(b+k)x=q
    //(c)x=r
    if(r%c==0){
        int x=r/c;
        if(x and p%x==0 and q%x==0 and p/x-a==q/x-b){
            //printf("84here");
            return 2;
        }
    }
    
    //(a+k)x=p
    //(b)x=q
    //(c+k)x=r

    if(q%b==0){
        int x=q/b;
        if(x and p%x==0 and r%c==0 and p/x-a==r/x-c){
            //printf("85here");
            
        }
    }
    
    //(a)x=p
    //(b+k)x=q
    //(c+k)x=r
    if(p%a==0){
        int x=p/a;
        if(x and r%x==0 and q%x==0 and r/x-c==q/x-b){
            //printf("86here");
            return 2;
        }
    }
    //(a*x)+k=p
    //(b*x)+k=q
    //(c*x)+k=r
    if((q-p)%(b-a)==0 and (r-q)%(c-b)==0 and (r-p)%(c-a)==0){
        int x=(q-p)/(b-a);
        if((p-a*x)==(q-b*x) and (r-c*x)==(q-b*x)){
            //printf("87here");
            return 2;
        }
    }

    //(a)+k=p
    //(b*x)+k=q
    //(c*x)+k=r
    if((r-q)%(c-b)==0){
        int k=q-(b*((r-q)/(c-b)));
        if(a+k==p){
            //printf("88here");
            return 2;
        }
    }

    //(a*x)+k=p
    //(b)+k=q
    //(c*x)+k=r
    if((r-p)%(c-a)==0){
        int k=r-(c*((r-p)/(c-a)));
        if(b+k==q){
            //printf("89here");
            return 2;
        }
    }

    //(a*x)+k=p
    //(b*x)+k=q
    //(c)+k=r
    if((q-p)%(b-a)==0){
        int k=q-(b*((q-p)/(b-a)));
        if(c+k==r){
            //printf("90here");
            return 2;
        }
    }


    return 3;


}
int no_zero(){
    // return -1;
    int x=p-a,y=q-b,z=r-c;
    if((x==y and y==z) or (p%a==0 and q%b==0 and r%c==0 and p/a==q/b and q/b==r/c)){
        return 1;
    }else if((x==y or y==z or x==z) or (x+y==z or x+z==y or z+y==x)){
        return 2;
    }
    if(p%a==0 and q%b==0 and r%c==0){
        int u=p/a,v=q/b,w=r/c;
            //1 2 3
            //2 12 9
        if(u==v or v==w or u==w){
            //printf("69here");
            return 2;
        }
        if(u*v==w or u*w==v or v*w==u){
            //printf("70here");
            return 2;
        }
    }
    if(p%a==0 and q%b==0){
        int u=p/a;
        int v=q/b;
        if(u==v){
            //printf("1hello");
            return 2;
        }
        if(b*u+(r-c)==q){
            //printf("71here");
            return 2;
        }
        if(a*v+(r-c)==p){
            //printf("72here");
            return 2;
        }
        
    }
    if(q%b==0 and r%c==0){

        int u=q/b;
        int v=r/c;
        if(u==v){
            //printf("2hello");
            return 2;
        }
        if(c*u+(p-a)==r){
            //printf("73here");
            return 2;
        }
        if(b*v+(p-a)==q){
            //printf("74here");
            return 2;
        }
    }
    if(p%a==0 and r%c==0){
        int u=p/a;
        int v=r/c;
        if(u==v){
            //printf("3hello");
            return 2;
        }
        if(c*u+(q-b)==r){
            //printf("75here");
            return 2;
        }
        if(a*v+(q-b)==p){
            //printf("76here");
            return 2;
        }
    }
    if(p%a==0){
        int u=q-b;
        int v=r-c;
        int x=p/a;
        if((b+v)*x==q){
            //printf("77here");
            return 2;
        }
        if((c+u)*x==r){
            //printf("78here");
            return 2;
        }
    }
    if(q%b==0){
        swap(p,q);
        swap(a,b);
        int u=q-b;
        int v=r-c;
        int x=p/a;
        if((b+v)*x==q){
            //printf("79here");
            return 2;
        }
        if((c+u)*x==r){
                //printf("80here");
            return 2;
        }
        swap(p,q);
        swap(a,b);
    }
    if(r%c==0){
        swap(p,r);
        swap(a,c);
        int u=q-b;
        int v=r-c;
        int x=p/a;
        if((b+v)*x==q){
            //printf("81here");
            return 2;
        }
        if((c+u)*x==r){
                //printf("82here");
            return 2;
        }
        swap(p,r);
        swap(a,c);
    }
    if(a==b and b==c){
        return abc_equal();
    }else if(a==b or b==c or a==c){
        if(a==b){
            return ab_equal();
        }else if(b==c){
            swap(b,c);
            swap(q,r);
            return ab_equal();
        }else{
            swap(a,c);
            swap(p,r);
            return ab_equal();
        }
    }else{
        if(p==q and q==r){
            return 2;
        }else if(p==q){
            return pq_equal();
        }else if(q==r){
            swap(a,c);
            swap(p,r);
            return pq_equal();
        }else if(p==r){
            swap(b,c);
            swap(q,r);
            return pq_equal();
        }else{
            return pqr_diff();
            // return 3;
        }
    }
}
            




int k,x;
int32_t main(){
    ios;
    int t;
    cin>>t;
    while(t--){
        cin>>a>>b>>c;
        cin>>p>>q>>r;
        // cout<<a<<b<<c<<p<<q<<r;
        if(a==p or b==q or c==r){
            cout(atleastone());
        }else{
            if(!a){
                if(!b){
                    if(!c){
                        cout(abc_zero());
                    }else{
                        cout(ab_zero());
                    }
                }else{
                    if(!c){
                        //0 b 0
                        swap(b,c);
                        swap(q,r);
                        cout(ab_zero());
                    }else{
                        
                        assert(!b and !c);
                        // cout(a_zero());
                        //0 b c
                        //p q r
                    }
                }
            }else{
                if(!b){
                    if(!c){
                        //a 0 0
                        swap(a,c);
                        swap(p,r);
                        cout(ab_zero());
                    }else{
                        //a 0 c
                        swap(a,b);
                        swap(p,q);
                        assert(!b and !c);
                        // cout(a_zero());
                    }
                }else{
                    if(!c){
                        //a b 0
                        swap(a,c);
                        swap(p,r);
                        // cout(a_zero());
                    }else{
                        cout(no_zero());
                    }
                }
            }
        }
    }
    return 0;
}