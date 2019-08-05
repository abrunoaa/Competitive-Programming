#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define all(x) x.begin(), x.end()

int m, s;
string mi, ma;
char memo[105][905];

bool minimum (int p, int rem) {
  if (p == m) { return !rem; }
  if (!rem) {
    if (minimum(p + 1, 0)) {
      mi.push_back('0');
      return 1;
    }
    return 0;
  }

  if (memo[p][rem]) { return 0; }
  memo[p][rem] = 1;

  for (int k = (p == 0); k < 10; ++k)
    if (minimum(p + 1, rem - k)) {
      mi.push_back(k + '0');
      return 1;
    }

  return 0;
}

bool maximum (int p, int rem) {
  if (p == m) { return !rem; }
  if (!rem) {
    if (maximum(p + 1, 0)) {
      ma.push_back('0');
      return 1;
    }
    return 0;
  }

  if (memo[p][rem]) { return 0; }
  memo[p][rem] = 1;

  if (p) {
    for (int k = 10; k--; )
      if (maximum(p + 1, rem - k)) {
        ma.push_back(k + '0');
        return 1;
      }
  } else
    for (int k = 10; --k; )
      if (maximum(p + 1, rem - k)) {
        ma.push_back(k + '0');
        return 1;
      }

  return 0;
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0);

  cin >> m >> s;
  if (!s) {
    if (m != 1) { goto failed; }
    cout << "0 0\n";
    return 0;
  }

  memset(memo, 0, sizeof memo);
  if (!minimum(0, s)) { goto failed; }

  memset(memo, 0, sizeof memo);
  if (!maximum(0, s)) { goto failed; }

  reverse(all(mi)), reverse(all(ma));

  cout << mi << ' ' << ma << endl;

  return 0;

failed:
  cout << "-1 -1\n";

  return 0;
}
