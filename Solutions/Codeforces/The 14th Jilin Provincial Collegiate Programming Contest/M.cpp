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

template<class T>inline int lb(const vector<T>&v,const T&x,int l=0,int r=-1){return(int)(lower_bound(v.begin()+l,(r==-1?v.end():v.begin()+r),x)-v.begin());}
template<class T>inline int ub(const vector<T>&v,const T&x,int l=0,int r=-1){return(int)(upper_bound(v.begin()+l,(r==-1?v.end():v.begin()+r),x)-v.begin());}
template<class T>inline int lb(const T*v,int n,const T&x,int l=0,int r=-1){return(int)(lower_bound(v+l,v+(r==-1?n:r),x)-v);}
template<class T>inline int ub(const T*v,int n,const T&x,int l=0,int r=-1){return(int)(upper_bound(v+l,v+(r==-1?n:r),x)-v);}

template<class A,class B>ostream&operator<<(ostream&f,const pair<A,B>&x){return f<<'('<<x.first<<", "<<x.second<<')';}

#define DEF1(_class...) ostream&operator<<(ostream&f,const _class&x){int b=0;f<<'[';for(auto&y:x){if(b++)f<<", ";f<<y;}return f<<']';}
#define DEF2(get,_class...) ostream&operator<<(ostream&f,_class x){int b=0;f<<'[';while(x.size()){if(b++)f<<", ";f<<x.get();x.pop();}return f<<']';}
template<class T>DEF1(vector<T>) template<class T,class C>DEF1(set<T,C>) template<class T,class C>DEF1(multiset<T,C>) template<class K,class T,class C>DEF1(map<K,T,C>) template<class K,class T,class C>DEF1(multimap<K,T,C>)
template<class T>DEF2(front,queue<T>) template<class T>DEF2(top,stack<T>) template<class T,class V,class C>DEF2(top,priority_queue<T,V,C>)

#define st first
#define nd second
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define forr(i, l, r) for (int i = (int)(l); i < (int)(r); ++i)
#define fore(i, v) for (auto &i : v)

#define rand() uid(rng)
// mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count()); // ll = mt19937_64
mt19937 rng(0); // ll = mt19937_64
uniform_int_distribution<int> uid(0, numeric_limits<int>::max());             // range

typedef long long ll;
typedef double lf;
typedef pair<int,int> ii;
typedef pair<int,ii> tri;

const int inf = 0x3f3f3f3f;
const ll infl = 0x3f3f3f3f3f3f3f3f;
const lf eps = 1e-9;
const int mod = 1000000007;
const int maxn = (int)5e5 + 3;

struct Qry {
  int l, r, i;

  bool operator<(const Qry& o) const {
    return r < o.r;
  }
};

int n, q;
int a[maxn];
int x[maxn];
int ft[maxn];
int ans[maxn];
vector<Qry> qry;
map<int, vector<int>> pos;

void add(int i, int x) {
  for (; i < maxn; i += i & -i) {
    ft[i] ^= x;
  }
}

int get(int i) {
  int r = 0;
  for (; i; i -= i & -i) {
    r ^= ft[i];
  }
  return r;
}

void brute() {
  for (auto [l, r, id] : qry) {
    map<int, int> mp;
    forr(i, l, r + 1) {
      ++mp[a[i]];
    }
    int exp = 0;
    for (auto [ai, k] : mp) {
      if (k % 2 == 0) {
        exp ^= ai;
      }
    }
    debug(id, l, r, ans[id], exp);
    assert(ans[id] == exp);
  }
}

int main() {
  assert(freopen("in", "r", stdin));
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  while (cin >> n >> q) {
  // while (1) {
    // n = 10;
    // q = (n + 1) * n / 2;
    pos.clear();
    qry.clear();
    memset(x, 0, sizeof(x));
    memset(ft, 0, sizeof(ft));
    memset(ans, 0, sizeof(ans));
    forr(i, 1, n + 1) {
      cin >> a[i];
      // a[i] = rand() % 10;
      pos[a[i]].push_back(i);
      x[i] = a[i] ^ x[i - 1];
    }
    for (auto [ai, p] : pos) {
      add(p.back(), ai);
    }
    assert(x[0] == 0);
    assert(get(0) == 0);
    forn(i, q) {
      int l, r;
      cin >> l >> r;
      qry.push_back({l, r, i});
    }
    // int idx = 0;
    // forr(i, 1, n + 1) forr(j, i, n + 1) qry.push_back({i, j, idx++});
    // assert((int)qry.size() == q);
    debug(vector(a + 1, a + n + 1));
    sort(qry.begin(), qry.end());
    int j = q - 1;
    for (int i = n; i >= 1 && j >= 0; --i) {
      for (; j >= 0 && qry[j].r == i; --j) {
        auto [l, r, id] = qry[j];
        assert(1 <= l && l <= r && r <= n);
        assert(0 <= id && id < q);
        debug(l, r, x[r], x[l - 1], get(r), get(l - 1));
        ans[id] = x[r] ^ x[l - 1];
        ans[id] ^= get(r) ^ get(l - 1);
        assert(l < r || ans[id] == 0);
      }
      debug(i, a[i], pos[a[i]]);
      auto &p = pos[a[i]];
      p.pop_back();
      if (!p.empty()) {
        add(p.back(), a[i]);
      }
    }
    assert(j < 0);
    forn(i, q) {
      cout << ans[i] << '\n';
    }
    // brute();
  }
  return 0;
}
