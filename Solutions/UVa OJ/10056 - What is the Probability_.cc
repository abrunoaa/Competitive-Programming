#include <bits/stdc++.h>
using namespace std;

#define eps 1e-6

int main(){
  cin.sync_with_stdio(0), cin.tie(0);
  cout << fixed << setprecision(4);

  int t;
  cin >> t;
  while(t--){
    int n, i;
    double p;
    cin >> n >> p >> i;

    double ans = 0.0;
    for(int k = 0; k < 1000; ++k){
      ans += p * pow(1.0 - p, k * n + i - 1);
    }
    cout << ans << '\n';
  }

  return 0;
}
