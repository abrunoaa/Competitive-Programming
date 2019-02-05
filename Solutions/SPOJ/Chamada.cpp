#include <cstdio>



int main()
{
	register int i, j, k, n, sort;
	
	char **nome = new char*[100], *st;
	
	
	
	scanf("%d%d", &n, &sort);
	
	for (i=0; i<n; i++)
	{
		st = new char[21];
		
		scanf(" %s", st);
		
		for(j=i-1; j>=0 && st[0]<nome[j][0]; j--)
		{
			nome[j+1] = nome[j];
		}
		
		if(j>=0)
		{
			do
			{
				for(k=0; k<20 && st[k]==nome[j][k]; k++);
				if(st[k]<nome[j][k])
				{
					nome[j+1] = nome[j--];
				}
				else
				{
					break;
				}
				
			} while(j>=0);
		}
		
		nome[j+1] = st;
	}
	
	printf("%s", nome[sort-1]);
	
	
	delete[] nome;
}
