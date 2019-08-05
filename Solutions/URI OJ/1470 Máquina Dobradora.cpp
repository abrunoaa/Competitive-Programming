#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

vi v, w1, w2;

bool f(vi &v) {
  if (v == w1 || v == w2) { return 1; }
  if (v.size() < w1.size()) { return 0; }
  for (int i = 1; i < (int)v.size(); ++i) {
    vi u;
    for (int j = 0; j < i; ++j) { u.push_back((2 * i - j - 1 >= (int)v.size() ? 0 : v[2 * i - j - 1]) + v[j]); }
    for (int j = 2 * i; j < (int)v.size(); ++j) { u.push_back(v[j]); }
    if (f(u)) { return 1; }
  }
  return 0;
}

int main() {
  // freopen("in", "r", stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  int n, m;
  while (cin >> n) {
    v.resize(n);
    for (int &x : v) { cin >> x; }
    cin >> m;
    w1.resize(m);
    for (int &x : w1) { cin >> x; }
    w2.assign(w1.rbegin(), w1.rend());
    cout << (f(v) ? 'S' : 'N') << '\n';
  }

  return 0;
}
