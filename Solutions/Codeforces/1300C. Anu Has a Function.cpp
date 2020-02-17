#include <bits/stdc++.h>
using namespace std;

#ifdef BALLOONFIELD
__attribute__((destructor))static void __destroy__() {cerr << "Elapsed: " << (double)clock() / CLOCKS_PER_SEC << "s.\n";}

void debug() {}
template<class t, class... u> void debug(const t &x, const u &...y) {cerr << ' ' << x, debug(y...);}
# define debug(...) cerr<<"\x1b[91m"<<__LINE__<<" ["#__VA_ARGS__"] =",debug(__VA_ARGS__),cerr<<"\x1b[0m\n"
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

#define DEF1(...) ostream&operator<<(ostream&f,const __VA_ARGS__&x){int b=0;f<<'[';for(auto&y:x){if(b++)f<<", ";f<<y;}return f<<']';}
#define DEF2(get,pop,...) ostream&operator<<(ostream&f,__VA_ARGS__ x){int b=0;f<<'[';while(x.size()){if(b++)f<<", ";f<<x.get();x.pop();}return f<<']';}
template<class T> DEF1(vector<T>) template<class T, class C> DEF1(set<T, C>) template<class T, class C> DEF1(multiset<T, C>) template<class K, class T, class C> DEF1(map<K, T, C>) template<class K, class T, class C> DEF1(multimap<K, T, C>)
template<class T> DEF2(front, pop, queue<T>) template<class T> DEF2(top, pop, stack<T>) template<class T, class V, class C> DEF2(top, pop, priority_queue<T, V, C>)

#define st first
#define nd second

#define rand() uid(rng)
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count()); // ll = mt19937_64
uniform_int_distribution<int> uid(0, numeric_limits<int>::max());             // range for random

typedef long long ll;
typedef double lf;
typedef pair<int, int> ii;

const int inf = 0x3f3f3f3f;
const ll infl = 0x3f3f3f3f3f3f3f3f;
const int mod = 1000000007;
const int maxn = (int)1e5 + 3;

int a[maxn];
int x[maxn];
int y[maxn];

int main() {
  assert(freopen("in", "r", stdin));
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for (int i = 1; i < n; ++i) {
    x[i] = x[i - 1] | a[i - 1];
  }
  for (int i = n - 2; i >= 0; --i) {
    y[i] = y[i + 1] | a[i + 1];
  }
  int ans = 0;
  int best = 0;
  for (int i = 0; i < n; ++i) {
    int o = x[i] | y[i];
    int f = (a[i] | o) - o;
    if (f > best) {
      best = f;
      ans = i;
    }
  }
  debug(best, ans);
  cout << a[ans];
  for (int i = 0; i < n; ++i) {
    if (i != ans) {
      cout << ' ' << a[i];
    }
  }
  cout << '\n';
  return 0;
}
