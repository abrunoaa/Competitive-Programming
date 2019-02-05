#include <cstdio>

int main()
{
	register int c=0,p,x,y,n;
	scanf("%d%d",&n,&p);
	while(n>0)
	{
		scanf("%d%d",&x,&y);
		if(x+y>=p)
			c++;
		n--;
	}
	printf("%d",c);
}
