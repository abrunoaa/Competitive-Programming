#include <bits/stdc++.h>
using namespace std;

#ifdef BALLOONFIELD
__attribute__((destructor))static void __destroy__(){cerr<<"\nElapsed: "<<(double)clock()/CLOCKS_PER_SEC<<"s.\n";}

void debug(){}
template<class t,class... u> void debug(const t &x, const u &...y){cerr<<' '<<x, debug(y...);}
#define debug(x...) cerr<<"\x1b[91m"<<__LINE__<<" ["#x"] =",debug(x),cerr<<"\x1b[0m\n"
#define sleep(x) this_thread::sleep_for(chrono::milliseconds(x))
#else
#define assert(x) void(0)
#define debug(...) void(0)
#define freopen(...) void(0)
#define sleep(x) void(0)
#endif

template<class A,class B>ostream&operator<<(ostream&f,const pair<A,B>&x){return f<<'('<<x.first<<", "<<x.second<<')';}

#define DEF1(_class...) ostream&operator<<(ostream&f,const _class&x){int b=0;f<<'[';for(auto&y:x){if(b++)f<<", ";f<<y;}return f<<']';}
#define DEF2(get,_class...) ostream&operator<<(ostream&f,_class x){int b=0;f<<'[';while(x.size()){if(b++)f<<", ";f<<x.get();x.pop();}return f<<']';}
template<class T>DEF1(vector<T>) template<class T,class C>DEF1(set<T,C>) template<class T,class C>DEF1(multiset<T,C>) template<class K,class T,class C>DEF1(map<K,T,C>) template<class K,class T,class C>DEF1(multimap<K,T,C>)
template<class T>DEF2(front,queue<T>) template<class T>DEF2(top,stack<T>) template<class T,class V,class C>DEF2(top,priority_queue<T,V,C>)

#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define forr(i, l, r) for (int i = (int)(l); i < (int)(r); ++i)
#define fore(i, v) for (auto &i : v)

#define rand() uid(rng)
mt19937 rng(0);
uniform_int_distribution<int> uid(0, numeric_limits<int>::max());             // range

typedef long long ll;
typedef pair<ll,ll> ii;

const ll maxn = (ll)1e3 + 3;

ll c[maxn];
ll ans[maxn];
vector<ll> g[maxn];
vector<ii> h[maxn];

int main() {
  assert(freopen("in", "r", stdin));
  ios_base::sync_with_stdio(0);

  ll m, n, k;
  cin >> m >> n >> k;
  forn(i, n) {
    cin >> c[i];
  }

  forn(i, n) {
    if (c[i] % 2 == 0) {
      ans[0] = 2;
      while (c[i] % 2 == 0) {
        c[i] /= 2;
      }
    }
  }

  forn(i, k) {
    ll a, b, d;
    cin >> a >> b >> d, --a, --b;
    if (a == 0 && ans[0] != 0) continue;
    g[a].push_back(b);
    h[b].push_back(ii(a, d));
  }
  forn(i, n) {
    if (c[i] == 1) continue;
    if (h[i].size() != 1) continue;

    auto [v, d] = h[i][0];
    ans[v] = (ll)(pow(c[i], 1.0 / (double)d) + 0.5);
    fore(j, g[v]) {
      while (c[j] % ans[v] == 0) {
        c[j] /= ans[v];
      }
    }
  }

  ll p = 0;
  for (ll i = 3; ; i += 2) {
    while (p < m && ans[p] != 0) ++p;
    if (p >= m) break;

    if (p > 0 && i < ans[p - 1]) i = ans[p - 1];

    ll x = c[g[p][0]];
    fore(j, g[p]) {
      x = min(x, c[j]);
    }
    assert(x >= i);
    ll sq = (ll)(sqrt(x) + .5);
    for (; x % i && i <= sq; i += 2);
    if (i > sq) i = x;

    ans[p] = i;
    fore(d, g[p]) {
      while (c[d] % i == 0) {
        c[d] /= i;
      }
    }
  }

  forn(i, m) {
    cout << ans[i] << ' ';
  }
  cout << '\n';
  return 0;
}
