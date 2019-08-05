#include <bits/stdc++.h>
using namespace std;

#define maxn 100010
#define st first
#define nd second

typedef pair<int, int> ii;
typedef long long ll;

string a;

bool check(int i) {
  return a[i] + a[i + 1] - 2 * '0' == 9;
}

ll f(int i, int j) {
  if (i + 1 >= j) { return 1; }
  return f(i + 2, j) + 1;
}

int main() {
  // freopen("in","r",stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  while (cin >> a) {
    ll ans = 1;
    for (int i = 0; i < (int)a.size() - 1; ++i) {
      if (check(i)) {
        int j;
        for (j = i + 1; check(j); ++j);
        if (a[i] == a[j]) {
          ans *= f(0, j - i);
        }
        i = j;
      }
    }
    cout << ans << '\n';
  }

  return 0;
}
