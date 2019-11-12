#include <bits/stdc++.h>
using namespace std;

inline int fix(int x, int mod) {
  if (x >= mod) x -= mod;
  return x;
}

vector<int> build(const string& s) {
  const int n = (int)s.size();

  vector<int> p(n);
  for (int i = 0; i < n; ++i) {
    p[i] = i;
  }
  sort(p.begin(), p.end(), [&s](int i, int j) {
    return s[i] < s[j];
  });

  vector<int> c(n);
  c[p[0]] = 0;
  for (int i = 1, classes = 0; i < n; ++i) {
    if (s[p[i]] != s[p[i - 1]]) {
      ++classes;
    }
    c[p[i]] = classes;
  }

  vector<int> tmp(n);
  for (int k = 1; (1 << k) <= n; ++k) {
    sort(p.begin(), p.end(), [&](int i, int j) {
      if (c[i] != c[j]) {
        return c[i] < c[j];
      }
      return c[fix(i + (1 << (k - 1)), n)] < c[fix(j + (1 << (k - 1)), n)];
    });

    tmp[p[0]] = 0;
    for (int i = 1, classes = 0; i < n; ++i) {
      if (c[p[i]] != c[p[i - 1]] || c[fix(p[i] + (1 << (k - 1)), n)] != c[fix(p[i - 1] + (1 << (k - 1)), n)]) {
        ++classes;
      }
      tmp[p[i]] = classes;
    }
    c = tmp;
  }

  return p;
}

int main() {
  srand(0);
  string s(50000, 'a');
  for (char &c : s) {
    c = (char)(rand() % 26 + 'a');
  }
  s += s;
  s.push_back('$');
  // cerr << " ## " << s << endl;
  auto p = build(s);
  for (int i = 1; i < (int)s.size(); ++i) {
    assert(s.substr(p[i - 1]) < s.substr(p[i]));
  }
  return 0;
}
