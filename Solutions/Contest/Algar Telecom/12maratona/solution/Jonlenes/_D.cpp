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

long long total[101];
long long macho[101];


int main() {

  //freopen("../input.txt","r", stdin);
  //freopen("../out.txt","w", stdout);

  int n;
  long long lim = pow(2, 32);

  total[0] = 1;
  macho[0] = 0;
  for (int i = 1; i <= 100; ++i) {
    macho[i] = total[i - 1];
    total[i] = macho[i] + macho[i - 1] + 1;
  }


  while (cin >> n && n != -1) {
    cout << macho[n] % lim << " " << total[n] % lim << endl;
  }

  return 0;
}
