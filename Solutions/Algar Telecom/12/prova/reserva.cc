#include <bits/stdc++.h>
using namespace std;

#define inf static_cast < int > (1e9)

int main()
{
	//freopen("in", "r", stdin);
	freopen("reserva.in", "r", stdin);
	freopen("out", "w", stdout);
	
	register int xmin, xmax, ymin, ymax;
	int n, x, y, u, v, teste = 0;
	
	while (scanf("%d", &n), n)
	{
		xmin = -inf;
		ymin = -inf;
		xmax = inf;
		ymax = inf;
		
		while (n--)
		{
			scanf("%d%d%d%d", &x, &y, &u, &v);
			
			if (x > xmin)
				xmin = x;
			if (y < ymax)
				ymax = y;
			if (u < xmax)
				xmax = u;
			if (v > ymin)
				ymin = v;
				
			if (xmin >= xmax || ymin >= ymax)
				break;
		}
		if (n != -1)
		{
			while (n--)
				scanf("%*d%*d%*d%*d");
			n = 0;
		}
		
		printf("Teste %d\n", ++teste);
		if (n)
			printf("%d %d %d %d\n\n", xmin, ymax, xmax, ymin);
		else
			printf("nenhum\n\n");
	}
	
	return 0;
}
