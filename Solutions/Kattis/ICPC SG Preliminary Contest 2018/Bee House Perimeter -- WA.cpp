#include <bits/stdc++.h>
using namespace std;

int r;
vector<int> start;

int lenLine(int i) {
  if (i <= 0 || i >= 2 * r) return (int)1e9;
  if (i <= r) return r + i - 1;
  return 2 * r - i + 2;
}

void isNeig(vector<int>& v, int y, int i, int j) {
  bool is = 1;
  is = is && 1 <= i + j && i + j <= 2 * r - 1;
  is = is && start[i + j] <= y && y < start[i + j + 1];
  if (!is) return;
  v.push_back(y);
}

vector<int> neigbors(int x, int i) {
  vector<int> v;
  isNeig(v, x - 1, i, 0);
  isNeig(v, x + 1, i, 0);
  isNeig(v, x - lenLine(i - 1) + (i > r), i, -1);
  isNeig(v, x - lenLine(i - 1) + (i > r) - 1, i, -1);
  isNeig(v, x + lenLine(i) - (i >= r), i, +1);
  isNeig(v, x + lenLine(i) - (i >= r) + 1, i, +1);
  return v;
}

int main() {
  // assert(freopen("in", "r", stdin));
  cin.sync_with_stdio(0), cin.tie(0);
  int n;
  cin >> r >> n;
  start = {0, 1};
  for (int i = 2; i < 2 * r; ++i) {
    start.push_back(start.back() + lenLine(i - 1));
    // cerr << " ---- " << i << ' ' << start.back() << endl;
  }
  start.push_back((int)1e9);
  start.push_back((int)1e9);
  vector<int> a(n);
  for (int &x : a) {
    cin >> x;
  }
  sort(a.begin(), a.end());
  set<int> house;
  for (int i = 0, line = 1; i < n; ) {
    // cerr << "ok\n";
    while (start[line + 1] <= a[i]) {
      ++line;
    }
    int lo = a[i];
    while (i < n && start[line + 1] > a[i]) {
      ++i;
    }
    int hi = a[i - 1];
    // cerr << " ++ " << lo << ' ' << hi << endl;
    for (int k = lo; k <= hi; ++k) {
      house.insert(k);
    }
  }
  // for (int x : house) {
    // cerr << " ----- " << x << endl;
  // }
  int line = 1;
  int ans = 0;
  for (int x : house) {
    while (start[line + 1] <= x) {
      ++line;
    }
    ans += 6;
    for (int y : neigbors(x, line)) {
      // cerr << " ## " << line << " == " << x << ' ' << y << endl;
      if (house.count(y)) {
        --ans;
      }
    }
  }
  cout << ans << '\n';
  return 0;
}
