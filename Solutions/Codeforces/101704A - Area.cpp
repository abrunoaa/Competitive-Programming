#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> ii;
vector<ii> P;

double A() {
  long double ans = 0.0;
  int x1, x2, y1, y2;
  for (int i = 0 ; i < (int)P.size() - 1; ++i) {
    x1 = P[i].first;
    x2 = P[i + 1].first;
    y1 = P[i].second;
    y2 = P[i + 1].second;
    ans += (x1 * y2  - x2 * y1);
  }
  return fabs(ans) / 2.0;
}

int main() {

  //~ freopen("ain","r",stdin);
  int n;
  ii aux;

  cin >> n;

  for (; n--;) {
    cin >> aux.first >> aux.second;
    P.push_back(aux);
  }

  P.push_back(P[0]);
  printf("%.5lf\n", A());

  return 0;
}
