#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;

int n;              // the size of s including the sentinels
string s;           // the string itself
vi p;               // the suffix array

int fix(int x) { return (x < n ? x : x - n); }

void build() {                // cache friend
  n = (int)s.size();
  p.resize(n);
  int d = 128;                // 128 = number of starting symbols
  vi r(n), cnt(n), tmp(n), tmp2(n);
  for (int i = 0; i < n; ++i) { p[i] = i; r[i] = s[i]; }
  for (int k = 0; k < n; k ? k *= 2 : ++k) {
    cnt.assign(d, 0);
    for (int i = 0; i < n; ++i) tmp[i] = fix(p[i] - k + n);   // radix sort
    for (int i = 0; i < n; ++i) tmp2[i] = r[tmp[i]];          // count sort
    for (int i = 0; i < n; ++i) ++cnt[tmp2[i]];
    for (int i = 1; i < d; ++i) cnt[i] += cnt[i - 1];
    for (int i = n - 1; i >= 0; --i) tmp2[i] = --cnt[tmp2[i]];
    for (int i = 0; i < n; ++i) p[tmp2[i]] = tmp[i];
    tmp[p[0]] = 0;
    d = 0;          // d + 1 = number of distinct substrings
    for (int i = 1; i < n; ++i) {
      if (r[p[i]] != r[p[i - 1]] || r[fix(p[i] + k)] != r[fix(p[i - 1] + k)]) ++d;
      tmp[p[i]] = d;
    }
    r.swap(tmp);
    if (d + 1 == n) break;    // doesn't work if r is needed
  }
}

/* String comparison in O(1) */
vi rnk[20];         // rnk[k]: the rank r at iteration k of build
vi lg;              // lg[i] = (int)log2(i) = lg[i - 1] + ((i & (i - 1)) == 0)

int cmp(int i, int j, int len) {
  int k = lg[len];
  ii a = {rnk[k][i], rnk[k][fix(i + len - (1 << k))]};
  ii b = {rnk[k][j], rnk[k][fix(j + len - (1 << k))]};
  return a == b ? 0 : a < b ? -1 : 1;
}

/* Longest common prefix */
vi lcp;

void buildLcp() {
  lcp.resize(n - 1);
  vi rank(n);
  for (int i = 0; i < n; ++i) rank[p[i]] = i;
  for (int i = 0, k = 0; i < n; ++i) if (rank[i] != n - 1) {
    int j = p[rank[i] + 1];
    while (s[i + k] == s[j + k]) ++k;   // s.back() must be unique
    lcp[rank[i]] = k;
    if (k) --k;
  }
}

/* String counting (or whatever) */
ii find(const string& t) {              // find the range in S.A. which equals t
  auto find = [&](int l, int r, auto cmp) {
    while (l < r) {
      int m = (l + r) / 2;
      cmp(s.compare(p[m], t.size(), t), 0) ? l = m + 1 : r = m;
    }
    return r;
  };
  int l = find(0, (int)p.size() - 1, less<int>());
  if (s.compare(p[l], t.size(), t) != 0) return {-1, -1};
  int r = find(l + 1, (int)p.size(), less_equal<int>());
  return {l, r - 1};
}

/* Number of different substrings:                                   *
 *   - The length of string starting at i (n - p[i])                 *
 *   - Except the prefixes that match the previous string (p[i - 1]) *
 *                                                                   *
 * ans = sum(n - p[i] - lcp[i - 1]) = n * (n + 1) / 2 - sum(lcp[i])  */

int main() {
  // for (int t = 0; t < 1000; ++t) {
    s.resize(10000);
    for (char &c : s) c = (char)(rand() % 26 + 'a');
    s += s;
    s.push_back('$');
    build();
    // cerr << " ## " << s << endl;
    for (int i = 1; i < (int)s.size(); ++i) {
      assert(s.substr(p[i - 1]) < s.substr(p[i]));
    }
    buildLcp();
    for (int i = 0; i < (int)s.size() - 1; ++i) {
      int k = 0;
      while (s[p[i] + k] == s[p[i + 1] + k]) ++k;
      assert(lcp[i] == k);
    }
  // }
  return 0;
}
