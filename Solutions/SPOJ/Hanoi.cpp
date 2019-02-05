#include <cstdio>
#include <cmath>

int main()
{
	register int i,n,m;
	
	scanf("%d",&n);
	
	for(i=1;n!=0;i++){
		
		m = pow(2,n) - 1;
		
		printf("Teste %d\n%d\n\n",i,m);
		scanf("%d",&n);
	}
}
