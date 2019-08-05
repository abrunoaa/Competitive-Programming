#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

#if !defined ONLINE_JUDGE || defined LOCAL
__attribute__((destructor)) static void __destroy__() { cerr << "\nTime elapsed: " << (double)clock() / CLOCKS_PER_SEC << "s.\n"; }

void debug() {}
template<class t, class... u> void debug(t x, u ...y) { cerr << ' ' << x, debug(y...); }
#define debug(x...) cerr << "\x1b[91m[" #x "] =", debug(x), cerr << "\x1b[0m\n"
#else
#define assert(x) void(0)
#define debug(...) void(0)
#define freopen(...) void(0)
#endif

#define gcd __gcd
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define zero(x) (abs(x) < eps)
#define pi acos(-1.0l)
#define inf 0x3f3f3f3f
#define infl 0x3f3f3f3f3f3f3f3f

#define popcnt __builtin_popcountll
#define ctz __builtin_ctzll
int clz(int x) { return __builtin_clz(x); }
int clz(long x) { return __builtin_clzl(x); }
int clz(long long x) { return __builtin_clzll(x); }

#define y0 asdf1
#define y1 asdf2
#define yn asdf3
#define j1 asdf4
#define tm asdf5
#define lr asdf6
#define div asdf7

template<class t1, class t2, class t3> struct triple {
  t1 st;
  t2 nd;
  t3 rd;

  triple() : st(), nd(), rd() {}
  triple(const t1 &a, const t2 &b, const t3 &c) : st(a), nd(b), rd(c) {}

  bool operator == (const triple &t) const { return st == t.st && nd == t.nd && rd == t.rd; }
  bool operator != (const triple &t) const { return !(*this == t); }
  bool operator <  (const triple &t) const { return st != t.st ? st < t.st : nd != t.nd ? nd < t.nd : rd < t.rd; }
  bool operator <= (const triple &t) const { return !(t < *this); }
  bool operator >  (const triple &t) const { return t < *this; }
  bool operator >= (const triple &t) const { return !(*this < t); }
};

template<class t> using tset = tree<t, null_type, less<t>, rb_tree_tag, tree_order_statistics_node_update>;
template<class t, class u> using tmap = tree<t, u, less<t>, rb_tree_tag, tree_order_statistics_node_update>;
template<class t, class u = greater<t>> using pqueue = priority_queue<t, vector<t>, u>;

template<class t1, class t2> ostream &operator << (ostream &out, const pair<t1, t2> &x) { return out << '(' << x.st << ", " << x.nd << ')'; }
template<class t1, class t2, class t3> ostream &operator << (ostream &out, const triple<t1, t2, t3> &x) { return out << '(' << x.st << ", " << x.nd << ", " << x.rd << ')'; }

#define PRINT_DS bool flag = 0; out << '['; for(auto& x : ds){ if(flag) out << ", "; else flag = 1; out << x; } return out << ']'
template<class t> ostream &operator << (ostream &out, const vector<t> &ds) { PRINT_DS; }
template<class t> ostream &operator << (ostream &out, const set<t> &ds) { PRINT_DS; }
template<class t> ostream &operator << (ostream &out, const tset<t> &ds) { PRINT_DS; }
template<class t1, class t2> ostream &operator << (ostream &out, const map<t1, t2> &ds) { PRINT_DS; }
template<class t1, class t2> ostream &operator << (ostream &out, const tmap<t1, t2> &ds) { PRINT_DS; }

typedef long long ll;
typedef unsigned long long ull;
typedef long double lf;
typedef pair<int, int> ii;
typedef triple<int, int, int> tri;
typedef vector<int> vi;
typedef vector<ii> vii;

#define eps 1e-9
#define mod 1000000007
#define maxn "abacate"

int pow(int b, int e, int m) {
  int x = 1;
  while (e) {
    if (e % 2) { x = (ll)x * b % m; }
    e /= 2;
    b = (ll)b * b % m;
  }
  return x;
}

int main() {
  freopen("in", "r", stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  int m;
  cin >> m;

  map<int, int> mp;
  for (int i = 0; i < m; ++i) {
    int x;
    cin >> x;
    ++mp[x];
  }

  vii p;
  p.reserve(mp.size());
  for (auto x : mp) {
    p.pb(ii(x.st, x.nd));
  }

  vi pref(p.size());
  pref[0] = 1;
  for (int i = 1; i < (int)p.size(); ++i) {
    pref[i] = (ll)pref[i - 1] * (p[i - 1].nd + 1) % (mod - 1);
  }

  vi suf(p.size());
  suf[(int)p.size() - 1] = 1;
  for (int i = p.size() - 2; i >= 0; --i) {
    suf[i] = (ll)suf[i + 1] * (p[i + 1].nd + 1) % (mod - 1);
  }

  int ans = 1;
  for (int i = 0; i < (int)p.size(); ++i) {
    int e = p[i].nd;
    int b = p[i].st;
    for (int k = 1; k <= e; ++k) {
      ans = (ll)ans * pow(b, (ll)k * pref[i] % (mod - 1) * suf[i] % (mod - 1), mod) % mod;
    }
  }
  cout << ans << endl;

  return 0;
}
