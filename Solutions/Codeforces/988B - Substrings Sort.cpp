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
#define maxn 100010

typedef long long ll;
typedef long double lf;
typedef pair<int, int> ii;
typedef pair<ii, int> tri;
typedef pair<ii, ii> qua;
typedef vector<int> vi;
typedef vector<ii> vii;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> Set;
typedef tree<int, int, less<int>, rb_tree_tag, tree_order_statistics_node_update> Map;

void db() { cerr << endl; }

template<class t, class... u>
void db(t x, u... y)
{ cerr << ' ' << x, db(y...); }

#ifdef LOCAL
__attribute__((destructor)) static void destroy()
{ cerr << "\nTime elapsed: " << (lf)clock() / CLOCKS_PER_SEC << "s.\n"; }

#define db(x...) cerr << " >> [" #x "] =", db(x)
#else
#warning "JUDGE"
#define NDEBUG
#define db(...) 42
#endif

int n;
string s[110];

bool cmp(const string &s, const string &t) {
  // db(&s, &t);
  return s.size() <= t.size() && t.find(s) != string::npos;
}

int main() {
  cin.sync_with_stdio(0), cin.tie(0);

  cin >> n;
  // n = 100;
  vector<string> s(n, "");
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
    // s[i] = "abacate";
  }

  for (int i = 0; i < n; ++i) {
    int m = i;
    for (int j = i + 1; j < n; ++j) {
      if (cmp(s[j], s[m])) {
        m = j;
      }
    }
    swap(s[i], s[m]);
  }
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if ((int)s[j].find(s[i]) == -1) {
        cout << "NO\n";
        return 0;
      }
    }
  }

  cout << "YES\n";
  for (int i = 0; i < n; ++i) {
    cout << s[i] << endl;
  }

  return 0;
}
