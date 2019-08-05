#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

#ifndef ONLINE_JUDGE
__attribute__((destructor)) static void destroy() { cerr << "\nTime elapsed: " << (double)clock() / CLOCKS_PER_SEC << "s.\n"; }

void db() { cerr << '\n'; }
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
#define maxn -1

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

bool s[2][110];
int n, memo[110];

bool canput(int fig, int p) {
  if (p + 1 >= n) { return 0; }
  if (fig == 0) { return s[0][p] && s[0][p + 1] && s[1][p]; }
  if (fig == 1) { return s[0][p] && s[0][p + 1] && s[1][p + 1]; }
  if (fig == 2) { return s[0][p + 1] && s[1][p] && s[1][p + 1]; }
  return s[0][p] && s[1][p] && s[1][p + 1];
}

int f(int i) {
  if (i + 1 >= n) { return 0; }

  int &pd = memo[i];
  if (pd != -1) { return pd; }

  pd = f(i + 1);
  for (int k = 0; k < 4; ++k) {
    if (canput(k, i)) {
      if ((k == 0 && canput(2, i + 1)) || (k == 3 && canput(1, i + 1))) {
        pd = max(pd, f(i + 3) + 2);
      } else {
        pd = max(pd, f(i + 2) + 1);
      }
    }
  }
  return pd;
}

int main() {
  freopen("in", "r", stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  memset(memo, -1, sizeof memo);
  string str[2];
  cin >> str[0] >> str[1];

  n = str[0].size();
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < n; ++j) {
      s[i][j] = (str[i][j] == '0');
    }
  }
  cout << f(0) << endl;

  return 0;
}
