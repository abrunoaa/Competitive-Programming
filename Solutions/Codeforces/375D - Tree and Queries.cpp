#include <bits/stdc++.h>
using namespace std;

#define fst first
#define snd second
#define maxn 100010

typedef pair<int,int> ii;
typedef pair<ii,ii> qua;

int N, Q, c[maxn];
int bs, answer[maxn], current[maxn] = {}, f[maxn] = {};
int cnt = 0, tree[maxn], in[maxn], out[maxn];
qua queries[maxn];
vector<int> g[maxn];

void dfs(int u, int p)
{
  tree[cnt] = u;
  in[u] = cnt;
  for (int i = 0; i < (int)g[u].size(); ++i)
  {
    int v = g[u][i];
    if (v != p)
    {
      ++cnt;
      dfs(v, u);
    }
  }
  out[u] = cnt;
}

inline bool cmp(qua x, qua y)
{
  int bx = x.fst.fst / bs, by = y.fst.fst / bs;
  return bx != by ? bx < by : x.fst.snd < y.fst.snd;
}

inline void add(int k) { ++current[++f[c[tree[k]]]]; }
inline void rem(int k) { --current[f[c[tree[k]]]--]; }

void mo()
{
  bs = sqrt(N);
  sort(queries, queries + Q, cmp);

  for (int i = 0, mol = 0, mor = -1; i < Q; ++i)
  {
    qua &q = queries[i];

    int l = q.fst.fst;
    int r = q.fst.snd;
    int id = q.snd.fst;
    int k = q.snd.snd;

    while (mor < r) add(++mor);
    while (mor > r) rem(mor--);
    while (mol < l) rem(mol++);
    while (mol > l) add(--mol);

    answer[id] = current[k];
  }
}

int main()
{
  // freopen("gin", "r", stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  cin >> N >> Q;
  for (int i = 0; i < N; ++i) cin >> c[i];
  for (int i = 0; i < N - 1; ++i)
  {
    int a, b;
    cin >> a >> b, --a, --b;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  dfs(0, -1);

  for (int i = 0; i < Q; ++i)
  {
    int v, k;
    cin >> v >> k, --v;
    queries[i] = qua(ii(in[v], out[v]), ii(i, k));
  }

  mo();
  for (int i = 0; i < Q; ++i)
    cout << answer[i] << '\n';

  return 0;
}
