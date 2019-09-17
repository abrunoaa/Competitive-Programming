#include <bits/stdc++.h>
using namespace std;

map<unsigned,int> allow[33];
map<unsigned,int> deny[33];

inline void clean(unsigned &ip, int &mask) {
  ip &= (unsigned)~((1ull << (32 - mask)) - 1);
}

inline int get(auto& mp, unsigned ip) {
  return (!mp.count(ip) ? (int)1e9 : mp[ip]);
}

void parse(const string& s, unsigned &ip, int &mask) {
  ip = 0;
  mask = 32;
  stringstream ss(s);
  for (int i = 3; i >= 0; --i) {
    unsigned x;
    char c;
    ss >> x >> c;
    ip |= x << (8 * i);
  }
  ss >> mask;
  clean(ip, mask);
}

int main() {
  assert(freopen("access.in", "r", stdin));
  assert(freopen("access.out", "w", stdout));
  cin.sync_with_stdio(0), cin.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    string op, ign, addr;
    cin >> op >> ign >> addr;
    unsigned ip;
    int mask;
    parse(addr, ip, mask);
    auto &x = (op[0] == 'a' ? allow[mask][ip] : deny[mask][ip]);
    if (!x) {
      x = i;
    }
  }
  int q;
  cin >> q;
  while (q--) {
    string addr;
    cin >> addr;
    unsigned ip;
    int mask;
    parse(addr, ip, mask);
    int a = (int)1e9 - 1, d = (int)1e9;
    for (int i = 32; i >= 0; --i) {
      clean(ip, i);
      a = min(a, get(allow[i], ip));
      d = min(d, get(deny[i], ip));
    }
    cout << (a < d ? 'A' : 'D');
  }
  cout << '\n';
  return 0;
}
