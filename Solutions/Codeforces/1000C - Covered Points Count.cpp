#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

#ifndef ONLINE_JUDGE
__attribute__((destructor)) static void destroy() { cerr << "\nTime elapsed: " << (double)clock() / CLOCKS_PER_SEC << "s.\n"; }

void db(){ cerr << '\n'; }
template<class t, class... u> void db(t x, u... y){ cerr << ' ' << x, db(y...); }
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
#define maxn 200010

#define y0 asdf1
#define y1 asdf2
#define yn asdf3
#define j1 asdf4
#define tm asdf5
#define lr asdf6

template<class t1, class t2, class t3> struct triple{
  t1 st; t2 nd; t3 rd;

  triple() : st(), nd(), rd() {}
  triple(const t1& a, const t2& b, const t3& c) : st(a), nd(b), rd(c) {}

  bool operator == (const triple& t) const { return st == t.st && nd == t.nd && rd == t.rd; }
  bool operator != (const triple& t) const { return !(*this == t); }
  bool operator <  (const triple& t) const { return st != t.st ? st < t.st : nd != t.nd ? nd < t.nd : rd < t.rd; }
  bool operator <= (const triple& t) const { return !(t < *this); }
  bool operator >  (const triple& t) const { return t < *this; }
  bool operator >= (const triple& t) const { return !(*this < t); }
};

typedef long long ll;
typedef unsigned long long ull;
typedef long double lf;
typedef pair<int,int> ii;
typedef triple<int,int,int> tri;
typedef vector<int> vi;
typedef vector<ii> vii;

template<class t> using tset = tree<t,null_type,less<t>,rb_tree_tag,tree_order_statistics_node_update>;
template<class t,class u> using tmap = tree<t,u,less<t>,rb_tree_tag,tree_order_statistics_node_update>;
template<class t,class u = greater<t>> using pqueue = priority_queue<t,vector<t>,u>;

template<class t1, class t2> ostream& operator << (ostream& out, const pair<t1,t2>& x){ return out << '(' << x.st << ", " << x.nd << ')'; }
template<class t1, class t2, class t3> ostream& operator << (ostream& out, const triple<t1,t2,t3>& x){ return out << '(' << x.st << ", " << x.nd << ", " << x.rd << ')'; }

#define PRINT_DS bool flag = 0; out << '['; for(auto& x : ds){ if(flag) out << ", "; else flag = 1; out << x; } return out << ']'
template<class t> ostream& operator << (ostream& out, const vector<t>& ds){ PRINT_DS; }
template<class t> ostream& operator << (ostream& out, const set<t>& ds){ PRINT_DS; }
template<class t> ostream& operator << (ostream& out, const tset<t>& ds){ PRINT_DS; }
template<class t1, class t2> ostream& operator << (ostream& out, const map<t1,t2>& ds){ PRINT_DS; }
template<class t1, class t2> ostream& operator << (ostream& out, const tmap<t1,t2>& ds){ PRINT_DS; }

#define L (k * 2)
#define R (L + 1)
#define M ((l + r) / 2)

ll n, m, l[maxn], r[maxn], cnt[maxn], st[4 * 6 * maxn], lazy[4 * 6 * maxn], mp2[6 * maxn];

void prop(ll k, bool child){
  ll &l = lazy[k];
  if(l){
    st[k] += l;
    if(child){
      lazy[L] += l;
      lazy[R] += l;
    }
    l = 0;
  }
}

ll upd(ll i, ll j, ll k = 1, ll l = 0, ll r = m - 1){
  if(i <= l && r <= j){
    ++lazy[k];
    prop(k, l < r);
    return st[k];
  }
  prop(k, l < r);
  if(r < i || j < l) return st[k];
  return st[k] = upd(i, j, L, l, M) + upd(i, j, R, M+1, r);
}

ll qry(ll i, ll k = 1, ll l = 0, ll r = m - 1){
  if(r < i || i < l) return 0;
  prop(k, l < r);
  if(l == r) return st[k];
  return qry(i, L, l, M) + qry(i, R, M+1, r);
}

int main(){
  freopen("in","r",stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  map<ll,ll> mp;

  cin >> n;
  for(ll i = 0; i < n; ++i){
    cin >> l[i] >> r[i];
    mp[l[i] - 1];
    mp[l[i]];
    mp[l[i] + 1];
    mp[r[i] - 1];
    mp[r[i]];
    mp[r[i] + 1];
  }

  m = 0;
  for(auto &x : mp){
    x.nd = m++;
    mp2[x.nd] = x.st;
  }

  for(ll i = 0; i < n; ++i){
    upd(mp[l[i]], mp[r[i]]);
  }
  for(ll i = 0; i < m - 1; ++i){
    cnt[qry(i)] += mp2[i + 1] - mp2[i];
  }
  for(ll i = 1; i <= n; ++i){
    cout << cnt[i] << ' ';
  }
  cout << endl;

  return 0;
}
