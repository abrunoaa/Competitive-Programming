#include <cstdio>

int main()
{
	register int i,j,m,n;
	int s,maior=0;
	int p[100][100];
	scanf("%d%d",&n,&m);
	
	for(i=0;i<n;i++)
	{
		s=0;
		for(j=0;j<m;j++)
		{
			scanf("%d",&p[i][j]);
			s+=p[i][j];
		}
		if(s>maior)
		{
			maior=s;
		}
	}
	
	for(j=0;j<m;j++)
	{
		s=0;
		for(i=0;i<n;i++)
		{
			s+=p[i][j];
		}
		
		if(s>maior)
		{
			maior=s;
		}
	}
	
	printf("%d",maior);
}
