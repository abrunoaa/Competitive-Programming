#include <bits/stdc++.h>
using namespace std;

/** begin *********************************************************************/
const int maxn = 100003;

int n;        // number of nodes
int p[maxn];  // parents
int s[maxn];  // size of the most representative parent in the set

void build() {
  for (int i = 0; i < n; ++i) {
    p[i] = i;
    s[i] = 1;
  }
}

int find(int u) { return (u == p[u] ? u : p[u] = find(p[u])); }

void merge(int u, int v) {
  u = find(u);
  v = find(v);
  if (u != v) {
    p[u] = v;
    s[v] += s[u];
  }
}
/** end ***********************************************************************/

#define cerr if(0) cerr

void test(int m, int seed, bool check = true) {
  cout << "Test: m = " << m << ", n = " << n << ", seed = " << seed << '\n';

  vector<int> path(n);
  vector<set<int>> uf(n);
  for (int i = 0; i < n; ++i) {
    uf[i].insert(i);
    path[i] = i;
  }

  auto get = [&](int u) {
    for (; u != path[u]; u = path[u]);
    return u;
  };
  auto upd = [&](int a, int b) {
    a = get(a);
    b = get(b);
    if (a == b) return;
    if (uf[a].size() < uf[b].size()) swap(a, b);
    assert(!uf[a].count(b));
    for (auto v : uf[b]) uf[a].insert(v);
    path[b] = a;
    uf[b].clear();
  };

  srand(seed);
  build();
  for (int i = 0; i < m; ++i) {
    cerr << "operation " << i << '\n';
    int a = rand() % n;
    int b = rand() % n;
    merge(a, b);
    assert(find(a) == find(b));
    upd(a, b);
    assert((int)uf[get(a)].size() == s[find(a)]);
    assert((int)uf[get(b)].size() == s[find(b)]);

    if (check) {
      for (int u = 0; u < n; ++u) {
        assert((int)uf[get(u)].size() == s[find(u)]);
        for (int v : uf[get(u)]) {
          assert(find(v) == find(u));
        }
      }
    }
  }
}

int main() {
  for (int seed = 0; seed < 5000; ++seed) {
    n = 5;
    test(25, seed);
  }
  for (int m = 1; m < 500; ++m) {
    n = 10;
    test(m, 0);
  }
  for (n = 1; n <= 1000; ++n) {
    test(5 * n, 0, n <= 50);
  }
  for (int seed = 0; seed < 5; ++seed) {
    n = 100000;
    test(1000000, seed, false);
  }
  return 0;
}
