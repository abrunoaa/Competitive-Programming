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
#define maxn 103

#define rand() uid(rng)
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count()); // ll = mt19937_64
uniform_int_distribution<int> uid(0, numeric_limits<int>::max());             // range for random

typedef long long ll;
typedef double lf;
typedef pair<int, int> ii;

bool y[maxn];
int n, r, a[maxn], dis[maxn];
vector<ii> g[maxn];

void dijkstra(int s) {
  memset(dis, inf, sizeof(dis));
  dis[s] = 0;
  priority_queue<ii, vector<ii>, greater<ii>> pq;
  pq.push(ii(0, s));
  while (!pq.empty()) {
    int u = pq.top().nd;
    int d = pq.top().st;
    pq.pop();
    if (d > dis[u]) { continue; }
    for (ii v : g[u]) {
      if (d + v.nd < dis[v.st]) {
        dis[v.st] = d + v.nd;
        pq.push(ii(dis[v.st], v.st));
      }
    }
  }
}

int main() {
  freopen("in", "r", stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    cin >> n >> r;
    map<string, int> mp;
    for (auto &x : g) { x.clear(); }
    for (int i = 0; i < n; ++i) {
      string s, t;
      cin >> s >> a[i] >> t;
      mp[s] = i;
      y[i] = t[0] == 'y';
    }
    while (r--) {
      string s, t;
      int c;
      cin >> s >> t >> c;
      int u = mp[s];
      int v = mp[t];
      g[u].push_back(ii(v, c));
      g[v].push_back(ii(u, c));
    }
    dijkstra(0);
    int ans = inf;
    for (int i = 0; i < n; ++i) {
      if (y[i] && dis[i] <= a[0]) {
        ans = min(ans, dis[i]);
      }
    }
    if (ans == inf) {
      for (int i = 1; i < n; ++i) {
        if (a[i] && dis[i] <= a[0]) {
          int prev = dis[i];
          int ammo = a[i] + a[0] - dis[i];
          dijkstra(i);
          for (int j = 0; j < n; ++j) {
            if (y[j] && dis[j] <= ammo) {
              ans = min(ans, prev + dis[j]);
            }
          }
          break;
        }
      }
    }
    if (ans == inf) {
      cout << "No safe path\n";
    } else {
      cout << ans << '\n';
    }
  }

  return 0;
}
