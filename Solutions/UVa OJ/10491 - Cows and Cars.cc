#include <bits/stdc++.h>
using namespace std;

typedef double lf;

int main(){
  cin.sync_with_stdio(0), cin.tie(0);
  cout << fixed << setprecision(5);

  int ncow, ncar, nshow;
  while(cin >> ncow >> ncar >> nshow){
    int n = ncow + ncar;
    cout << lf(ncow * ncar) / (n * (n - nshow - 1)) + lf(ncar * (ncar - 1)) / (n * (n - nshow - 1)) << '\n';
  }

  return 0;
}
