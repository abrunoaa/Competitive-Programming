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

vi buildLcp(const string& s, const vi& p) {
  const int n = (int)p.size();
  vi lcp(n - 1), rank(n);
  for (int i = 0; i < n; ++i) rank[p[i]] = i;
  for (int i = 0, k = 0; i < n; ++i) if (rank[i] != n - 1) {
    int j = p[rank[i] + 1];
    while (s[i + k] == s[j + k]) ++k;   // s.back() must be unique
    lcp[rank[i]] = k;
    if (k) --k;
  }
  return lcp;
}

int main() {
  cin.sync_with_stdio(0), cin.tie(0), cout.tie(0);
  string s;
  cin >> s;
  s.push_back('$');
  vi p = build(s);
  vi lcp = buildLcp(s, p);
  vector<long long> ans(26);
  for (int i = 1; i < (int)s.size(); ++i) {
    ans[s[p[i]] - 'a'] += (int)s.size() - 1 - p[i] - lcp[i - 1];
  }
  for (int i = 0; i < 26; ++i) {
    if (i) cout << ' ';
    cout << ans[i];
  }
  cout << '\n';
  return 0;
}
