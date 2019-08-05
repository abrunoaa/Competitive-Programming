#include <bits/stdc++.h>
using namespace std;

#define gcd __gcd

typedef long long ll;

const int maxn = 1e3 + 3;

int v[maxn], p[maxn];

int main() {
  // assert(freopen("in", "r", stdin));
  cin.sync_with_stdio(0), cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int num = 0, den = 0;
    vector<int> order;
    for (int i = 0; i < n; ++i) {
      cin >> p[i] >> v[i];
      num += v[i] * p[i];
      den += v[i];
      order.push_back(i);
    }
    sort(order.begin(), order.end(), [](int x, int y) {
      return p[x] > p[y];
    });
    int k;
    for (k = 0; k < n; ++k) {
      int i = order[k];
      int a = num + p[i], b = den + 1;
      if ((ll)a * den < (ll)num * b) {
        break;
      }
      num = a;
      den = b;
    }
    int g = gcd(num, den);
    cout << num / g << '/' << den / g << '\n' << k << '\n';
    for (int i = 0; i < k; ++i) {
      cout << order[i] + 1 << ' ';
    }
    cout << '\n';
  }
  return 0;
}
