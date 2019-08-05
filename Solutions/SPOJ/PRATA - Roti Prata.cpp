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
#define maxn 100

typedef long long ll;
typedef long double lf;
typedef pair<int, int> ii;
typedef pair<ii, int> tri;
typedef pair<ii, ii> qua;
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

int r[maxn];

int main() {
  // freopen("in","r",stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  int t;
  cin >> t;
  while (t--) {
    int p, l;
    cin >> p >> l;
    for (int i = 0; i < l; ++i) {
      cin >> r[i];
    }

    int i = 0, j = 4 * p * (p + 1);
    while (i < j) {
      int t = (i + j) / 2;
      ll prod = 0;
      for (int k = 0; k < l; ++k) {
        prod += max(0, int((sqrt(lf(8 * t + r[k]) / r[k]) - 1.0 + eps) / 2.0));
      }
      if (prod >= p) {
        j = t;
      } else {
        i = t + 1;
      }
    }

    cout << i << endl;
  }

  return 0;
}
