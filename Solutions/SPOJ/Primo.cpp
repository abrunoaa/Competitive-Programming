#include <cstdio>
#include <cmath>

int main()
{
	register int i,n;
	scanf("%d",&n);
	for(i=2;n%i!=0 && i<sqrt(n);i++);
	if(n%i==0 || n==1 || n==2)
		printf("nao");
	else
		printf("sim");
}
