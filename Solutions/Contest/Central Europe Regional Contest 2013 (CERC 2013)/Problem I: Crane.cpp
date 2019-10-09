#include <bits/stdc++.h>
using namespace std;

const int maxn = 10003;

int a[maxn], b[maxn], delay[maxn];
vector<int> delSwap;
vector<pair<int,int>> ans;

void run(int i, int j, int off = 0) {
  if (i == j) return;
  if ((j - i + 1) & 1) {
    run(i + 1, j, off);
    ans.emplace_back(i, i + 1);
    delSwap.push_back(i);
    return;
  }
  int m = (j - i + 1) / 2;
  delay[off + i] += m;
  delay[off + i + m] += -2 * m;
  delay[off + i + 2 * m] += m;
  ans.emplace_back(i, j);
  run(i, j - m, off + m);
}

int main() {
  // assert(freopen("in", "r", stdin));
  cin.sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) {
      cin >> a[i];
    }
    for (int i = 1; i <= n; ++i) {
      if (a[i] == i) continue;
      int j;
      for (j = i + 1; a[j] != i; ++j);
      delSwap.clear();
      run(i, j);
      for (int k = i; k <= n; ++k) {
        b[k + delay[k]] = a[k];
        delay[k + 1] += delay[k];
        delay[k] = 0;
      }
      for (int k = i; k <= n; ++k) {
        a[k] = b[k];
      }
      for (int s : delSwap) {
        swap(a[s], a[s + 1]);
      }
    }
    cout << ans.size() << '\n';
    for (auto p : ans) {
      int s1, s2;
      tie(s1, s2) = p;
      cout << s1 << ' ' << s2 << '\n';
    }
    ans.clear();
  }
  return 0;
}
