#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

#ifndef ONLINE_JUDGE
__attribute__((destructor)) static void destroy() { cerr << "\nTime elapsed: " << (double)clock() / CLOCKS_PER_SEC << "s.\n"; }

void db() { cerr << endl; }
template<class t, class... u> void db(t x, u... y) { cerr << ' ' << x, db(y...); }

#define db(x...) cerr << " >> [" #x "] =", db(x)
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
#define maxn 200010

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

template<class t> using Set = tree<t, null_type, less<t>, rb_tree_tag, tree_order_statistics_node_update>;
template<class t, class u> using Map = tree<t, u, less<t>, rb_tree_tag, tree_order_statistics_node_update>;

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

int n, m, l[maxn], r[maxn], st[3 * 4 * maxn], lazy[3 * 4 * maxn];

void prop(int k, bool child) {
  int &l = lazy[k];
  if (l) {
    st[k] += l;
    if (child) {
      lazy[L] += l;
      lazy[R] += l;
    }
    l = 0;
  }
}

int upd(int i, int j, int k = 1, int l = 1, int r = m) {
  if (i <= l && r <= j) {
    ++lazy[k];
    prop(k, l < r);
    return st[k];
  }
  prop(k, l < r);
  if (r < i || j < l) { return st[k]; }
  return st[k] = min(upd(i, j, L, l, M), upd(i, j, R, M + 1, r));
}

int qry(int i, int j, int k = 1, int l = 1, int r = m) {
  if (r < i || j < l) { return inf; }
  prop(k, l < r);
  if (i <= l && r <= j) { return st[k]; }
  return min(qry(i, j, L, l, M), qry(i, j, R, M + 1, r));
}

int main() {
  freopen("in", "r", stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  cin >> n;
  map<int, int> mp;
  for (int i = 0; i < n; ++i) {
    cin >> l[i] >> r[i];
    mp[l[i] - 1];
    mp[l[i]];
    mp[r[i]];
  }
  for (auto &x : mp) {
    x.nd = ++m;
  }
  for (int i = 0; i < n; ++i) {
    l[i] = mp[l[i]];
    r[i] = mp[r[i]];
    upd(l[i], r[i]);
  }
  for (int i = 0; i < n; ++i) {
    if (qry(l[i], r[i]) > 1) {
      cout << i + 1 << endl;
      return 0;
    }
  }
  cout << "-1\n";

  return 0;
}
