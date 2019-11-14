#include <bits/stdc++.h>
using namespace std;

vector<int> build(const string& s) {
  const int n = (int)s.size();
  int diff = 128;                       // 128 = number of starting symbols
  vector<int> p(n), c(n), tmp(n), cnt(n);
  for (int i = 0; i < n; ++i) {
    p[i] = i;
    c[i] = s[i];
  }
  auto fix = [n](int x) {
    return (x < n ? x : x - n);
  };
  for (int k = 0; k < n; k ? k *= 2 : k = 1) {
    cnt.assign(diff, 0);
    for (int i = 0; i < n; ++i) {
      tmp[i] = p[i] - k;
      if (tmp[i] < 0) tmp[i] += n;
    }
    for (int i = 0; i < n; ++i) ++cnt[c[tmp[i]]];
    for (int i = 1; i < diff; ++i) cnt[i] += cnt[i - 1];
    for (int i = n - 1; i >= 0; --i) p[--cnt[c[tmp[i]]]] = tmp[i];

    tmp[p[0]] = 0;
    diff = 1;
    for (int i = 1; i < n; ++i) {
      if (c[p[i]] != c[p[i - 1]] || c[fix(p[i] + k)] != c[fix(p[i - 1] + k)])
        ++diff;
      tmp[p[i]] = diff - 1;
    }
    c.swap(tmp);
  }
  return p;
}

int main() {
  string s(500000, 'a');
  for (char &c : s) c = (char)(rand() % 26 + 'a');
  s += s;
  s.push_back('$');
  // cerr << " ## " << s << endl;
  auto p = build(s);
  // for (int i = 1; i < (int)s.size(); ++i) {
    // assert(s.substr(p[i - 1]) < s.substr(p[i]));
  // }
  return 0;
}
