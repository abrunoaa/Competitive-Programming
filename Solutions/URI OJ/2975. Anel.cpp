#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

template<int base> struct Hash {                  // common bases: 31, 151, 163
  vector<ull> b, h;

  Hash() {}
  explicit Hash(const string& s) { build(s); }
  void build(const string& s) {
    b.resize(s.size());
    h.resize(s.size());
    b[0] = 1;
    h[0] = s[0];
    for (int i = 1; i < (int)b.size(); ++i) {
      b[i] = base * b[i - 1];
      h[i] = h[i - 1] * base + s[i];
    }
  }

  ull operator()(int i, int j) { return h[j] - (!i ? 0 : h[i - 1] * b[j - i + 1]); }
};

const int maxn = (int)1e5 + 3;

int n;
string s;
Hash<151> h1;
Hash<163> h2;

int cmp(int i, int j) {
  int l = 0, r = n - 1;
  while (l < r) {
    int m = (l + r) / 2;
    if (h1(i, i + m) == h1(j, j + m) && h2(i, i + m) == h2(j, j + m)) {
      l = m + 1;
    } else {
      r = m;
    }
  }
  return s[i + r] - s[j + r];
}

int main() {
  // assert(freopen("in", "r", stdin));
  cin.sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> s;
  n = (int)s.size();
  s = s + s;
  h1.build(s);
  h2.build(s);
  int ans = 0, freq = 1;
  for (int i = 1; i < n; ++i) {
    int x = s[ans] != s[i] ? s[ans] - s[i] : cmp(ans, i);
    if (x == 0) {
      ++freq;
    } else if (x < 0) {
      ans = i;
      freq = 1;
    }
  }
  cout << freq << ' ' << ans + 1 << '\n';
  return 0;
}
