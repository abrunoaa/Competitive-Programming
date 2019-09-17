#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second

typedef pair<int,int> ii;

const int maxn = (int)5e4 + 3;
const int maxs = (int)sqrt(maxn) + 3;

struct Operation {
  int x, m, pos, sign;
};

int n, q, a[maxn];
int ans[maxn];
int freq[maxn];
int mod[maxs][maxn];
vector<Operation> oper[maxn];

int main() {
  // assert(freopen("in", "r", stdin));
  cin.sync_with_stdio(0), cin.tie(0);
  cin >> n >> q;
  const int bs = (int)sqrt(n);
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  for (int i = 0; i < q; ++i) {
    int l = 0, r = 0, x = 0, m = 0;
    cin >> l >> r >> x >> m;
    oper[r].push_back({x, m, i, +1});
    oper[l - 1].push_back({x, m, i, -1});
  }
  for (int i = 1; i <= n; ++i) {
    for (int m = 1; m <= bs; ++m) {
      ++mod[m][a[i] % m];
    }
    ++freq[a[i]];
    for (auto &op : oper[i]) {
      int tmp = 0;
      if (op.m <= bs) {
        tmp = mod[op.m][op.x];
      } else {
        for (int x = op.x; x < maxn; x += op.m) {
          tmp += freq[x];
        }
      }
      ans[op.pos] += op.sign * tmp;
    }
  }
  for (int i = 0; i < q; ++i) {
    cout << ans[i] << '\n';
  }
  return 0;
}
