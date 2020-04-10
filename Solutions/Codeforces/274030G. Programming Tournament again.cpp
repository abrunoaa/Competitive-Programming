#include <bits/stdc++.h>
using namespace std;

const int maxn = (int)1e5 + 3;

int n, q;
int p[maxn];

int f(int k, int power) {
  return (k - 1) / power * power + 1;
}

int qry(int i, int j) {
  int ans = 1;
  for (int power = 2; f(i, power) != f(j, power); power *= 2) {
    ++ans;
  }
  return ans;
}

int main() {
  cin.sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> q;
  for (int i = 1; i <= n; ++i) {
    int a;
    cin >> a;
    p[a] = i;
  }
  while (q--) {
    int t, x, y;
    cin >> t >> x >> y;
    if (t == 1) {
      swap(p[x], p[y]);
    } else {
      cout << qry(p[x], p[y]) << '\n';
    }
  }
  return 0;
}
