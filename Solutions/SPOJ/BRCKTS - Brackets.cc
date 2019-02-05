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
#define pi acos(-1.0l)
#define inf 0x3f3f3f3f
#define infl 0x3f3f3f3f3f3f3f3f
#define mod 1000000007
#define maxn 30010

typedef long long ll;
typedef long double lf;
typedef pair<int,int> ii;
typedef pair<ii,int> tri;
typedef pair<ii,ii> qua;
typedef vector<int> vi;
typedef vector<ii> vii;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

template<class t>
using Set = tree<t,null_type,less<t>,rb_tree_tag,tree_order_statistics_node_update>;
template<class t,class u>
using Map = tree<t,u,less<t>,rb_tree_tag,tree_order_statistics_node_update>;

void db() { cerr << endl; }

template<class t, class... u>
void db(t x, u... y)
{ cerr << ' ' << x, db(y...); }

#if !defined ONLINE_JUDGE || defined LOCAL
__attribute__((destructor)) static void destroy()
{ cerr << "\nTime elapsed: " << (lf)clock() / CLOCKS_PER_SEC << "s.\n"; }

#define db(x...) cerr << " >> [" #x "] =", db(x)
#else
#warning "JUDGE"
#define NDEBUG
#define db(...) 42
#endif

template<class t> t sq(t x) { return x * x; }

#define L (2 * k)
#define R (L + 1)
#define M ((l + r) / 2)

int n;
char s[maxn];
ii st[4 * maxn];

ii merge(ii x, ii y){
  int p = min(x.st, y.nd);
  return ii(x.st - p + y.st, x.nd + y.nd - p);
}

ii build(int k = 1, int l = 1, int r = n){
  if(l == r) return st[k] = ii(s[l] == '(', s[l] == ')');
  return st[k] = merge(build(L, l, M), build(R, M+1, r));
}

ii upd(int i, int k = 1, int l = 1, int r = n){
  if(r < i || i < l) return st[k];
  if(l == r){
    s[l] = (s[l] + 1) % 2 + '(';
    return st[k] = ii(s[l] == '(', s[l] == ')');
  }
  return st[k] = merge(upd(i, L, l, M), upd(i, R, M+1, r));
}

int main(){
  // freopen("in","r",stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  s[0] = '*';
  int t = 0;
  while(cin >> n){
    int m;
    cin >> (s + 1) >> m;
    build();
    cout << "Test " << ++t << ":\n";
    while(m--){
      int k;
      cin >> k;
      if(k == 0){
        cout << (st[1].st == 0 && st[k].nd == 0 ? "YES" : "NO") << endl;
      }
      else{
        upd(k);
      }
    }
  }

  return 0;
}
