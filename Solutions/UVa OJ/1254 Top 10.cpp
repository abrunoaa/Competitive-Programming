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

#define L (2 * t)
#define R (L + 1)
#define M ((l + r) / 2)

const int maxn = (int)2e5;

int n;
int slen;  // s.len
SuffixArray sa;
string &s = sa.s;
vi pos, len, lex;
vi st[4 * maxn];

void read() {
  cin >> n;
  vector<string> words(n);
  map<string, int> mp;
  for (string &str : words) {
    cin >> str;
    mp[str];
  }
  int k = 0;
  for (auto &pair : mp) {
    pair.second = ++k;
  }
  for (string &str : words) {
    s += str;
    s.push_back('$');
    lex.push_back(mp[str]);
    len.push_back((int)str.size());
    pos.push_back((int)s.size() - 1);
  }
  s.back() = '!';
}

vi merge(const vi& x, const vi& y) {
  vi z(x.size() + y.size());
  merge(x.begin(), x.end(), y.begin(), y.end(), z.begin(), [](int i, int j) {
    if (len[i] != len[j]) return len[i] < len[j];
    if (lex[i] != lex[j]) return lex[i] < lex[j];
    return i < j;
  });
  z.resize(min(10, (int)(unique(z.begin(), z.end()) - z.begin())));
  return z;
}

vi& build(int t = 1, int l = 0, int r = slen - 1) {
  if (l == r) return st[t] = {(int)(lower_bound(pos.begin(), pos.end(), sa.p[r]) - pos.begin())};
  return st[t] = merge(build(L, l, M), build(R, M + 1, r));
}

vi qry(int i, int j, int t = 1, int l = 0, int r = slen - 1) {
  if (r < i || j < l) return vi();
  if (i <= l && r <= j) return st[t];
  return merge(qry(i, j, L, l, M), qry(i, j, R, M + 1, r));
}

void solve() {
  int q;
  cin >> q;
  while (q--) {
    string t;
    cin >> t;
    int a, b;
    tie(a, b) = sa.find(t);
    if (a == -1) {
      cout << "-1\n";
    } else {
      bool flag = 0;
      for (int x : qry(a, b)) {
        if (flag) cout << ' ';
        flag = 1;
        cout << x + 1;
      }
      cout << '\n';
    }
  }
}

int main() {
  // assert(freopen("in", "r", stdin));
  cin.sync_with_stdio(0), cin.tie(0), cout.tie(0);
  read();
  slen = (int)s.size();
  sa.build();
  build();
  solve();
  return 0;
}
