#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

vi build(const string& s) {   // cache friend
  const int n = (int)s.size();
  int d = 128;                // 128 = number of starting symbols
  vi p(n), c(n), cnt(n), tmp(n), tmp2(n);
  auto fix = [n](int x) { return (x < n ? x : x - n); };
  for (int i = 0; i < n; ++i) { p[i] = i; c[i] = s[i]; }
  for (int k = 0; k < n; k ? k *= 2 : ++k) {
    cnt.assign(d, 0);
    for (int i = 0; i < n; ++i) {
      tmp[i] = fix(p[i] - k + n);
      tmp2[i] = c[tmp[i]];
    }
    for (int i = 0; i < n; ++i) ++cnt[tmp2[i]];
    for (int i = 1; i < d; ++i) cnt[i] += cnt[i - 1];
    for (int i = n - 1; i >= 0; --i) tmp2[i] = --cnt[tmp2[i]];
    for (int i = 0; i < n; ++i) p[tmp2[i]] = tmp[i];
    tmp[p[0]] = 0;
    d = 1;
    for (int i = 1; i < n; ++i) {
      if (c[p[i]] != c[p[i - 1]] || c[fix(p[i] + k)] != c[fix(p[i - 1] + k)]) ++d;
      tmp[p[i]] = d - 1;
    }
    c.swap(tmp);
    if (d == n) break;
  }
  return p;
}

string root(const string& s) {
  int n = (int)s.size();
  vector<int> div = {1};
  for (int d = 2, r = (int)sqrt(n); d <= r; ++d) {
    if (n % d == 0) {
      div.push_back(d);
      if (d != n / d) {
        div.push_back(n / d);
      }
    }
  }
  sort(div.begin(), div.end());
  for (int d : div) {
    int i, j;
    for (i = j = 0; i < n && s[i] == s[j]; ++i, j = (j + 1) % d);
    if (i == n) return s.substr(0, d);
  }
  return s;
}

int main() {
  // assert(freopen("in", "r", stdin));
  cin.sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    int n = (int)s.size();
    for (int x : build(root(s))) {
      if (x < n) {
        cout << x + 1 << '\n';
        break;
      }
    }
  }
  return 0;
}
