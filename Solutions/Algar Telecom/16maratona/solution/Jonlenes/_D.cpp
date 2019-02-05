#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int n, W, k, d, v, p;

    while (cin >> n && n) {
        vector<int> c, w;
        while (n--) {
            cin >> v >> p;
            c.push_back(v);
            w.push_back(p);
        }

        cin >> W;
		n = c.size();
		
		//Matriz - [linha - qtde item][coluna - valorMax]
		long long z[c.size() + 1][W + 1];
		
		for (d = 0; d <= W; ++d) z[0][d] = 0;
		for (k = 0; k <= n; ++k) z[k][0] = 0;
		
		
		for (k = 1; k <= n; ++k)
			for (d = 1; d <= W; ++d) {
				z[k][d] = z[k - 1][d];
				if (w[k - 1] <= d && (c[k - 1] + z[k - 1][d - w[k - 1]]) > z[k][d])
					z[k][d] = c[k - 1] + z[k - 1][d - w[k - 1]];
			}
			

		cout << z[n][W] << endl;

    }

    return 0;
}


