#include <iostream>
#include <string>
#include <vector>
#include <cassert>
using namespace std;

#define inf 0x3f3f3f3f

string s;
vector<int> f[26];

int main() {
  // freopen("in","r",stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  int n;
  cin >> n >> s;
  for (int i = 0; i < n; ++i) { f[s[i] - 'a'].push_back(i); }
  for (auto &x : f) { x.push_back(inf); }

  int ans = 0;
  for (auto &a : f) if (a[0] < inf)
      for (auto &b : f) if (b[0] < inf) {
          int sum = 0;
          bool hasa = 0, hasb = 0, flag = 0;
          for (int i = 0, j = 0; a[i] != inf || b[j] != inf; a[i] < b[j] ? ++i : ++j) {
            if (a[i] < b[j]) {
              sum += 1;
              hasa = 1;
            } else {
              sum -= 1;
              hasb = 1;
              flag = 0;
            }
            if (sum < 0) {
              sum = 0;
              flag = 1;
            }
            if (hasa && hasb) {
              ans = max(ans, sum - flag);
            }
          }
        }
  cout << ans << '\n';

  return 0;
}
