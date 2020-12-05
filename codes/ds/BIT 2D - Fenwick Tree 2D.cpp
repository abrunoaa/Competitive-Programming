#include <bits/stdc++.h>
using namespace std;

/** begin *********************************************************************/
const int maxn = 10003;
int ft[maxn][maxn]; // 1-indexed

void init(int n) {
  for (int i = 1; i <= n; ++i)
    for (int j = 1; j <= n; ++j)
      ft[i][j] = 0;
}

void upd(int i, int j0, int x) { // add +x into each element of (i..n, j..n)
  for (; i < maxn; i += i & -i)
    for (int j = j0; j < maxn; j += j & -j)
      ft[i][j] += x;
}

int qry(int i, int j0) { // returns the value at (i, j)
  int s = 0;
  for (; i; i -= i & -i)
    for (int j = j0; j; j -= j & -j)
      s += ft[i][j];
  return s;
}
/** end ***********************************************************************/

#define cerr if (0) cerr

void test(int op, int n, int s, bool validate = 1) {
  cout << "Test with " << op << " operations, n = " << n << ", s = " << s << '\n';

  srand(s);
  init(n);

  int sum = 0;
  vector v(n + 1, vector(n + 1, 0));
  for (int k = 0; k < op; ++k) {
    cerr << " > operation " << k << '\n';

    int i = rand() % n + 1;
    int j = rand() % n + 1;
    int x = rand() % 201 - 100;
    cerr << " > update " << i << ' ' << j << ' ' << x << '\n';

    sum += x;
    upd(i, j, x);

    cerr << " > validate\n";
    assert(qry(n, n) == sum);
    if (validate)
      for (int a = 1; a <= n; ++a)
        for (int b = 1; b <= n; ++b) {
          if (a >= i && b >= j)
            v[a][b] += x;
          assert(qry(a, b) == v[a][b]);
        }
  }
}

int main() {
  for (int s = 0; s < 1000; ++s)
    test(100, 3, s);
  for (int n = 1; n <= 1000; ++n)
    test(n, 5, 0);
  for (int s = 0; s < 10; ++s)
    test(100000, 10, s);
  for (int s = 0; s < 10; ++s)
    test(1000000, 10000, s, false);
  return 0;
}
