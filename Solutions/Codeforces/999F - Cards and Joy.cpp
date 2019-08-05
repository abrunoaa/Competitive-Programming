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
#define maxn 100010

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

int n, k, h[20], memo[510][5010];

int get(int i, int nc) {
  if (i == 0 || nc == 0) { return 0; }

  int &pd = memo[i][nc];
  if (pd != -1) { return pd; }

  pd = 0;
  for (int k = 1, up = min(::k, nc); k <= up; ++k) {
    pd = max(pd, get(i - 1, nc - k) + h[k]);
  }
  return pd;
}

int main() {
  freopen("in", "r", stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  map<int, int> nc, nf;

  cin >> n >> k;
  for (int i = 0, c; i < n * k; ++i) {
    cin >> c;
    ++nc[c];
  }
  for (int i = 0, f; i < n; ++i) {
    cin >> f;
    ++nf[f];
  }
  for (int i = 1; i <= k; ++i) {
    cin >> h[i];
  }
  int ans = 0;
  for (auto x : nf) {
    int k = nc[x.st];
    for (int i = 0; i <= x.nd; ++i) {
      for (int j = 0; j <= k; ++j) {
        memo[i][j] = -1;
      }
    }
    db(x.st, x.nd, k, get(x.nd, k));
    ans += get(x.nd, k);
  }
  cout << ans << endl;

  return 0;
}

