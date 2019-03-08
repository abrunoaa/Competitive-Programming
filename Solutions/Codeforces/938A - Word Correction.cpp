#include <bits/stdc++.h>
using namespace std;

void db() { cerr << endl; }

template<class t, class... u>
void db(t x, u... y)
{ cerr << " " << x, db(y...); }

#define db(x...) cerr << " >>", db(x)
#define gcd __gcd
#define st first
#define nd second
#define pb push_back
#define eps 1e-9
#define zero(x) (fabs(x) < eps)
#define inf 0x3f3f3f3f
#define mod 1000000007
#define maxn 1000010

typedef long long ll;
typedef long double lf;
typedef pair<int,int> ii;
typedef pair<int,ii> tri;
typedef vector<int> vi;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> Set;
typedef tree<int, int, less<int>, rb_tree_tag, tree_order_statistics_node_update> Map;

#ifdef LOCAL
struct _S { _S() { assert(freopen("in","r",stdin)); } } _S;
#else
struct _S { _S() { cin.sync_with_stdio(0), cin.tie(0); } } _S;
#define db(x...)
#endif

bool ev(int c)
{
  return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y';
}

int main(){
  int n;
  string s;

  cin >> n >> s;
  for (int i = 0; i < (int)s.size(); ++i){
    // db(s[i - 1], s[i], ev(s[i-1]), ev(s[i]));
    if (i && ev(s[i]) && ev(s[i - 1])) continue;
    cout << s[i];
  }
  cout << '\n';

  return 0;
}

