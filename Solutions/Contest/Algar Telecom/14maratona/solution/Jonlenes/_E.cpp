#include <iostream>
#include <vector>
#include <math.h>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

int main() {

  //freopen("../input.txt","r", stdin);
  //freopen("../out.txt","w", stdout);

  int n, q;
  int k, m;
  string s;
  int idx, c;

  while (cin >> n >> q && n && q) {

    cin >> s;

    while (q--) {
      cin >> k >> m;
      idx = 0;

      string temp = s;
      c = 0;
      while (m--) {
        temp[idx] = (temp[idx] == 'o' ? 'x' : 'o');
        idx = (idx + k) % n;
        c++;
        if (temp == s) { break; }
      }
      if (m > 0) {
        m %= c;

        while (m-- > 0) {
          temp[idx] = (temp[idx] == 'o' ? 'x' : 'o');
          idx = (idx + k) % n;
        }
      }

      cout << temp << endl;
    }
  }

  return 0;
}
