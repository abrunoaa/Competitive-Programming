#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int maxn = (int)1e6 + 3;

int n;
double a[maxn];

int main() {
  assert(freopen("in", "r", stdin));
  cin.sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cout << fixed << setprecision(10);
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int tmp;
    cin >> tmp;
    a[i] = tmp;
  }
  double s = 0;
  for (int i = 1; i < n; ++i) {
    s += a[i];
    cout << i << ' ' << s / (i + 0) << endl;
  }
  return 0;
}
