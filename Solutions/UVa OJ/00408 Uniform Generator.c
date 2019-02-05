#include <stdio.h>

int mdc (int a, int b) { return b ? mdc(b, a % b) : a; }

int main()
{
	int s, m;
	while (scanf("%d%d", &s, &m) == 2)
		printf("%10d%10d    %s\n\n", s, m, (mdc(s, m) == 1 ? "Good Choice" : "Bad Choice"));
	
	return 0;
}
