#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <vector>

using namespace std;

int main() {
  //freopen("in.txt", "r", stdin);
  //freopen("out.txt", "w", stdout);

  int n, p, d;
  string s;
  cin >> n;

  vector< pair<string, int> > vet;

  while (n--) {
    cin >> p;

    scanf(" ");
    vet.clear();

    while (p--) {
      cin >> s;
      scanf(" %d ", &d);
      vet.push_back(make_pair(s, d));
    }

    for (int i = 0; i < int(vet.size()) - 1; ++i) {
      if (vet[i].second > vet[i + 1].second) {
        swap(vet[i], vet[i + 1]);
      }
    }

    for (int i = 0; i < int(vet.size()); ++i) {
      cout << vet[i].first;
      if (i != int(vet.size() - 1)) { printf(" "); }
    }
    printf("\n");

  }

  return 0;
}


