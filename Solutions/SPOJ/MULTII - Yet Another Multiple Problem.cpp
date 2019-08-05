#include <bits/stdc++.h>
using namespace std;

#ifdef BALLOONFIELD
__attribute__((destructor))static void __destroy__() { cerr << "\nElapsed: " << (double)clock() / CLOCKS_PER_SEC << "s.\n"; }

void debug() {}
template<class t, class... u> void debug(const t &x, const u &...y) { cerr << ' ' << x, debug(y...); }
#define debug(x...) cerr<<"\x1b[91m[" #x "] =",debug(x),cerr<<"\x1b[0m\n"
#else
#define assert(x) void(0)
#define debug(...) void(0)
#define freopen(...) void(0)
#endif

#define null nullptr
#define st first
#define nd second
// #define mod 1000000007
#define maxn 10003
#define inf 0x3f3f3f3f

typedef long long ll;
typedef double lf;
typedef pair<int, int> ii;

int p[100000];
char digit[100000];
bool mod[maxn];

void rec(int i) {
  if (i) {
    rec(p[i]);
    cout << digit[i];
  }
}

int main() {
  freopen("in", "r", stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  int n, m, t = 0;
  while (cin >> n >> m) {
    cout << "Case " << ++t << ": ";

    bool forbidden[10] = {};
    for (int i = 0; i < m; ++i) {
      int d;
      cin >> d;
      forbidden[d] = 1;
    }

    vector<int> digits;
    for (int d = 0; d <= 9; ++d) {
      if (!forbidden[d]) {
        digits.push_back(d);
      }
    }

    memset(p, 0, sizeof p);
    memset(mod, 0, sizeof mod);
    bool flag = 0;
    queue<ii> q;
    q.push({0, 0});
    int cnt = 1;
    while (!q.empty()) {
      ii f = q.front();
      q.pop();
      int x = f.st;
      int k = f.nd;

      if (x == 0 && k > 0) {
        flag = 1;
        rec(k);
        cout << '\n';
        break;
      }

      for (int d : digits) {
        if (k == 0 && d == 0) {
          continue;
        }

        int y = (x * 10 + d) % n;
        if (mod[y]) {
          continue;
        }

        p[cnt] = k;
        digit[cnt] = char(d + '0');
        mod[y] = 1;
        q.push({y, cnt});
        ++cnt;
      }
      if (flag) {
        break;
      }
    }
    if (!flag) {
      cout << "-1\n";
    }
  }

  return 0;
}