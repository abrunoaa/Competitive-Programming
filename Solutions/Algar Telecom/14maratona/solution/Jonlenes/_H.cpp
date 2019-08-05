#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

int main() {
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

    //Matrimat - [linha - qtde item][coluna - valorMax]
    long long mat[c.size() + 1][W + 1];

    for (k = 0; k <= n; ++k)
      for (d = 0; d <= W; ++d) {
        if (!k || !d) { mat[k][d] = 0; }
        else {
          mat[k][d] = mat[k - 1][d];
          if (w[k - 1] <= d && (c[k - 1] + mat[k - 1][d - w[k - 1]]) > mat[k][d]) {
            mat[k][d] = c[k - 1] + mat[k - 1][d - w[k - 1]];
          }
        }
      }


    cout << mat[n][W] << endl;

  }

  return 0;
}


