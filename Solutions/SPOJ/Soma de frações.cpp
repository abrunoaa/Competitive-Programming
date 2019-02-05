#include <cstdio>
#include <cmath>

int main()
{///  7/5 + 3/2
	register int i,d,e,a,b,c;
	
	scanf("%d%d%d%d",&a,&b,&c,&d);
	
	if(b!=d)
	{
		a*=d;
		c*=b;
		d *= b;
	}
	e=a+c;
	
	for(i=2;i<=e && i<=d;i++)
	{
		while(e%i==0 && d%i==0)
		{
			e/=i;
			d/=i;
		}
	}
	
	printf("%d %d",e,d);
}
