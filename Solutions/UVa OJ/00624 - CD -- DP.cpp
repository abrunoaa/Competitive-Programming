#include <bits/stdc++.h>
using namespace std;

#ifdef BALLOONFIELD
__attribute__((destructor))static void __destroy__() {cerr << "\nElapsed: " << (double)clock() / CLOCKS_PER_SEC << "s.\n";}

void debug() {}
template<class t, class... u> void debug(const t &x, const u &...y) {cerr << ' ' << x, debug(y...);}
# define debug(x...) cerr<<"\x1b[91m"<<__LINE__<<" ["#x"] =",debug(x),cerr<<"\x1b[0m\n"
# define sleep(x) this_thread::sleep_for(chrono::milliseconds(x))
#else
# define assert(x) void(0)
# define debug(...) void(0)
# define freopen(...) void(0)
# define sleep(x) void(0)
#endif

char memo[23][10000];
int n, t, cd[23];

bool f(int i, int s) {
  if (s == 0) { return 1; }
  if (i == t || s > n) { return 0; }

  auto &pd = memo[i][s];
  if (pd != -1) { return pd; }
  pd = f(i + 1, s) || f(i + 1, s - cd[i]);

  return pd;
}

void rec(int i, int s) {
  if (s == 0) { return; }
  if (cd[i] > s) { return rec(i + 1, s); }
  for (; !f(i + 1, s - cd[i]); ++i);
  cout << cd[i] << ' ';
  rec(i + 1, s - cd[i]);
}

int main() {
  freopen("in", "r", stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  while (cin >> n >> t) {
    for (int i = 0; i < t; ++i) { cin >> cd[i]; }
    memset(memo, -1, sizeof(memo));
    for (int s = n; ; --s) {
      if (f(0, s)) {
        rec(0, s);
        cout << "sum:" << s << '\n';
        break;
      }
    }
  }

  return 0;
}
