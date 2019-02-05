#include <bits/stdc++.h>
using namespace std;

int main()
{
	//freopen("in", "r", stdin);
	freopen("armstrong.in", "r", stdin);
	freopen("out", "w", stdout);
	
	register int i, j, k, l, s;
	int t, a1, a2;
	char ach;
	
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d%d", &a1, &a2);
		j = a2;
		ach = 0;
		for (i = a1; i <= j; ++i)
		{
			k = i;
			for (l = 0; k; ++l, k /= 10);
			k = i;
			for (s = 0; k; s += pow(k % 10, l), k /= 10);
			if (s == i)
			{
				ach = 1;
				printf("%d ", i);
			}
		}
		if (ach)
			printf("\n");
		else
			printf("Nenhum\n");
	}
	
	return 0;
}
