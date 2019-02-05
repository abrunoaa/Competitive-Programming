#include <cstdio>



int main()
{
	register int i, a, b;
	
	char time[16];
	
	
	
	for (i = 0; i < 16; i++)
	{
		time[i] = 'A' + i;
	}
	
	for (i = 0; i < 8; i++)
	{
		scanf("%d%d", &a, &b);
		
		if (a > b)
		{
			time[i] = time[i*2];
		}
		else
		{
			time[i] = time[i*2+1];
		}
	}
	
	for (i = 0; i < 4; i++)
	{
		scanf("%d%d", &a, &b);
		
		if (a > b)
		{
			time[i] = time[i*2];
		}
		else
		{
			time[i] = time[i*2+1];
		}
	}
	
	for (i = 0; i < 2; i++)
	{
		scanf("%d%d", &a, &b);
		
		if (a > b)
		{
			time[i] = time[i*2];
		}
		else
		{
			time[i] = time[i*2+1];
		}
	}
	
	scanf("%d%d", &a, &b);
	
	if (a > b)
	{
		printf("%c", time[0]);
	}
	else
	{
		printf("%c", time[1]);
	}
}
