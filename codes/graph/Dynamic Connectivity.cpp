struct DsuOp {
  int v, rv, u, ru;
  DsuOp() {}
  DsuOp(int _v, int _rv, int _u, int _ru): v(_v), rv(_rv), u(_u), ru(_ru) {}
};

struct Dsu {
  vector<int> p, r;
  int comps;
  stack<DsuOp> op;

  Dsu() {}
  Dsu(int n): p(n), r(n) {
    for (int i = 0; i < n; ++i) {
      p[i] = i;
      r[i] = 0;
    }
    comps = n;
  }

  int find(int v) { return (v == p[v]) ? v : find(p[v]); }

  bool unite(int v, int u) {
    v = find(v);
    u = find(u);
    if (v == u) return false;
    --comps;
    if (r[v] > r[u]) swap(v, u);
    op.emplace(v, r[v], u, r[u]);
    p[v] = u;
    if (r[u] == r[v]) ++r[u];
    return true;
  }

  void rollback() {
    assert(!op.empty());
    DsuOp x = op.top();
    op.pop();
    ++comps;
    p[x.v] = x.v;
    r[x.v] = x.rv;
    p[x.u] = x.u;
    r[x.u] = x.ru;
  }
};

/* segtree */
#define L (2 * t)
#define R (L + 1)
#define M ((l + r) >> 1)

struct query {
  int v, u;
  bool united;
  query(int _v, int _u) : v(_v), u(_u) {}
};

struct QueryTree {
  int T;  // number of queries
  Dsu dsu;
  vector<vector<query>> tree;

  QueryTree() {}
  QueryTree(int _T, int n): T(_T), dsu(n), tree(4 * T + 4) {}

  void add(int t, int l, int r, int ul, int ur, query& q) {
    if (ul > ur) return;
    assert(t < (int)tree.size());
    if (l == ul && r == ur) {
      tree[t].push_back(q);
      return;
    }
    add(L, l, M, ul, min(ur, M), q);
    add(R, M + 1, r, max(ul, M + 1), ur, q);
  }

  void add(query q, int l, int r) {
    add(1, 0, T - 1, l, r, q);
  }

  void dfs(int t, int l, int r, vector<int>& ans) {
    for (query& q : tree[t]) q.united = dsu.unite(q.v, q.u);
    if (l == r) {
      ans[l] = dsu.comps;
    } else {
      dfs(L, l, M, ans);
      dfs(R, M + 1, r, ans);
    }
    for (query& q : tree[t]) if (q.united) dsu.rollback();
  }

  vector<int> solve() {
    vector<int> ans(T);
    dfs(1, 0, T - 1, ans);
    return ans;
  }
};
