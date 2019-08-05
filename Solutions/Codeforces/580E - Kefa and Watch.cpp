#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

#ifndef ONLINE_JUDGE
__attribute__((destructor)) static void destroy()
{ cerr << "\nTime elapsed: " << (double)clock() / CLOCKS_PER_SEC << "s.\n"; }

void db() { cerr << endl; }

template<class t, class... u>
void db(t x, u... y)
{ cerr << ' ' << x, db(y...); }

#define db(x...) cerr << " >> [" #x "] =", db(x)
#else
#warning "JUDGE"
#define assert(x)
#define db(...)
#define freopen(...)
#endif

#define gcd __gcd
#define popcnt __builtin_popcountll
#define ctz __builtin_ctzll
#define clz __builtin_clzll
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define eps 1e-9
#define zero(x) (abs(x) < eps)
#define pi acos(-1.0l)
#define inf 0x3f3f3f3f
#define infl 0x3f3f3f3f3f3f3f3f
#define mod 1000000007
#define maxn 100010

#define y0 asdf1
#define y1 asdf2
#define yn asdf3
#define j1 asdf4
#define tm asdf5
#define lr asdf6

template<class t1, class t2, class t3>
struct triple {
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

typedef long long ll;
typedef unsigned long long ull;
typedef long double lf;
typedef pair<int, int> ii;
typedef triple<int, int, int> tri;
typedef vector<int> vi;
typedef vector<ii> vii;

template<class t>
using Set = tree<t, null_type, less<t>, rb_tree_tag, tree_order_statistics_node_update>;
template<class t, class u>
using Map = tree<t, u, less<t>, rb_tree_tag, tree_order_statistics_node_update>;

template<class t1, class t2> ostream &operator << (ostream &out, const pair<t1, t2> &x) { return out << '(' << x.st << ", " << x.nd << ')'; }
template<class t1, class t2, class t3> ostream &operator << (ostream &out, const triple<t1, t2, t3> &x) { return out << '(' << x.st << ", " << x.nd << ", " << x.rd << ')'; }

#define PRINT_DS bool flag = 0; out << '['; for(auto& x : ds){ if(flag) out << ", "; else flag = 1; out << x; } return out << ']'
template<class t> ostream &operator << (ostream &out, const vector<t> &ds) { PRINT_DS; }
template<class t> ostream &operator << (ostream &out, const set<t> &ds) { PRINT_DS; }
template<class t1, class t2> ostream &operator << (ostream &out, const map<t1, t2> &ds) { PRINT_DS; }

template<class t> void print_arr(const t* arr, int n) { cout << '['; for (int i = 0; i < n; ++i) { if (i) cout << ", "; cout << arr[i]; } cout << ']'; }

#define b1 11
#define mod1 1000000007
#define b2 13
#define mod2 1000000009
#define L (2 * k)
#define R (L + 1)
#define M ((l + r) / 2)

char s[maxn];
int n, m, lazy[4 * maxn], p1_cache[maxn], p2_cache[maxn];
ii st[4 * maxn];

void init() {
  memset(lazy, -1, sizeof lazy);
  p1_cache[0] = p2_cache[0] = 1;
  for (int i = 1; i < maxn; ++i) {
    p1_cache[i] = (ll)b1 * p1_cache[i - 1] % mod1;
    p2_cache[i] = (ll)b2 * p2_cache[i - 1] % mod2;
  }
}

int mpow(int b, int e, int m) {
  int x = 1;
  while (e) {
    if (e % 2) { x = (ll)x * b % m; }
    b = (ll)b * b % m;
    e /= 2;
  }
  return x;
}

ii merge(ii x, ii y, int ny) {
  if (x.st == -1) { return y; }
  if (y.st == -1 || ny == 0) { return x; }
  return ii(((ll)x.st * p1_cache[ny] + y.st) % mod1,
            ((ll)x.nd * p2_cache[ny] + y.nd) % mod2);
}

ii build(int k = 1, int l = 1, int r = n) {
  if (l == r) { return st[k] = ii(s[l], s[l]); }
  return st[k] = merge(build(L, l, M), build(R, M + 1, r), r - (M + 1) + 1);
}

void prop(int k, int child) {
  int &l = lazy[k];
  if (l != -1) {
    static int mp1 = mpow(b1 - 1, mod1 - 2, mod1);
    static int mp2 = mpow(b2 - 1, mod2 - 2, mod2);
    st[k] = ii((ll)l * (p1_cache[child] - 1 + mod1) % mod1 * mp1 % mod1,
               (ll)l * (p2_cache[child] - 1 + mod2) % mod2 * mp2 % mod2);
    if (child > 1) {
      lazy[L] = lazy[R] = l;
    }
    l = -1;
  }
}

ii upd(int i, int j, int x, int k = 1, int l = 1, int r = n) {
  if (i <= l && r <= j) {
    lazy[k] = x;
    prop(k, r - l + 1);
    return st[k];
  }
  prop(k, r - l + 1);
  if (r < i || j < l) { return st[k]; }
  return st[k] = merge(upd(i, j, x, L, l, M), upd(i, j, x, R, M + 1, r), r - (M + 1) + 1);
}

ii qry(int i, int j, int k = 1, int l = 1, int r = n) {
  if (r < i || j < l) { return ii(-1, -1); }
  prop(k, r - l + 1);
  if (i <= l && r <= j) { return st[k]; }
  return merge(qry(i, j, L, l, M), qry(i, j, R, M + 1, r), max(0, min(j, r) - (M + 1) + 1));
}

int main() {
  freopen("in", "r", stdin);
  cin.sync_with_stdio(0), cin.tie(0);
  init();

  int m1, m2;
  cin >> n >> m1 >> m2;
  for (int i = 1; i <= n; ++i) {
    cin >> s[i];
    s[i] -= '0';
  }

  build();
  m = m1 + m2;
  while (m--) {
    int t, l, r, x;
    cin >> t >> l >> r >> x;
    if (t == 1) {
      upd(l, r, x);
    } else {
      cout << (l == r || qry(l + x, r) == qry(l, r - x) ? "YES" : "NO") << endl;
    }
  }

  return 0;
}
