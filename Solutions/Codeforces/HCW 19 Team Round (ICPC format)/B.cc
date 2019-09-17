#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define maxn 200010
typedef pair<int, int> ii;
typedef vector<int> vi;

int n;          // nº de vértices (numerados de 1 a n)
int deg[maxn];  // grau do vértice
int lv[maxn];   // "profundidade" do vértice (distância até a folha mais distante)
vi g[maxn];
unordered_map<int,set<int>> forbidden;
bool ign[maxn];

// grafo deve ser uma árvore, pode ter um ou dois centros (depende do diâmetro)
ii center() {
  int c1 = -1, c2 = -1;                           // candidatos a ser centro
  queue<int> q;
  for (int u = 1; u <= n; ++u) {
    if (ign[u]) continue;
    deg[u] = (int)(g[u].size() - forbidden[u].size());               // não vale a pena calcular antes!
    if (deg[u] == 1) {
      // cerr << " -- " << u << endl;
      q.push(u);
      lv[u] = 1;
      if (c1 == -1) {
        c1 = u;
      } else {
        c2 = u;
      }
    }
  }
  if (c1 == -1) {
    for (int u = 1; u <= n; ++u) {
      if (!ign[u]) {
        return {u, -1};
      }
    }
  }

  int m = 0;                            // vértice mais "profundo"
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    // cerr << " $$ " << u << endl;
    for (int v : g[u]) {
      if (forbidden[u].count(v)) continue;
      // cerr << " §§ " << u << " -> " << v << endl;
      if (--deg[v] == 1) {
        q.push(v);
        lv[v] = lv[u] + 1;

        if (lv[v] > m) {
          m = lv[v];
          c1 = v;
          c2 = -1;
        } else if (lv[v] == m) {
          c2 = v;
        }
      }
    }
  }
  assert(c1 != -1);
  return ii(c1, c2);
}

void dfs(int u, int p) {
  // cerr << " >> " << u << endl;
  ign[u] = 1;
  for (int v : g[u]) {
    if (!forbidden[u].count(v) && v != p) {
      dfs(v, u);
    }
  }
}

int main() {
  // assert(freopen("bin", "r", stdin));
  scanf("%d", &n);
  // n = 200000;
  for (int i = 1; i < n; ++i) {
    int u, v;
    scanf("%d%d", &u, &v);
    // u = i;
    // v = i + 1;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  while (1) {
    ii c = center();
    cout << "? 2 " << c.st << endl;
    int ans;
    cin >> ans;
    if (ans == 0) {
      cout << "! " << c.st << endl;
      break;
    }
    forbidden[c.st].insert(ans);
    forbidden[ans].insert(c.st);
    // cerr << " ## " << c.st << endl;
    dfs(c.st, 0);
  }
  return 0;
}
