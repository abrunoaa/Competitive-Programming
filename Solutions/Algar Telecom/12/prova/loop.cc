#include <bits/stdc++.h>
using namespace std;

int main()
{
	//freopen("in", "r", stdin);
	freopen("loop.in", "r", stdin);
	freopen("out", "w", stdout);
	
	register int i, s, m;
	char c;
	int n, p, t, pa, pv, a[1005], v[1005];
	
	scanf("%d", &n);
	while (n--)
	{
		scanf("%d", &p);
		pa = pv = 0;
		while (p--)
		{
			scanf("%d %1c", &t, &c);
			if (c == 'V')
			{
				i = pv++;
				while (--i >= 0 && t > v[i])
					v[i + 1] = v[i];
				v[i + 1] = t;
			}
			else
			{
				i = pa++;
				while (--i >= 0 && t > a[i])
					a[i + 1] = a[i];
				a[i + 1] = t;
			}
		}
		
		s = 0;
		m = pa < pv ? pa : pv;
		if (m)
		{
			for (i = 0; i < m; ++i)
				s += a[i] + v[i] - 1;
			s -= i;
		}
		
		printf("%d\n", s);
	}
	
	return 0;
}
