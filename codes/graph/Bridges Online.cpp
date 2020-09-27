int bridges;
int dsu[maxn], dsu2[maxn];
int p[maxn];                  // the parent of the 2e tree
int sz[maxn];
int mit, vis[maxn];
vector<int> pu, pv;

void init(int n) {
  bridges = 0;
  mit = 0;
  for (int v = 0; v < n; ++v) {
    vis[v] = 0;
    sz[v] = 1;
    p[v] = -1;
    dsu[v] = dsu2[v] = v;
  }
}

int find2(int v) {            // only the leader of the 2e has correct values
  if (v == -1) return -1;
  return dsu2[v] == v ? v : dsu2[v] = find2(dsu2[v]);
}

int find(int v) {             // the leader of the cc
  v = find2(v);
  return dsu[v] == v ? v : dsu[v] = find(dsu[v]);
}

void makeRoot(int v) {        // revert pointers from root to v
  int child = -1, root = v = find2(v);
  while (v != -1) {
    int u = find2(p[v]);
    p[v] = child;
    dsu[v] = root;            // the root of the component now is v
    child = v;
    v = u;
  }
  sz[root] = sz[child];
}

void merge(int u, int v) {    // merge cycle u -> lca(u, v) -> v -> u into lca(u, v)
  ++mit;                      // avoid clearing vis every call
  pu.clear();
  pv.clear();

  // ------------ find lca(u, v) ------------
  int lca = -1;
  auto proc = [&lca](int &w, vector<int> &path) {
    if (w != -1) {
      w = find2(w);
      path.push_back(w);
      if (vis[w] == mit) lca = w;
      vis[w] = mit;
      w = p[w];
    }
  };
  while (lca == -1) { proc(u, pu); proc(v, pv); }

  // ------------ merge ------------
  for (auto &path : {pu, pv}) for (int w : path) {
    dsu2[w] = lca;
    if (w == lca) break;
    --bridges;
  }
}

void add(int u, int v) {      // add edge (u, v)
  u = find2(u);
  v = find2(v);
  if (u == v) return;         // already in the same 2e component

  int x = find(u);
  int y = find(v);
  if (x == y) {               // creates a new cycle
    merge(u, v);
  } else {                    // two distinct trees
    ++bridges;
    if (sz[x] > sz[y]) { swap(u, v); swap(x, y); }
    makeRoot(u);
    p[u] = dsu[u] = v;
    sz[y] += sz[u];
  }
}
