#include <bits/stdc++.h>
using namespace std;

int convert(int c, int k) {
  c = (c == ' ' ? 0 : c - 'A' + 1);
  c = (c + k) % 27;
  return (c == 0 ? ' ' : 'A' + c - 1);
}

int main() {
  // freopen("in","r",stdin);
  ios::sync_with_stdio(0), cin.tie(0);

  string s;
  set<string> dict;

  while (cin >> s, s != "#") {
    dict.insert(s);
  }

  cin.ignore();
  getline(cin, s);
  int n = s.size();

  int ansMatch = -1, ansk = -1;
  for (int k = 0; k <= 26; ++k) {
    string t(n + 1, 0);
    t[n] = ' ';
    for (int i = 0; i < n; ++i) {
      t[i] = convert(s[i], k);
    }

    string u;
    int match = 0;
    for (int i = 0; i <= n; ++i) {
      if (t[i] == ' ') {
        match += dict.count(u);
        u.clear();
      } else {
        u.push_back(t[i]);
      }
    }

    if (match > ansMatch) {
      ansMatch = match;
      ansk = k;
    }
  }

  for (char &c : s) {
    c = convert(c, ansk);
  }

  string ans;
  s.push_back(' ');
  for (int p = 0, d, stop = 0; !stop; p += d) {
    while (s[p] == ' ') {
      ++p;
    }

    if (s.size() - p <= 60) {
      d = s.size() - p;
      stop = 1;
    } else {
      d = -1;
      for (int i = 0; i <= 60; ++i) {
        if (s[p + i] == ' ') {
          d = i + 1;
        }
      }
    }

    ans += (ans.empty() ? "" : "\n") + s.substr(p, d);
    while (ans.back() == ' ') {
      ans.pop_back();
    }
  }
  cout << ans << '\n';

  return 0;
}
