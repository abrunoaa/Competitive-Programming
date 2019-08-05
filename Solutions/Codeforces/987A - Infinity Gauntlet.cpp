#include <bits/stdc++.h>
using namespace std;

#define gcd __gcd
#define popcnt __builtin_popcount
#define st first
#define nd second
#define pb push_back
#define eps 1e-9
#define zero(x) (abs(x) < eps)
#define inf 0x3f3f3f3f
#define infl 0x3f3f3f3f3f3f3f3f
#define mod 1000000007
#define maxn 100010

typedef long long ll;
typedef long double lf;
typedef pair<int, int> ii;
typedef pair<ii, int> tri;
typedef vector<int> vi;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> Set;
typedef tree<int, int, less<int>, rb_tree_tag, tree_order_statistics_node_update> Map;

void db() { cerr << endl; }

template<class t, class... u>
void db(t x, u... y)
{ cerr << ' ' << x, db(y...); }

#ifdef LOCAL
__attribute__((destructor))
static void destroy() {
  cerr << "\nTime elapsed: " << (lf)clock() / CLOCKS_PER_SEC << "s.\n";
}

#define db(x...) cerr << " >> [" #x "] = ", db(x)
#else
#warning "JUDGE"
#define db(...) 42
#endif

string c[] = {"purple", "green", "blue", "orange", "red", "yellow"};
string gem[] = {"Power", "Time", "Space", "Soul", "Reality", "Mind"};

int main() {
  int n;
  cin >> n;
  map<string, int> appear;
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    appear[s] = 1;
  }
  cout << 6 - n << '\n';
  for (int i = 0; i < 6; ++i) {
    if (!appear[c[i]]) {
      cout << gem[i] << '\n';
    }
  }

  return 0;
}
