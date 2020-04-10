#include <bits/stdc++.h>
using namespace std;

const int maxn = (int)1e6 + 3;

int n, q;
int a[maxn];
map<int, int> c[maxn];

void remove(int x){
  auto &mp = c[a[x]];
  auto it = mp.upper_bound(x);
  --it;
  // cerr << " >> remove " << x << ": " << it->first << ' ' << it->second << endl;
  if (it->second == 1) {
    mp.erase(it);
  } else if (it->first == x) {
    int len = it->second;
    mp.erase(it);
    mp[x + 1] = len - 1;
  } else if (it->first + it->second - 1 == x) {
    --it->second;
  } else {
    auto r = *it;
    mp.erase(it);
    mp.insert({r.first, x - r.first});
    mp.insert({x + 1, r.first + r.second - x - 1});
  }
}

void add(int x) {
  // cerr << " >> add " << x << ' ' << a[x] << endl;
  auto &mp = c[a[x]];
  auto it = mp.upper_bound(x);
  if (it != mp.end() && it->first == x + 1) {
    // cerr << " -- " << it->first << ' ' << it->second << endl;
    auto prev = it;
    --prev;
    if (prev->first + prev->second == x) {
      int len = it->second;
      mp.erase(it);
      prev->second += len + 1;
    } else {
      int len = it->second;
      mp.erase(it);
      mp[x] = len + 1;
    }
  } else {
    if (it != mp.begin()) {
      --it;
    }
    // cerr << " ## " << it->first << ' ' << it->second << endl;
    if (it != mp.end() && it->first + it->second == x) {
      ++it->second;
    } else {
      mp[x] = 1;
    }
  }
}

int main() {
  // assert(freopen("in", "r", stdin));
  cin.sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n >> q;
  for (int i = 0, p = 0; i < n; ++i) {
    cin >> a[i];
    if (i == 0 || a[i] != a[i - 1]) {
      p = i;
    }
    ++c[a[i]][p];
  }
  while (q--) {
    int t, x, nc;
    cin >> t >> x;
    if (t == 1) {
      --x;
      cin >> nc;
      if (nc != a[x]) {
        remove(x);
        a[x] = nc;
        add(x);
      }
    } else {
      cout << c[x].size() << '\n';
    }
  }
  return 0;
}
