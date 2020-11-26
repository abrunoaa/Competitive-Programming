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
#include <utility>

using namespace std;


int main() {

  //freopen("../input.txt","r", stdin);
  //freopen("../out.txt","w", stdout);

  int a, b, c;

  while (scanf("%d %d %d", &a, &b, &c) == 3) {
    long long r = (a * c * b) / (c - a);
    cout << r << " pagina";
    if (r > 1) { printf("s"); }
    printf("\n");
  }
}
