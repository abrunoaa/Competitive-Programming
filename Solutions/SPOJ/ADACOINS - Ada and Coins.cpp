// g++ -std=c++11 -o "%e" "%f" -fsanitize=address -fno-omit-frame-pointer -DBALLOONFIELD -Wall -Wextra -Wfloat-equal -Wconversion -Winline -Wlogical-op

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

#define st first
#define nd second
#define inf 0x3f3f3f3f
#define infl 0x3f3f3f3f3f3f3f3f
#define mod 1000000007
#define maxn 100003

#define rand() uid(rng)
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count()); // ll = mt19937_64
uniform_int_distribution<int> uid(0, numeric_limits<int>::max());             // range for random

typedef long long ll;
typedef double lf;
typedef pair<int, int> ii;

bool can[maxn];
int ans[maxn];

int main() {
  assert(freopen("in", "r", stdin));
  ios_base::sync_with_stdio(0), cin.tie(0);
  int n, q;
  cin >> n >> q;
  can[0] = 1;
  for (int i = 0; i < n; ++i) {
    int c;
    cin >> c;
    for (int i = maxn - 1; i >= c; --i) {
      can[i] |= can[i - c];
    }
  }
  for (int i = 1; i < maxn; ++i) {
    ans[i] = ans[i - 1] + can[i];
  }
  for (int i = 0; i < q; ++i) {
    int b, e;
    cin >> b >> e;
    cout << ans[e] - ans[b - 1] << '\n';
  }
  return 0;
}
