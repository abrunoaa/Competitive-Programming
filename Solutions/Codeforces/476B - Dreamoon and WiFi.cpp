#include <bits/stdc++.h>
using namespace std;

#define maxn 11

int nplus, nminus, unknown, memo[maxn][maxn][maxn];
string s1, s2;

int f(int i, int plus, int minus) {
  int &pd = memo[i][plus][minus];
  if (pd != -1) {
    return pd;
  }

  if (i == (int)s2.size()) {
    return pd = plus == nplus && minus == nminus;
  }
  if (s2[i] == '?') {
    return pd = f(i + 1, plus + 1, minus) + f(i + 1, plus, minus + 1);
  }
  if (s2[i] == '+') {
    return pd = f(i + 1, plus + 1, minus);
  }
  return pd = f(i + 1, plus, minus + 1);
}

int main() {
  memset(memo, -1, sizeof memo);

  cin >> s1 >> s2;
  for (char c : s1) {
    if (c == '+') {
      ++nplus;
    } else {
      ++nminus;
    }
  }
  for (char c : s2) {
    if (c == '?') {
      ++unknown;
    }
  }
  // cerr << " >> " << f(0,0,0) << ' ' << unknown << endl;
  cout << fixed << setprecision(20) << double(f(0, 0, 0)) / (1 << unknown) << '\n';

  return 0;
}
