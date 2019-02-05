#include <cstdio>

struct one
{
	int q;
	int p;
} st[1000];

int main()
{
	register int tot = 0, p, q, i, me = 999999, t = 0, s[1000], k;
	char c;
	while (scanf(" %1c%*[^0-9\n]s", &c), c != '#')
	{
		scanf("%d%d", &q, &p);
		if (p < me)
			me = p;
		
		i = tot - 1;
		while (i >= 0 && q < st[i].q)
		{
			st[i + 1] = st[i];
			i--;
		}
		++i;
		st[i].p = p;
		st[i].q = q;
		s[i] = p;
		
		tot++;
	}
	
	scanf("%d", &k);
	while (k > 0)
	{
		t += me;
		i = -1;
		while (++i < tot)
		{
			if (s[i] < t)
			{
				printf("%d\n", st[i].q);
				if (--k <= 0)
					break;
				s[i] += st[i].p;
			}
		}
	}
	
	return 0;
}
