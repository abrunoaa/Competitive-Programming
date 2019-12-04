#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

struct SuffixArray { ~SuffixArray(){}
  int n;
  string s;
  vi p, lcp;

  void build() {                // cache friend
    n = (int)s.size();
    p.resize(n);
    int d = 128;                // 128 = number of starting symbols
    vi c(n), cnt(n), tmp(n), tmp2(n);
    auto fix = [this](int x) { return (x < n ? x : x - n); };
    for (int i = 0; i < n; ++i) { p[i] = i; c[i] = s[i]; }
    for (int k = 0; k < n; k ? k *= 2 : ++k) {
      cnt.assign(d, 0);
      for (int i = 0; i < n; ++i) tmp[i] = fix(p[i] - k + n);
      for (int i = 0; i < n; ++i) tmp2[i] = c[tmp[i]];
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
  }

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

  pair<int,int> find(const string& t) {
    auto find = [&](int l, int r, function<bool(int, int)> cmp) {
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
};

int main() {
  // for (int t = 0; t < 1000; ++t) {
    string s(10000, 'a');
    s.resize(10000);
    for (char &c : s) c = (char)(rand() % 26 + 'a');
    s += s;
    s.push_back('$');
    SuffixArray sa;
    sa.s = s;
    sa.build();
    // cerr << " ## " << s << endl;
    for (int i = 1; i < (int)s.size(); ++i) {
      assert(s.substr(sa.p[i - 1]) < s.substr(sa.p[i]));
    }
    sa.buildLcp();
    for (int i = 0; i < (int)s.size() - 1; ++i) {
      int k = 0;
      while (s[sa.p[i] + k] == s[sa.p[i + 1] + k]) ++k;
      assert(sa.lcp[i] == k);
    }
  // }
  return 0;
}
