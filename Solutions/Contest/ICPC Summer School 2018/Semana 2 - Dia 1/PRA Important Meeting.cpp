#include <iostream>
#include <queue>
#include <algorithm>
#include <bitset>
using namespace std;

#define maxn int(1e6+3)
#define st first
#define nd second

typedef pair<int, int> ii;

struct Emp {
  int a, b, i;
  bool operator < (const Emp &x) const { return a < x.a; }
};

Emp s[maxn];
bitset<maxn> isAns;

int main() {
  // freopen("in","r",stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  int n, k;
  cin >> n >> k;
  for (int i = 0; i < n; ++i) { cin >> s[i].a >> s[i].b, s[i].i = i; }
  sort(s, s + n);

  int ans = 0, ansi = -1;
  priority_queue<int, vector<int>, greater<int>> q;
  for (int i = 0; i < n; ++i) {
    q.push(s[i].b);
    while (q.size() > k) { q.pop(); }
    if (q.size() == k && q.top() - s[i].a > ans) { ans = q.top() - s[i].a, ansi = i; }
  }

  priority_queue<ii, vector<ii>, greater<ii>> p;
  for (int i = 0; i < n; ++i) {
    isAns[s[i].i] = 1;
    p.push({ s[i].b, s[i].i });
    while (p.size() > k) { isAns[p.top().nd] = 0, p.pop(); }
    if (i == ansi) { break; }
  }

  cout << ans << '\n';
  for (int i = 0, flag = 0; i < n; ++i)
    if (isAns[i]) {
      if (flag) { cout << ' '; }
      flag = 1;
      cout << i + 1;
    }
  cout << '\n';

  return 0;
}
