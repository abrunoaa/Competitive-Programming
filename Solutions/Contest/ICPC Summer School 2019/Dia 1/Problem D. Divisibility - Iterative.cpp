#include < bits / stdc++.h >
using namespace std;

#define st first
#define nd second
#define inf 0x3f3f3f3f

typedef pair<int, int> ii;

#define maxn 1000003

vector<ii> pd[maxn][2];

int p;
string l;

int main() {
  // freopen("in","r",stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  cin >> l >> p;
  for (int z = 0; z < 2; ++z) {
    pd[l.size()][z].resize(p);
    for (int r = 0; r < p; ++r) {
      pd[l.size()][z][r] = ii(-inf * (r != 0 || !z), -1);
    }
  }
  for (int i = l.size() - 1; i >= 0; --i) {
    for (int z = 0; z < 2; ++z) {
      pd[i][z].resize(p);
      for (int r = 0; r < p; ++r) {
        if (!z && l[i] == '0') {
          pd[i][z][r] = max(ii(1, 0), pd[i + 1][0][0]);
        } else {
          ii t = pd[i + 1][1][(r * 10 + l[i] - '0') % p];
          ++t.st;
          t.nd = l[i] - '0';
          pd[i][z][r] = max(t, pd[i + 1][z][r]);
        }
      }
    }
  }
  if (pd[0][0][0].st <= 0) {
    cout << "-1\n";
    return 0;
  }
  for (int i = 0, r = 0, z = 0; i < (int)l.size() && pd[i][z][r].st; ++i) {
    if (!z && l[i] == '0') {
      if (pd[i][0][0] != pd[i + 1][0][0]) {
        cout << '0';
        break;
      }
    } else if (pd[i][z][r] != pd[i + 1][z][r] || l[i] - '0' == pd[i + 1][z][r].nd) {
      cout << l[i];
      r = (r * 10 + l[i] - '0') % p;
      z = 1;
    }
  }
  cout << '\n';
  return 0;
}
