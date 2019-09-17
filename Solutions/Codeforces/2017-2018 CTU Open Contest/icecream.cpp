#include <bits/stdc++.h>
using namespace std;

const int maxn = (int)1e6 + 3;

int n, k;
int cost, brand;
int freq[maxn];
vector<int> a[maxn];

bool input() {
  if (!(cin >> n >> k)) return 0;
  for (int i = 0; i < n; ++i) {
    int m;
    cin >> m;
    a[i].resize(m);
    for (int &x : a[i]) {
      cin >> x;
    }
  }
  return 1;
}

void add(vector<int> &v, int s) {
  cost += s * (int)v.size();
  for (int x : v) {
    freq[x] += s;
    if (freq[x] == 0) {
      --brand;
    } else if (freq[x] == 1 && s > 0) {
      ++brand;
    }
  }
}

int solve() {
  int ans = (int)1e9;
  for (int l = 0, r = 0; l < n; ++l) {
    for (; r < 2 * n && brand < k; ++r) {
      add(a[r % n], +1);
    }
    if (brand < k) {
      break;
    }
    ans = min(ans, cost);
    add(a[l], -1);
  }
  return (ans == (int)1e9 ? -1 : ans);
}

int main() {
  // assert(freopen("in", "r", stdin));
  cin.sync_with_stdio(0), cin.tie(0), cout.tie(0);
  while (input()) {
    memset(freq, 0, sizeof(freq));
    cost = brand = 0;
    cout << solve() << '\n';
  }
  return 0;
}
