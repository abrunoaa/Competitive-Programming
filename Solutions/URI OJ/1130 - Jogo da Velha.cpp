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

#define maxn 10010

bool see[maxn];
int mex[maxn];

void halim() {
  for (int n = 1; n < maxn; ++n) {
    memset(see, 0, sizeof see);
    for (int i = 3; i < n - 1; ++i) { see[mex[i - 1] ^ mex[n - i]] = 1; }
    for (int &m = mex[n] = 0; see[m]; ++m);
  }
}

int main() {
  freopen("in", "r", stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  halim();
  int n;
  char s[maxn];
  while (cin >> n >> s && n) {
    s[n] = s[n + 1] = 0;
    int ans = 0;
    for (int i = 0; i < n; ++i) {
      if (s[i] == 'X' && (s[i + 1] == 'X' || s[i + 2] == 'X')) {
        ans = 1;
        break;
      }
    }
    if (!ans) {
      int p = -3; // o jogador pode por na borda
      for (int i = 0; i < n; ++i) {
        if (s[i] == 'X') {
          ans ^= mex[i - p - 1];
          p = i;
        }
      }
      ans ^= mex[n - p + 1];
    }
    cout << (ans ? 'S' : 'N') << '\n';
  }

  return 0;
}
