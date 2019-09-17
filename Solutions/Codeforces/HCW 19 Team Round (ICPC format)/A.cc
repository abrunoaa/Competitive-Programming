#include <bits/stdc++.h>
using namespace std;

const int maxn = (int)1e5 + 3;

int vis[maxn];
int n, s, b, l;

bool f(int &x, int add, int num) {
  x = (x + add) % (n + 1);
  if (x > 0 && vis[x] != 0 && vis[x] != num) {
    return 1;
  }
  vis[x] = num;
  return 0;
}

int main() {
  // assert(freopen("in", "r", stdin));
  cin.sync_with_stdio(0), cin.tie(0);
  cin >> n >> s >> b >> l;
  for (int i = 0, j = 0, k = 0, m = 0; m < 3 * n; m += 3) {
    if (f(i, s, 1)) {
      cout << m + 1 << '\n';
      return 0;
    }
    if (f(j, b, 2)) {
      cout << m + 2 << '\n';
      return 0;
    }
    if (f(k, l, 3)) {
      cout << m + 3 << '\n';
      return 0;
    }
  }
  cout << 3000000000ll << '\n';
  return 0;
}
