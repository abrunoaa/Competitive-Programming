#include <bits/stdc++.h>
using namespace std;

int f[128];

int main() {
  cin.sync_with_stdio(0), cin.tie(0), cout.tie(0);
  string s;
  cin >> s;
  int n = (int)s.size();
  for (int c : s) {
    ++f[c];
  }
  long long ans = 0;
  for (int i = 'a'; i <= 'z'; ++i) {
    ans += (long long)f[i] * f[i];
  }
  cout << fixed << setprecision(10) << (double)ans / n << '\n';
  return 0;
}
