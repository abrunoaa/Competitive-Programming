#include <cstdio>

int main()
{
	register int i,p,d,n,m;
	bool s[100]={0};
	scanf("%d%d",&n,&m);
	while(m>0)
	{
		scanf("%d%d",&p,&d);
		p--;
		for(i=p;i<n;i+=d)
		{
			s[i]=1;
		}
		for(i=p-d;i>=0;i-=d)
		{
			s[i]=1;
		}
		m--;
	}
	for(i=0;i<n;i++)
		printf("%d\n",s[i]);
}
