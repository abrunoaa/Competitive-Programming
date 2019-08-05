#include <algorithm>
#include <iostream>
#include <utility>
#include <numeric>
#include <stack>
#include <queue>
#include <list>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <bitset>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <climits>
using namespace std;


int main() {

  freopen("input.txt", "r", stdin);
  freopen("out.txt", "w", stdout);

  int n, m, value;
  char c;

  cin >> n;

  while (n--) {

    cin >> m;

    vector<int> a;
    vector<int> v;

    while (m--) {
      scanf("%d%c ", &value, &c);
      if (c == 'A') { a.push_back(value); }
      else { v.push_back(value); }
    }

    if (a.size() == 0 || v.size() == 0) { printf("0\n"); }
    else {

      sort(a.begin(), a.end());
      sort(v.begin(), v.end());

      long long soma = 0;

      int i;
      for (i = 0; i < int(a.size()) && i < int(v.size()); ++i) {
        soma += a[ a.size() - 1 - i ];
        soma += v[ v.size() - 1 - i ];
        soma -= 2;
      }


      printf("%lld\n", soma);
    }
  }

  return 0;
}

