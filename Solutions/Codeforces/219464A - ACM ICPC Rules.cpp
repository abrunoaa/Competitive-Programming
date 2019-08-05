#include <bits/stdc++.h>
using namespace std;

vector<string> ans;

int main() {
  // freopen("ain", "r", stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  int n, msu = 0;
  map<string, int> mp;
  string in, tn;

  cin >> n;
  while (n--) {
    cin >> in;
    cin.ignore();
    getline(cin, tn);

    // cerr << " >> " << in << ' ' << tn << endl;

    if (in == "SCH") { continue; }
    if (in == "MSU") {
      if (msu < 4) {
        ans.push_back(in + " " + tn);
        ++msu;
      }
    } else {
      int &v = mp[in];
      if (v < 2) {
        ans.push_back(in + " " + tn);
        ++v;
      }
    }
    if (ans.size() == 10) { break; }
  }

  cout << ans.size() << '\n';
  for (int i = 0; i < (int)ans.size(); ++i) {
    cout << ans[i] << '\n';
  }

  return 0;
}
