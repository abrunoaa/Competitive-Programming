#include <bits/stdc++.h>
using namespace std;

int main()
{
	//freopen("out", "w", stdout);
	
	register int i;
	char str[200];
	long n;
	
	while (scanf(" %[^\n]", str), *str != '-')
	{
		n = 0;
		if (str[1] == 'x')
		{
			for (i = 2; str[i]; ++i)
				if (str[i] >= 'a' && str[i] <= 'z')
					str[i] -= 39;
			for (i = 2; str[i]; ++i)
				n = n * 16 + str[i] - 48;
			printf("%ld\n", n);
		}
		else
		{
			for (i = 0; str[i]; ++i)
				n = n * 10 + str[i] - 48;
			printf("0x%lX\n", n);
		}
	}
	return 0;
}
