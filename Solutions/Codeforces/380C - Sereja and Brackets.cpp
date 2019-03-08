#include <bits/stdc++.h>
using namespace std;

#define gcd __gcd
#define popcnt __builtin_popcount
#define ctz __builtin_ctz
#define clz __builtin_clz
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define eps 1e-9
#define zero(x) (abs(x) < eps)
#define inf 0x3f3f3f3f
#define infl 0x3f3f3f3f3f3f3f3f
#define mod 1000000007
#define maxn 1000010

typedef long long ll;
typedef long double lf;
typedef pair<int,int> ii;
typedef pair<ii,int> tri;
typedef pair<ii,ii> qua;
typedef vector<int> vi;
typedef vector<ii> vii;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> Set;
typedef tree<int,int,less<int>,rb_tree_tag,tree_order_statistics_node_update> Map;

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
#define NDEBUG
#define db(...) 42
#endif

#define L (2 * k)
#define R (L + 1)
#define M ((l + r) / 2)

struct no{
  int ans, maxop, maxcl, nop, ncl;
};

no merge(no x, no y){
  return no{ x.ans + y.ans + min(x.maxop, y.maxcl),
    max(x.maxop - y.ncl + y.nop, y.maxop),
    max(x.maxcl, y.maxcl - x.nop + x.ncl),
    x.nop + y.nop,
    x.ncl + y.ncl };
}

int n, m;
char s[maxn];
no st[4 * maxn];

no build(int k = 1, int l = 1, int r = n){
  if(l == r) return st[k] = no{ 0, s[l] == '(', s[l] == ')', s[l] == '(', s[l] == ')' };
  return st[k] = merge(build(L, l, M), build(R, M+1, r));
}

no qry(int i, int j, int k = 1, int l = 1, int r = n){
  if(j < l || r < i) return { 0,0,0,0,0 };
  if(i <= l && r <= j) return st[k];
  return merge(qry(i, j, L, l, M), qry(i, j, R, M+1, r));
}

int main(){
  cin.sync_with_stdio(0), cin.tie(0);

  cin >> (s + 1) >> m;
  n = strlen(s + 1);
  build();
  while(m--){
    int l, r;
    cin >> l >> r;
    cout << 2 * qry(l, r).ans << endl;
  }

  return 0;
}
