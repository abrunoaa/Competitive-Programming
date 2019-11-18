#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

vi build(const string& s) {
  const int n = (int)s.size();
  vi p(n), c(n), tmp(n);
  for (int i = 0; i < n; ++i) { p[i] = i; c[i] = s[i]; }
  auto fix = [n](int x) { return (x < n ? x : x - n); };
  for (int k = 0; k < n; k ? k *= 2 : ++k) {
    sort(p.begin(), p.end(), [&](int i, int j) {
      if (c[i] != c[j]) return c[i] < c[j];
      return c[fix(i + k)] < c[fix(j + k)];
    });
    tmp[p[0]] = 0;
    for (int i = 1, d = 0; i < n; ++i) {
      if (c[p[i]] != c[p[i - 1]] || c[fix(p[i] + k)] != c[fix(p[i - 1] + k)]) ++d;
      tmp[p[i]] = d;
    }
    c.swap(tmp);
  }
  return p;
}

int main() {
  string s(50000, 'a');
  for (char &c : s) c = (char)(rand() % 26 + 'a');
  s += s;
  s.push_back('$');
  // cerr << " ## " << s << endl;
  auto p = build(s);
  for (int i = 1; i < (int)s.size(); ++i) {
    assert(s.substr(p[i - 1]) < s.substr(p[i]));
  }
  return 0;
}
