#include <bits/stdc++.h>
using namespace std;

const int maxn = 103;

int a[maxn];
int b[maxn];

int main() {
  cin.sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
      cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
      cin >> b[i];
    }
    sort(a, a + n);
    sort(b, b + n);
    for (int i = 0; i < n; ++i) {
      cout << a[i] << ' ';
    }
    cout << '\n';
    for (int i = 0; i < n; ++i) {
      cout << b[i] << ' ';
    }
    cout << '\n';
  }
  return 0;
}
