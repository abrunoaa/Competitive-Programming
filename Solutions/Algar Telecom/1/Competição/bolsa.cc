#include <bits/stdc++.h>
using namespace std;

int main()
{
	register int i;
	int n, fib[50] = {1, 1};
	
	while (scanf("%d", &n) > 0)
	{
		if (!fib[--n])
		{
			i = n;
			while (!fib[--i]);
			while (++i <= n)
				fib[i] = fib[i - 1] + fib[i - 2];
		}
		printf("%d\n", fib[n]);
	}
	return 0;
}
