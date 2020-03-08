#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second

typedef long long ll;

const int maxn = (int)2e5 + 3;

int n;
pair<int, int> p[maxn];
pair<ll, int> ft[maxn];
map<int, int> mp;

void add(int i, int x) {
  for (i = mp[i]; i; i -= i & -i) {
    ft[i].st += x;
    ft[i].nd += 1;
  }
}

auto qry(int i) {
  pair ans(0ll, 0);
  for (i = mp[i]; i < maxn; i += i & -i) {
    ans.st += ft[i].st;
    ans.nd += ft[i].nd;
  }
  return ans;
}

ll sum() {
  memset(ft, 0, (n + 1) * sizeof(*ft));
  sort(p, p + n);
  mp.clear();
  for (int i = 0; i < n; ++i) {
    if (p[i].nd > 0) {
      mp[p[i].nd];
    }
  }
  int m = 0;
  for (auto &[k, v] : mp) {
    v = ++m;
  }

  ll ans = 0;
  for (int i = n - 1; i >= 0; --i) {
    if (p[i].nd > 0) {
      auto [s, q] = qry(p[i].nd);
      ans += s - (ll)q * p[i].st;
      add(p[i].nd, p[i].st);
    }
  }

  // cerr << " >> " << ans << endl;
  return ans;
}

int main() {
  // assert(freopen("in", "r", stdin));
  cin.sync_with_stdio(0), cin.tie(0), cout.tie(0);
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> p[i].st;
  }
  for (int i = 0; i < n; ++i) {
    cin >> p[i].nd;
  }

  ll ans = sum();
  for (int i = 0; i < n; ++i) {
    p[i].st = p[n - 1].st - p[i].st + 1;
    p[i].nd *= -1;
  }
  ans += sum();

  ll cost = 0;
  for (int i = 0, q = 0; i < n; ++i) {
    if (p[i].nd >= 0) {
      ans += (ll)q * p[i].st - cost;
    }
    if (p[i].nd <= 0) {
      cost += p[i].st;
      ++q;
    }
  }

  cout << ans << '\n';
  return 0;
}
