#include <bits/stdc++.h>
using namespace std;

int main() {
  cin.sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n;
  while (cin >> n && n != -1) {
    int r = (int)(sqrt(n) + 1e-6);
    vector<int> d = {1};
    for (int i = 2; i <= r; ++i) {
      if (n % i == 0) {
        d.push_back(i);
        if (i != n / i) {
          d.push_back(n / i);
        }
      }
    }
    sort(d.begin(), d.end());
    int sum = 0;
    for (int x : d) {
      sum += x;
    }
    if (sum != n) {
      cout << n << " is NOT perfect.\n";
    } else {
      cout << n << " =";
      bool flag = 0;
      for (int x : d) {
        if (flag) cout << " +";
        flag = 1;
        cout << ' ' << x;
      }
      cout << '\n';
    }
  }
  return 0;
}
