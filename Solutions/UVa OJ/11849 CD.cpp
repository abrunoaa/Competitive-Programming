#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m, ans, v;
  set<int> jack;
  set<int>::iterator it;

  while (scanf("%d%d", &n, &m) == 2 && (n || m)) {
    ans = 0;

    while (n--) {
      scanf("%d", &v), jack.insert(v);
    }
    while (m--) {
      scanf("%d", &v);
      it = jack.find(v);
      if (it != jack.end()) {
        ++ans, jack.erase(it);
      }
    }

    printf("%d\n", ans);

    jack.clear();
  }

  return 0;
}
