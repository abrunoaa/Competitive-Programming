#include <bits/stdc++.h>
using namespace std;

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

  bool operator <  (const triple &t) const { return st != t.st ? st < t.st : nd != t.nd ? nd < t.nd : rd < t.rd; }
  bool operator <= (const triple &t) const { return !(t < *this); }
  bool operator >  (const triple &t) const { return t < *this; }
  bool operator >= (const triple &t) const { return !(*this < t); }
};

typedef long long ll;
typedef unsigned long long ull;
typedef long double lf;
typedef pair<int, int> ii;
typedef pair<ll, ll> pll;
typedef triple<int, int, int> tri;
typedef vector<int> vi;
typedef vector<ii> vii;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

template<class t>
using Set = tree<t, null_type, less<t>, rb_tree_tag, tree_order_statistics_node_update>;
template<class t, class u>
using Map = tree<t, u, less<t>, rb_tree_tag, tree_order_statistics_node_update>;

void db() { cerr << endl; }

template<class t, class... u>
void db(t x, u... y)
{ cerr << ' ' << x, db(y...); }

#ifndef ONLINE_JUDGE
__attribute__((destructor)) static void destroy()
{ cerr << "\nTime elapsed: " << (lf)clock() / CLOCKS_PER_SEC << "s.\n"; }

#define db(x...) cerr << " >> [" #x "] =", db(x)
#else
#warning "JUDGE"
#define assert(x)
#define db(...)
#define freopen(...)
#endif

template<class t1, class t2> ostream &operator << (ostream &out, const pair<t1, t2> &x) { return out << '(' << x.st << ", " << x.nd << ')'; }
template<class t1, class t2, class t3> ostream &operator << (ostream &out, const triple<t1, t2, t3> &x) { return out << '(' << x.st << ", " << x.nd << ", " << x.rd << ')'; }

#define PRINT_DS bool flag = 0; out << '['; for(auto& x : ds){ if(flag) out << ", "; else flag = 1; out << x; } return out << ']'
template<class t> ostream &operator << (ostream &out, const vector<t> &ds) { PRINT_DS; }
template<class t> ostream &operator << (ostream &out, const set<t> &ds) { PRINT_DS; }
template<class t1, class t2> ostream &operator << (ostream &out, const map<t1, t2> &ds) { PRINT_DS; }

#define L (2 * k)
#define R (L + 1)
#define M ((l + r) / 2)

typedef pair<pll, pll> pp;

int n, m, h[2 * maxn];
ll d[2 * maxn];

struct segtree {
  ll op;
  pp st[4 * 2 * maxn];

  segtree(ll sign) : op(sign) {}

  pp merge(pp x, pp y) {
    pll v[] = { x.st, x.nd, y.st, y.nd };
    sort(v, v + 4, greater<pll>());
    return pp(v[0], v[1]);
  }

  pp build(int k = 1, int l = 1, int r = 2 * n) {
    if (l == r) { return st[k] = pp(pll(2 * h[l] + op * d[l - 1], l), pll(-infl, -infl)); }
    return st[k] = merge(build(L, l, M), build(R, M + 1, r));
  }

  pp qry(int i, int j, int k = 1, int l = 1, int r = 2 * n) {
    if (r < i || j < l) { return pp(pll(-infl, -infl), pll(-infl, -infl)); }
    if (i <= l && r <= j) { return st[k]; }
    return merge(qry(i, j, L, l, M), qry(i, j, R, M + 1, r));
  }
} s1(1), s2(-1);

int main() {
  freopen("in", "r", stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  cin >> n >> m;
  for (int i = 1; i <= n; ++i) {
    cin >> d[i];
    d[i + n] = d[i];
  }
  for (int i = 1; i <= 2 * n; ++i) {
    d[i] += d[i - 1];
  }
  for (int i = 1; i <= n; ++i) {
    cin >> h[i];
    h[i + n] = h[i];
  }

  s1.build();
  s2.build();
  while (m--) {
    int l, r;
    cin >> l >> r;
    int a = r + 1;
    int b = l - 1 + n * (l <= r);

    pp ans1 = s1.qry(a, b);
    pp ans2 = s2.qry(a, b);
    ll ans = ans1.st.st + ans2.st.st;
    // db(ans1.st.nd, ans2.st.nd);
    if (ans1.st.nd == ans2.st.nd) {
      // db(ans1, ans2);
      ans = max(ans1.st.st + ans2.nd.st, ans1.nd.st + ans2.st.st);
    }
    cout << ans << endl;
  }

  return 0;
}
