#include <stdio.h>
int main(){
	int x=56;
	int y=__builtin_popcount(x);
	printf("%d\n",y);
	return 0;
}
