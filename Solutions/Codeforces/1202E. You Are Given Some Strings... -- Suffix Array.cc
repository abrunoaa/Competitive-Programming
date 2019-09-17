#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;

const int maxn = (int)2e5 + 3;

template<int maxn> struct SuffixArray {
  static_assert(maxn > 255, "");

  const int n;
  const string t;
  int sa[maxn], c[maxn], tmp[maxn], rnk[maxn];

  explicit SuffixArray(const string& s) : n((int)s.size() + 1), t(s + "$"), c() {
    for (int i = 0; i < n; ++i) {
      rnk[i] = t[i];
      sa[i] = i;
    }
    for (int k = 1; k < n && (rnk[sa[n - 1]] != n - 1 || k == 1); k *= 2) {
      sort(k), sort(0);
      tmp[sa[0]] = 0;
      for (int i = 1, r = 0; i < n; ++i) {
        if (rnk[sa[i]] != rnk[sa[i - 1]] || rnk[sa[i] + k] != rnk[sa[i - 1] + k]) {
          ++r;
        }
        tmp[sa[i]] = r;
      }
      for (int i = 0; i < n; ++i) {
        rnk[i] = tmp[i];
      }
    }
  }

  void sort(int k) {
    int lim = max(256, n);
    memset(c, 0, lim * sizeof(c[0]));
    for (int i = 0; i < n; ++i) {
      ++c[i + k < n ? rnk[i + k] : 0];
    }
    for (int i = 0, sum = 0; i < lim; ++i) {
      int x = c[i];
      c[i] = sum;
      sum += x;
    }
    for (int i = 0; i < n; ++i) {
      int &x = c[sa[i] + k < n ? rnk[sa[i] + k] : 0];
      tmp[x] = sa[i];
      ++x;
    }
    for (int i = 0; i < n; ++i) {
      sa[i] = tmp[i];
    }
  }

  // busca binária por p -- cmp = less | less_equal
  int find(const string& p, const auto& cmp) const {
    int i = 0, j = n - 1;
    while (i < j) {
      int k = (i + j) / 2;
      if (cmp(strncmp(t.data() + sa[k], p.data(), p.size()), 0)) {
        i = k + 1;
      } else {
        j = k;
      }
    }
    return i;
  }

  // encontra [início, fim] de um intervalo que tem o prefixo p; -1 se não existir
  ii match(const string& p) const {
    int i = find(p, less<int>());
    if (strncmp(t.data() + sa[i], p.data(), p.size()) != 0) return {-1, -1};
    int j = find(p, less_equal<int>());
    if (strncmp(t.data() + sa[j], p.data(), p.size()) != 0) --j;
    return {i, j};
  }

  // retorna qtd de string's s que daria match com t na posição k para todo k
  vector<int> matches(const string* s, int m) const {
    vector<int> u(t.size()), v(t.size() + 1);
    for (int i = 0; i < m; ++i) {
      ii g = match(s[i]);
      if (g.first >= 0) {
        ++v[g.first];
        --v[g.second + 1];
      }
    }
    for (int i = 1; i < (int)t.size(); ++i) v[i] += v[i - 1];
    for (int i = 1; i < (int)t.size(); ++i) u[sa[i]] = v[i];
    u.pop_back();   // remove o $
    return u;
  }
};

int n;
string t, s[maxn];

int main() {
  // assert(freopen("in", "r", stdin));
  cin.sync_with_stdio(0), cin.tie(0);
  cin >> t >> n;
  for (int i = 0; i < n; ++i) cin >> s[i];
  auto u = SuffixArray<maxn>(t).matches(s, n);
  reverse(t.begin(), t.end());
  for (int i = 0; i < n; ++i) {
    reverse(s[i].begin(), s[i].end());
  }
  auto v = SuffixArray<maxn>(t).matches(s, n);
  reverse(v.begin(), v.end());
  long long ans = 0;
  for (int i = 1; i < (int)t.size(); ++i) {
    ans += (long long)v[i - 1] * u[i];
  }
  cout << ans << '\n';
  return 0;
}
