#include <bits/stdc++.h>
using namespace std;

vector<int> build(const string& s) {
  vector<int> p(s.size());
  for (int i = 0; i < (int)p.size(); ++i) {
    p[i] = i;
  }
  sort(p.begin(), p.end(), [&](int i, int j) {
    return s.substr(i) < s.substr(j);
  });
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
