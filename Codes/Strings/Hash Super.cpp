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
  Hash h;
  h.build("bruno");
  auto res = h(0, 4);
  cout << res.first << endl;
  return 0;
}
