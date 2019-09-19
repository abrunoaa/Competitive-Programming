#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

const int n = 70;
const int maxv = n * n * n * n + 3;

int cnt = 0;
int dis[maxv];

inline int get(vi v) {
  int r = 0;
  for (int x : v) r = r * n + x;
  return r;
}

bool reorder(vi &v, int i) {
  if (v[i] < 1 || v[i] > n) return 0;
  for (; i > 0 && v[i] < v[i - 1]; --i) swap(v[i], v[i - 1]);
  for (; i < 3 && v[i] > v[i + 1]; ++i) swap(v[i], v[i + 1]);
  if (i > 0 && v[i] == v[i - 1]) return 0;
  if (i < 3 && v[i] == v[i + 1]) return 0;
  return 1;
}

void neighbor(queue<vi> &q, const vi& a) {
  int u = get(a);
  for (int x : {-1, 1}) {
    for (int i = 0; i < 4; ++i) {
      vi b = a;
      b[i] += x;
      if (!reorder(b, i)) continue;
      int v = get(b);
      if (dis[v] == -1) {
        dis[v] = dis[u] + 1;
        q.push(move(b));
      }
    }
  }
}

void symmetrically(queue<vi> &q, const vi& a) {
  int u = get(a);
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      if (i != j) {
        vi b = a;
        b[i] += 2 * (a[j] - a[i]);
        if (!reorder(b, i)) continue;
        int v = get(b);
        if (dis[v] == -1) {
          dis[v] = dis[u] + 1;
          q.push(move(b));
        }
      }
    }
  }
}

void bfs() {
  vi s = {1, 2, 3, 4};
  int v = get(s);
  memset(dis, -1, sizeof(dis));
  dis[0] = -2;
  dis[v] = 0;
  queue<vi> q;
  q.push(s);
  while (!q.empty()) {
    vi b = q.front();
    q.pop();
    neighbor(q, b);
    symmetrically(q, b);
  }
}

int main() {
  assert(freopen("in", "r", stdin));
  cin.sync_with_stdio(0), cin.tie(0), cout.tie(0);
  bfs();
  int t;
  cin >> t;
  while (t--) {
    vi v(4);
    for (int &x : v) cin >> x;
    cout << dis[get(v)] << '\n';
  }
  return 0;
}
