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
#define maxn 200010

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

#define L (2 * k)
#define R (L + 1)
#define M ((l + r) / 2)

int n, m, p[maxn], l[maxn], lazy[4 * maxn];
ll ans[maxn], st[4 * maxn];
tri q[maxn];

void prop(int k, bool child) {
  int &l = lazy[k];
  if (l != -1) {
    st[k] = l;
    if (child) {
      lazy[L] = lazy[R] = l;
    }
    l = -1;
  }
}

ll build(int k = 1, int l = 1, int r = n) {
  if (l == r) { return st[k] = inf; }
  return st[k] = build(L, l, M) + build(R, M + 1, r);
}

ll upd(int i, int j, int x, int k = 1, int l = 1, int r = n) {
  if (i <= l && r <= j) {
    lazy[k] = x;
    prop(k, l < r);
    return st[k];
  }
  prop(k, l < r);
  if (r < i || j < l) { return st[k]; }
  return st[k] = upd(i, j, x, L, l, M) + upd(i, j, x, R, M + 1, r);
}

ll qry(int i, int j, int k = 1, int l = 1, int r = n) {
  if (r < i || j < l) { return 0; }
  prop(k, l < r);
  if (i <= l && r <= j) { return st[k]; }
  return qry(i, j, L, l, M) + qry(i, j, R, M + 1, r);
}

int main() {
  freopen("in", "r", stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  memset(lazy, -1, sizeof lazy);

  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> p[i] >> l[i];
  }
  p[n + 1] = inf;
  cin >> m;
  for (int i = 0; i < m; ++i) {
    cin >> q[i].st >> q[i].nd;
    q[i].rd = i;
  }
  sort(q, q + m, greater<tri>());

  build();
  for (int i = n - 1, j = 0; j < m; --i) {
    int up = p[i] + l[i];
    int r = lower_bound(p + i + 1, p + n + 1, up) - p;
    upd(i + 1, r - 1, 0);
    if (r <= n && qry(r, r) > p[r] - up) {
      upd(r, r, p[r] - up);
    }
    for (; q[j].st == i; ++j) {
      ans[q[j].rd] = qry(i + 1, q[j].nd);
    }
  }
  for (int i = 0; i < m; ++i) {
    cout << ans[i] << endl;
  }

  return 0;
}
