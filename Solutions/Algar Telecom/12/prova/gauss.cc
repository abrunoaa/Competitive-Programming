#include <bits/stdc++.h>
using namespace std;

int main()
{
	//freopen("in", "r", stdin);
	
	int n, x, y;
	
	scanf("%d", &n);
	while (n--)
	{
		scanf("%d%d", &x, &y);
		printf("%d\n", ((y + x) * (y - x + 1)) >> 1);
	}
	return 0;
}
