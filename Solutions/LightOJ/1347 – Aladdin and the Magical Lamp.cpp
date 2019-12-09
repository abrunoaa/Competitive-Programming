#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;
typedef unsigned uns;
typedef vector<uns> vu;

const ull base = 153;

template <uns, uns...> struct BasicHash;

template <uns mod> struct BasicHash<mod> {
  static vu p;
  vu h;

  static void init(int max) {
    p.resize(max);
    p[0] = 1;
    for (int i = 1; i < max; ++i) p[i] = (uns)(base * p[i - 1] % mod);
  }

  void build(const string& s) {
    int n = (int)s.size();
    h.resize(n);
    h[0] = s[0];
    for (int i = 1; i < n; ++i) h[i] = (unsigned)((base * h[i - 1] + s[i]) % mod);
  }

  typedef unsigned int Tp;
  unsigned operator()(int i, int j) {
    int ans = (int)(h[j] - (!i ? 0 : (ull)h[i - 1] * p[j - i + 1] % mod));
    return (ans < 0 ? ans + mod : ans);
  }
};

template <uns mod> vu BasicHash<mod>::p;

template <uns mod, uns... others> struct BasicHash { ~BasicHash() {}
  typedef BasicHash<mod> H1;
  typedef BasicHash<others...> H2;

  H1 h1;
  H2 h2;

  static void init(int max) { H1::init(max); H2::init(max); }
  inline void build(const string& s) { h1.build(s); h2.build(s); }

  typedef pair<uns, typename BasicHash<others...>::Tp> Tp;
  inline Tp operator()(int i, int j) { return {h1(i, j), h2(i, j)}; }
};

constexpr int randomPrime() {
  int x = 0;
  for (char c : __TIME__) x = (11 * x + c - '0');
  x += x % 2 + (int)4.9e8 + 55;
  while (1) {
    bool ok = 1;
    for (int i = 3, up = (int)sqrt(x); ok &= x % i != 0, i <= up; i += 2);
    if (ok) return x;
    x += 2;
  }
}

typedef BasicHash<(int)1e9+21, randomPrime()> Hash;

int main() {
  // assert(freopen("in", "r", stdin));
  cin.sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int T;
  cin >> T;
  Hash::init(5003);
  Hash h1, h2, h3;
  for (int t = 1; t <= T; ++t) {
    string a, b, c;
    cin >> a >> b >> c;
    h1.build(a);
    h2.build(b);
    h3.build(c);
    int l = 0, r = (int)min(a.size(), min(b.size(), c.size()));
    while (l < r) {
      int m = (l + r + 1) / 2;
      bool ok = 0;
      set<Hash::Tp> s1, s2;
      for (int i = 0; i + m - 1 < (int)a.size(); ++i) {
        auto h = h1(i, i + m - 1);
        s1.insert(h);
      }
      for (int i = 0; i + m - 1 < (int)b.size(); ++i) {
        auto h = h2(i, i + m - 1);
        if (s1.count(h)) s2.insert(h);
      }
      for (int i = 0; i + m - 1 < (int)c.size(); ++i) {
        auto h = h3(i, i + m - 1);
        if (s2.count(h)) {
          ok = 1;
          break;
        }
      }
      ok ? l = m : r = m - 1;
    }
    cout << "Case " << t << ": " << r << '\n';
  }
  return 0;
}
