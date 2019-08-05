// g++ -std=c++11 -o "%e" "%f" -fsanitize=address -fno-omit-frame-pointer -DBALLOONFIELD -Wall -Wextra -Wfloat-equal -Wconversion -Winline -Wduplicated-cond -Wduplicated-branches -Wlogical-op -Wrestrict -Wnull-dereference

#include <bits/stdc++.h>
using namespace std;

#ifdef BALLOONFIELD
__attribute__((destructor))static void __destroy__() {cerr << "\nElapsed: " << (double)clock() / CLOCKS_PER_SEC << "s.\n";}

void debug() {}
template<class t, class... u> void debug(const t &x, const u &...y) {cerr << ' ' << x, debug(y...);}
# define debug(x...) cerr<<"\x1b[91m"<<__LINE__<<" ["#x"] =",debug(x),cerr<<"\x1b[0m\n"
# define sleep(x) this_thread::sleep_for(chrono::milliseconds(x))
#else
# define assert(x) void(0)
# define debug(...) void(0)
# define freopen(...) void(0)
# define sleep(x) void(0)
#endif

template<class T>inline int lb(vector<T> &v, const T &x) { return lower_bound(v.begin(), v.end(), x) - v.begin(); }
template<class T>inline int ub(vector<T> &v, const T &x) { return upper_bound(v.begin(), v.end(), x) - v.begin(); }
template<class T>inline int lb(T* v, int n, const T &x) { return lower_bound(v, v + n, x) - v; }
template<class T>inline int ub(T* v, int n, const T &x) { return upper_bound(v, v + n, x) - v; }

template<class A, class B>ostream &operator<<(ostream &f, const pair<A, B> &x) {return f << '(' << x.first << ", " << x.second << ')';}

#define DEF1(_class...) ostream&operator<<(ostream&f,const _class&x){int b=0;f<<'[';for(auto&y:x){if(b++)f<<", ";f<<y;}return f<<']';}
#define DEF2(get,pop,_class...) ostream&operator<<(ostream&f,_class x){int b=0;f<<'[';while(x.size()){if(b++)f<<", ";f<<x.get();x.pop();}return f<<']';}
template<class T> DEF1(vector<T>) template<class T, class C> DEF1(set<T, C>) template<class T, class C> DEF1(multiset<T, C>) template<class K, class T, class C> DEF1(map<K, T, C>) template<class K, class T, class C> DEF1(multimap<K, T, C>)
template<class T> DEF2(front, pop, queue<T>) template<class T> DEF2(top, pop, stack<T>) template<class T, class V, class C> DEF2(top, pop, priority_queue<T, V, C>)

#define null nullptr
#define st first
#define nd second
#define inf 0x3f3f3f3f
#define infl 0x3f3f3f3f3f3f3f3f
#define mod 1000000007
#define maxn 153

#define rand() uid(rng)
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count()); // ll = mt19937_64
uniform_int_distribution<int> uid(0, numeric_limits<int>::max());             // range for random

typedef long long ll;
typedef double lf;
typedef pair<int, int> ii;

bool vis[2 * maxn * maxn];
char mat[maxn][maxn];
int r, c, source, sink, p[2 * maxn * maxn];
map<int, int> g[2 * maxn * maxn];

int calc(int i, int j) {
  return (i - 1) * c + j;
}

void add(int u, int v, int c) {
  if (c) {
    g[2 * u][2 * v] = c;
    g[2 * v][2 * u] = 0;
    g[2 * u + 1][2 * v + 1] = 0;
    g[2 * v + 1][2 * u + 1] = c;
  }
}

bool bfs() {
  memset(vis, 0, sizeof(vis));
  vis[source] = 1;
  queue<int> q;
  q.push(source);
  while (!q.empty()) {
    int u = q.front();
    if (u == sink) { return 1; }
    q.pop();
    for (auto v : g[u]) {
      if (!vis[v.st] && v.nd > 0) {
        p[v.st] = u;
        vis[v.st] = 1;
        q.push(v.st);
      }
    }
  }
  return 0;
}

int maxFlow() {
  int mf = 0;
  while (bfs()) {
    int f = inf;
    for (int u = sink; u != source; u = p[u]) {
      f = min(f, g[p[u]][u]);
    }
    for (int u = sink; u != source; u = p[u]) {
      g[p[u]][u] -= f;
      g[u][p[u]] += f;
    }
    debug(f);
    mf += f;
  }
  return mf;
}

int main() {
  freopen("in", "r", stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  memset(mat, 'X', sizeof(mat));

  int t;
  cin >> t;
  while (t--) {
    for (auto &x : g) { x.clear(); }

    cin >> r >> c;

    source = 2 * 0;
    sink = 2 * (calc(r, c) + 1);

    for (int u = 0; u <= sink; u += 2) {
      g[u][u + 1] = inf;
      g[u + 1][u] = inf;
    }

    for (int i = 1; i <= r; ++i) {
      for (int j = 1; j <= c; ++j) {
        cin >> mat[i][j];
        if (mat[i][j] == 'X') { continue; }
        if (mat[i][j] == 'D') { add(calc(i, j), sink / 2, 4); }
        if (mat[i - 1][j] != 'X') { add(calc(i - 1, j), calc(i, j), 1); }
        if (mat[i][j - 1] != 'X') { add(calc(i, j - 1), calc(i, j), 1); }
        add(source / 2, calc(i, j), (i == 1) + (i == r) + (j == 1) + (j == c));
      }
    }

    cout << maxFlow() << '\n';
  }

  return 0;
}
