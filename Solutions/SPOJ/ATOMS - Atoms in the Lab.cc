#include <bits/stdc++.h>
using namespace std;

#define eps 1e-9

int main(){
  ios::sync_with_stdio(0), cin.tie(0);

  int p;
  cin >> p;
  while(p--){
    long long n, m, k;
    cin >> n >> k >> m;
    cout << max(0ll, (long long)(log((double)m / n) / log(k) + eps)) << '\n';
  }

  return 0;
}
