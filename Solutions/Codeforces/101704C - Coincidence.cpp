#include <bits/stdc++.h>
using namespace std;
#define maxn 106

int dp[maxn][maxn];
string a, b;

int f(int i, int j) {
  if ( i >= (int)a.size() || j >= (int)b.size()) { return 0; }
  int &r  = dp[i][j];
  if (r != -1) { return r; }
  if (a[i] == b[j]) { r = 1 + f(i + 1, j + 1); }
  r = max(r, max(f(i + 1, j), f(i, j + 1)));
  return r;
}

vector<int> aa;
vector<int> bb;

void rec(int i, int j ) {
  if ( i >= (int)a.size() || j >= (int)b.size()) { return; }
  int &r = dp[i][j];

  if (a[i] == b[j]) {
    if (r == 1 + f(i + 1, j + 1)) {
      aa.push_back(i + 1);
      bb.push_back(j + 1);
      return rec(i + 1, j + 1);
    }
    if (r == f(i + 1, j)) { return rec(i + 1, j); }
    return rec(i, j + 1);
  } else {
    if (r == f(i + 1, j)) { return rec(i + 1, j); }
    return rec(i, j + 1);
  }
  return;
}

int main() {
  //~ freopen("in","r",stdin);

  getline(cin, a);
  getline(cin, b);

  memset(dp, -1, sizeof dp);
  cout << f(0, 0) << endl;

  rec(0, 0);
  sort(aa.begin(), aa.end());
  sort(bb.begin(), bb.end());
  for (int i = 0; i < (int)aa.size(); i++) {
    cout << aa[i] << ' ';
  }
  cout << endl;

  for (int i = 0; i < (int)bb.size(); i++) {
    cout << bb[i] << ' ';
  }
  cout << endl;
}
