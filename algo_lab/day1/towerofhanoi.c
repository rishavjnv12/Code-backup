#include <stdio.h>
void towerofhanoi(int n,char source,char aux,char dest){
    if (n == 1) 
    { 
        printf("\n Move disk 1 from rod %c to rod %c", source,dest); 
        return; 
    } 
    towerofhanoi(n-1,source,dest,aux); 
    printf("\n Move disk %d from rod %c to rod %c", n, source, dest); 
    towerofhanoi(n-1,aux,dest,source); 
}
int main(){
    int n;
    printf("Enter the number of discs:");
    scanf("%d", &n);
    towerofhanoi(n,'A','B','C');
    printf("\n");
    return 0;
}