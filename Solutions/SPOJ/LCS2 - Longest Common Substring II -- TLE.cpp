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

struct MinQueue {
  deque<pair<int,int>> q;
  void push(int x) {
    int k = 1;
    for (; !q.empty() && x <= q.back().first; q.pop_back()) k += q.back().second;
    q.emplace_back(x, k);
  }
  inline int min() { return q.front().first; }
  inline void pop() { if (!--q.front().second) q.pop_front(); }
};

int main() {
  // assert(freopen("in", "r", stdin));
  cin.sync_with_stdio(0), cin.tie(0), cout.tie(0);
  string s, t;
  // int cnt = 0;
  while (cin >> t) {
    // if (++cnt > 10) break;
    // t = string(100000, 'a');
    // for (char& c : t) c = 'a' + rand() % 26;
    t.push_back('$');
    s += t;
  }
  s.back() = '!';
  int n = (int)s.size();
  vi p = build(s);
  vi lcp = buildLcp(s, p);
  vi pos(n);
  int k = 0;
  for (int i = 0; i < n; ++i) {
    pos[i] = k;
    if (s[i] == '$') ++k;
  }
  ++k;
  vi freq(k);
  int ans = 0;
  MinQueue q;
  for (int l = 0, r = 0; ; ++l) {
    for (int i = 0; i < k; ++i) {
      while (freq[i] == 0) {
        if (r == n) goto out;
        if (l != r) q.push(lcp[r - 1]);
        ++freq[pos[p[r]]];
        ++r;
      }
    }
    ans = max(ans, q.min());
    q.pop();
    --freq[pos[p[l]]];
  }
 out:
  cout << ans << '\n';
  return 0;
}
