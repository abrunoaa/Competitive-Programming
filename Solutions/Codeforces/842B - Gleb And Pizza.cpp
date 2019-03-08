#include <bits/stdc++.h>
using namespace std;

int main()
{
	int d, r, n, a, b, c, qtd = 0;
	
	scanf("%d%d%d", &r, &d, &n);
	while (n--)
	{
		scanf("%d%d%d", &a, &b, &c);
		double h = hypot(a, b);
		if (r - d <= h - c && h + c <= r)
			++qtd;
	}
	
	printf("%d\n", qtd);
	
	return 0;
}
