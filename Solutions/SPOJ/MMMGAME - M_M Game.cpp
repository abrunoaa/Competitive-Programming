#include <bits/stdc++.h>
using namespace std;

bool misereNim(vector<int> v) {
  int n = v.size();
  int ones = 0;
  int m = -1;
  for (int x : v) {
    if (x == 1) {
      ++ones;
    }
    m = max(m, x);
  }

  if (n - ones <= 1) { // jogo prox do fim
    return m > 1 || n % 2 == 0;
  }

  int ans = 0;
  for (int x : v) {
    ans ^= x;
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<int> v(n);
    for (int &x : v) {
      cin >> x;
    }
    cout << (misereNim(v) ? "John" : "Brother") << '\n';
  }

  return 0;
}
