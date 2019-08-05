#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second

typedef pair<int, int> ii;

const int maxn = 20003;

ii a[maxn];

int main() {
  // assert(freopen("in", "r", stdin));
  cin.sync_with_stdio(0), cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) {
      cin >> a[i].st >> a[i].nd;
    }
    sort(a, a + n);
    multiset<int> s;
    for (int i = 0, j; i < n; i = j) {
      for (j = i + 1; j < n && a[j].st == a[i].st; ++j);
      for (int k = i; k < j; ++k) {
        if (!s.empty() && a[k].nd > *s.begin()) {
          auto it = s.lower_bound(a[k].nd);
          --it;
          s.erase(it);
        }
      }
      for (int k = i; k < j; ++k) {
        s.insert(a[k].nd);
      }
    }
    cout << s.size() << '\n';
  }
  return 0;
}
