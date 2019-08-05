#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

#ifndef ONLINE_JUDGE
__attribute__((destructor)) static void destroy() { cerr << "\nTime elapsed: " << (double)clock() / CLOCKS_PER_SEC << "s.\n"; }

void db() { cerr << '\n'; }
template<class t, class... u> void db(t x, u... y) { cerr << ' ' << x, db(y...); }
#define db(x...) cerr << "\x1b[91m >> [" #x "] =", db(x), cerr << "\x1b[0m"
#else
#warning "JUDGE"
#define assert(x) 42
#define db(...) 42
#define freopen(...) 42
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
#define maxn 500010

#define y0 asdf1
#define y1 asdf2
#define yn asdf3
#define j1 asdf4
#define tm asdf5
#define lr asdf6

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

typedef long long ll;
typedef unsigned long long ull;
typedef long double lf;
typedef pair<int, int> ii;
typedef triple<int, int, int> tri;
typedef vector<int> vi;
typedef vector<ii> vii;

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

#define L (2 * k)
#define R (L + 1)
#define M ((l + r) / 2)

int n, m, a[maxn], last[maxn], ans[maxn];
ii st[4 * maxn];
tri q[maxn];

ii upd(int i, int x, int y, int k = 1, int l = 1, int r = n) {
  if (r < i || i < l) { return st[k]; }
  if (l == r) { return st[k] = ii(x, y); }
  return st[k] = min(upd(i, x, y, L, l, M), upd(i, x, y, R, M + 1, r));
}

ii qry(int i, int j, int k = 1, int l = 1, int r = n) {
  if (r < i || j < l) { return ii(inf, inf); }
  if (i <= l && r <= j) { return st[k]; }
  return min(qry(i, j, L, l, M), qry(i, j, R, M + 1, r));
}

int main() {
  freopen("in", "r", stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  memset(st, inf, sizeof st);

  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
  }
  cin >> m;
  for (int i = 0; i < m; ++i) {
    cin >> q[i].st >> q[i].nd;
    q[i].rd = i;
  }
  sort(q, q + m, [](const tri & x, const tri & y) {
    return x.nd < y.nd;
  });

  for (int r = 1, i = 0; r <= n; ++r) {
    if (last[a[r]]) {
      upd(last[a[r]], inf, inf);
    }
    upd(r, last[a[r]], a[r]);
    last[a[r]] = r;

    for (; r == q[i].nd; ++i) {
      int l = q[i].st;
      ii x = qry(l, r);
      ans[q[i].rd] = (x.st < l ? x.nd : 0);
    }
  }
  for (int i = 0; i < m; ++i) {
    cout << ans[i] << endl;
  }

  return 0;
}
