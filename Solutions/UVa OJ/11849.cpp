#include <cstdio>

int main()
{
	register int i, m, n, r, t;
	int *cd = new int[1000000];
	
	while (scanf("%d%d", &m, &n), m || n)
	{
		t = 0;
		i = -1;
		while (++i < m)
		{
			scanf("%d", &cd[i]);
		}
		
		i = 0;
		while (n--)
		{
			scanf("%d", &r);
			while (cd[i] < r && i < m)
				i++;
			if (cd[i] == r)
				t++;
		}
		
		printf("%d\n", t);
	}
	
	delete[] cd;
	return 0;
}
