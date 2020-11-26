#include <iostream>
#include <deque>
#include <algorithm>
#include <cassert>
using namespace std;

#define maxn int(2e6+10)
#define st first
#define nd second

typedef long long ll;

template<class T>
struct MaxQueue {
  int n;
  deque<pair<T, int>> q;

  MaxQueue() : n(0), q() {}

  int size() { return n; }
  void clear() { n = 0; q.clear(); }
  void pop() { --n; if (!--q.front().nd) q.pop_front(); }
  void push(T x) {
    ++n;
    int k = 0;
    for (; !q.empty() && q.back().st <= x; q.pop_back()) { k += q.back().nd; }
    q.push_back({x, k + 1});
  }
  T front() { return q.front().st; }
};

ll w[maxn];

int solve(int n, ll p, int d) {
  int ans = 0;
  MaxQueue<ll> q;
  for (int l = 1, r = d; r <= n; ++r) {
    q.push(w[r] - w[r - d]);
    for (; w[r] - w[l - 1] - q.front() > p; ++l) { q.pop(); }
    ans = max(ans, r - l + 1);
  }
  return ans;
}

int main() {
  // freopen("in","r",stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  int n, d;
  ll p;
  cin >> n >> p >> d;// p = areia, d = prancha
  for (int i = 1; i <= n; ++i) {
    cin >> w[i];
    w[i] += w[i - 1];
  }
  cout << solve(n, p, d) << '\n';

  return 0;
}
