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

using namespace std;

int digits(int i) {
  return (int)((log(i) / log(10)) + 1);
}

int main() {

  //freopen("input.txt","r", stdin);
  //freopen("out.txt","w", stdout);

  int n, a, b;

  cin >> n;

  while (n--) {

    cin >> a >> b;

    bool tem = false;
    for (int i = a; i <= b; ++i) {
      int soma = 0;
      int len = digits(i);
      int v = i;
      for (int j = 0; j < len; ++j) {
        soma += pow(v % 10, len);
        v /= 10;
      }

      if (soma == i) {
        printf("%d ", i);
        tem = true;
      }
    }

    if (!tem) { printf("Nenhum\n"); }
    else { printf("\n"); }
  }

  return 0;
}
