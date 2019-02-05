#include <bits/stdc++.h>
using namespace std;

int main()
{
	int i, n;
	unsigned long fat[30] = {1};
	
	while (scanf("%d", &n) > 0)
	{
		if (!fat[n])
		{
			i = n;
			while (!fat[--i]);
			while (++i <= n)
				fat[i] = i * fat[i - 1];
		}
		printf("%lu\n", fat[n]);
	}
	return 0;
}
