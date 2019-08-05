#include <bits/stdc++.h>
using namespace std;

#define maxn 10010
#define fst first
#define snd second

typedef pair<int, int> ii;
typedef pair<int, ii> tri;

int N, nxt[maxn];
tri info[maxn];
int memo[maxn];

inline bool cmp (tri x, int v) { return x.fst < v; }

int f(int i) {
  if (i == N) { return 0; }

  int &pd = memo[i];
  if (pd != -1) { return pd; }

  int p = info[i].snd.snd;
  int k = nxt[i];

  if (k == i + 1) { return pd = p + f(k); }
  return pd = max(f(i + 1), p + f(k));
}

int main() {
  // freopen("iin", "r", stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  int T;

  cin >> T;
  while (T--) {
    cin >> N;
    for (int i = 0; i < N; ++i) {
      cin >> info[i].fst >> info[i].snd.fst >> info[i].snd.snd;
    }

    sort(info, info + N);
    for (int i = 0; i < N; ++i) {
      nxt[i] = lower_bound(info + i + 1, info + N, info[i].fst + info[i].snd.fst, cmp) - info;
    }

    memset(memo, -1, sizeof memo);
    cout << f(0) << '\n';
  }

  return 0;
}
