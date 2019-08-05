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

char mat[maxn][maxn];
bool vis[maxn][maxn];
int w, h;
const int X[] = {-1, 1, 0, 0}, Y[] = {0, 0, 1, -1};

inline bool valida(int x, int y) {
  return !(x < 0 || x >= h || y < 0 || y >= w);
}

void event(int x, int y) {
  if (mat[x][y] == 'X') { return; }
  vis[x][y] = 1;
  for (int i = 0; i < 4; ++i) {
    int a = x + X[i];
    int b = y + Y[i];
    if (!vis[a][b] && valida(a, b) && mat[a][b] != 'X') {
      if (mat[a][b] == 'D') {
        event(a, b);
      } else {
        ++mat[a][b];
      }
    }
  }
}

int main() {
  freopen("in", "r", stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  int n;
  cin >> n;
  while (n--) {
    cin >> w >> h;
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        cin >> mat[i][j];
      }
    }
    int q;
    cin >> q;
    while (q--) {
      int x, y;
      cin >> y >> x;
      if (mat[x][y] != 'X') {
        if (mat[x][y] == 'D') {
          memset(vis, 0, sizeof vis);
          event(x, y);
        } else {
          ++mat[x][y];
        }
      }
    }
    for (int i = 0; i < h; ++i) {
      for (int j = 0; j < w; ++j) {
        cout << mat[i][j];
      }
      cout << '\n';
    }
  }

  return 0;
}
