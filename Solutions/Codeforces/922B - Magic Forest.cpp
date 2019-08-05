#include <bits/stdc++.h>
using namespace std;

void db() { cerr << endl; }

template<class t, class... u>
void db(t x, u... y)
{ cerr << " " << x, db(y...); }

#define db(x...) cerr << " >>", db(x)
#define gcd(x,y) __gcd(x,y)
#define st first
#define nd second
#define eps 1e-9
#define zero(x) (fabs(x) < eps)
#define inf 0x3f3f3f3f
#define mod 1000000007
#define maxn 100010

typedef long long ll;
typedef long double lf;
typedef pair<int, int> ii;
typedef pair<int, ii> tri;
typedef vector<int> vi;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> Set;
typedef tree<int, int, less<int>, rb_tree_tag, tree_order_statistics_node_update> Map;

int main() {
  int n, ans = 0;
  cin >> n;

  for (int a = 1; a <= n; ++a)
    for (int b = a; b <= n; ++b) {
      int c = a ^ b;
      if (c >= b && c <= n && a + b > c) {
        // assert((a ^ b ^ c) == 0);
        // db(a, b, c);
        ++ans;
      }
    }

  cout << ans << '\n';

  return 0;
}
