#include <bits/stdc++.h>
using namespace std;

#define maxn 50010

typedef pair<int,int> ii;
typedef pair<int,ii> tri;

#define fst(x) x.first
#define snd(x) x.second.first
#define trd(x) x.second.second

struct cmp { bool operator () (const tri &x, const tri &y) { return fst(x) < fst(y); } };

int n, m;
int ones[maxn], answer[maxn];
tri queries[maxn];
list<int> sum[2 * maxn];
priority_queue<tri,vector<tri>,cmp> pq;

void mo()
{
  int bs = sqrt(n);
  sort(queries, queries + m,
    [bs](tri x, tri y)
    {
      int bx = fst(x) / bs, by = fst(y) / bs;
      return (bx != by ? bx < by : snd(x) < snd(y));
    });

  int mol = 1, mor = 0;
  sum[50000].push_back(0);
  for (int i = 0; i < m; ++i)
  {
    tri &q = queries[i];
    int l = fst(q);
    int r = snd(q);
    int id = trd(q);

    while (mor < r)
    {
      ++mor;
      int x = ones[mor];
      sum[x].push_back(mor);
      if (sum[x].size() > 1)
      {
        int pos = sum[x].front();
        pq.push(tri(mor - pos, ii(pos + 1, mor)));
      }
    }
    while (mor > r)
    {
      int x = ones[mor];
      sum[x].pop_back();
      if (sum[x].size() > 1)
      {
        int pos1 = sum[x].front();
        int pos2 = sum[x].back();
        pq.push(tri(pos2 - pos1, ii(pos1 + 1, pos2)));
      }
      --mor;
    }
    while (mol < l)
    {
      int x = ones[mol - 1];
      sum[x].pop_front();
      if (sum[x].size() > 1)
      {
        int pos1 = sum[x].front();
        int pos2 = sum[x].back();
        pq.push(tri(pos2 - pos1, ii(pos1 + 1, pos2)));
      }
      ++mol;
    }
    while (mol > l)
    {
      --mol;
      int x = ones[mol - 1];
      sum[x].push_front(mol - 1);
      if (sum[x].size() > 1)
      {
        int pos = sum[x].back();
        pq.push(tri(pos - mol + 1, ii(mol, pos)));
      }
    }
    while (!pq.empty())
    {
      tri t = pq.top();
      if (snd(t) >= mol && trd(t) <= mor) break;
      pq.pop();
    }

    answer[id] = pq.empty() ? 0 : fst(pq.top());
  }
}

int main()
{
  // freopen("ein", "r", stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  cin >> n >> m;
  ones[0] = 50000;
  for (int i = 1; i <= n; ++i)
    cin >> ones[i],
    ones[i] += ones[i - 1];

  for (int i = 0; i < m; ++i)
  {
    tri &q = queries[i];
    cin >> fst(q) >> snd(q);
    trd(q) = i;
  }

  mo();
  for (int i = 0; i < m; ++i) cout << answer[i] << '\n';

  return 0;
}
