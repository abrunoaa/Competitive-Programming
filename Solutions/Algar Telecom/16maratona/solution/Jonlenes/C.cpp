#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <set>

using namespace std;

int main() {
  freopen("in.txt", "r", stdin);
  //freopen("out.txt", "w", stdout);

  int n, l, m, i, j;
  vector<string> vc;
  string s;

  while (cin >> n >> l >> m && (n || l || m)) {
    while (m--) {
      cin >> s;
      scanf(" ");
      vc.push_back(s);
    }

    s = "";
    for (i = 0; i < n; ++i) { s += char(i + 65); }

    vector< set<char> > vetSet(vc[0].size());
    for (i = 0; i < int(vc[0].size()); ++i) {
      set<char> ms;
      for (j = 0; j < int(vc.size()); ++j) {
        ms.insert(vc[j][i]);
      }
      vetSet[i] = ms;
    }

    unsigned long long int soma = 1;
    for (i = 0; i < l; ++i) {
      soma *= vetSet[i % (vc[0].size())].size();
    }

    cout << soma << endl;
  }

  return 0;
}
