#include <bits/stdc++.h>
using namespace std;

int N, T;
double P, Q;
double memo[2001][2001];

double f(int n, int t) {
  if (!n || !t) { return 0.0; }

  double &pd = memo[n][t];
  if (pd >= 0.0) { return pd; }

  // cerr << " >> " << n << ' ' << t << ' ' << p << endl;
  return pd = P * (1.0 + f(n - 1, t - 1)) + Q * f(n, t - 1);
}

int main() {
  // freopen("ain", "r", stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  while (cin >> N >> P >> T) {
    for (int i = 0; i <= N; ++i)
      for (int j = 0; j <= T; ++j) {
        memo[i][j] = -1.0;
      }

    Q = 1.0 - P;
    cout << fixed << setprecision(10) << f(N, T) << '\n';
  }

  return 0;
}
