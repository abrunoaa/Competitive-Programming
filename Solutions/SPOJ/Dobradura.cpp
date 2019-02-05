#include <cstdio>
#include <cmath>

int main()
{
	int n,d;
	
	register int i;
	
	scanf("%d",&n);
	
	for(i=1;n!=-1;i++)
	{
		d=1;
		
		d += pow(2,n);
		
		printf("Teste %d\n%d\n",i,d*d);
		scanf("%d",&n);
	}
}
