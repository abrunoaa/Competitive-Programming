#include <bits/stdc++.h>
using namespace std;

#define maxn 1003
#define maxm 100003
#define maxp 1000003

struct Item {
  int beg, end, cost;
  bool operator < (const Item &x) const {
    return beg < x.beg;
  }
};

struct Qry {
  int beg, end, cost, i;
  bool operator < (const Qry &x) const {
    return beg < x.beg;
  }
};

bool ans[maxp];
int n, p, dp[maxm];
Item item[maxn];
Qry qry[maxp];

void add(int w, int t) { // w = peso, t = tempo final disponível
  for (int i = maxm - 1; i >= w; --i) {
    dp[i] = max(dp[i], min(t, dp[i - w]));
  }
}

int main() {
  // freopen("in","r",stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  cin >> n;
  for (int i = 0; i < n; ++i) {
    Item &x = item[i];
    cin >> x.cost >> x.beg >> x.end;
  }
  cin >> p;
  for (int i = 0; i < p; ++i) {
    Qry &q = qry[i];
    cin >> q.beg >> q.cost >> q.end;
    q.end += q.beg;
    q.i = i;
  }

  sort(item, item + n);
  sort(qry, qry + p);

  dp[0] = 2e9 + 10;
  for (int i = 0, j = 0; i < p; ++i) {
    Qry &q = qry[i];
    for (; j < n && item[j].beg <= q.beg; ++j) {
      add(item[j].cost, item[j].end);
    }
    ans[q.i] = dp[q.cost] > q.end;
  }
  for (int i = 0; i < p; ++i) {
    cout << (ans[i] ? "TAK" : "NIE") << '\n';
  }

  return 0;
}
