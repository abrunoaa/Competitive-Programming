#include <bits/stdc++.h>
using namespace std;

vector<int> build(const string& s) {
  const int n = (int)s.size();
  auto fix = [n](int x) { return (x < n ? x : x - n); };

  vector<int> p(n);
  for (int i = 0; i < n; ++i) {
    p[i] = i;
  }
  sort(p.begin(), p.end(), [&s](int i, int j) {
    return s[i] < s[j];
  });

  vector<int> c(n);
  c[p[0]] = 0;
  for (int i = 1, diff = 0; i < n; ++i) {
    if (s[p[i]] != s[p[i - 1]]) {
      ++diff;
    }
    c[p[i]] = diff;
  }

  vector<int> tmp(n);
  for (int k = 1; k < n; k *= 2) {
    sort(p.begin(), p.end(), [&](int i, int j) {
      if (c[i] != c[j]) {
        return c[i] < c[j];
      }
      return c[fix(i + k)] < c[fix(j + k)];
    });

    tmp[p[0]] = 0;
    for (int i = 1, diff = 0; i < n; ++i) {
      if (c[p[i]] != c[p[i - 1]] || c[fix(p[i] + k)] != c[fix(p[i - 1] + k)]) {
        ++diff;
      }
      tmp[p[i]] = diff;
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
