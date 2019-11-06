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

int main() {
  string s = "bruno";
  Hash<153> h1;
  Hash<163> h2;
  h1.build(s);
  h2.build(s);
  cout << h1(1, 2) << ' ' << h2(1, 2) << endl;
  return 0;
}
