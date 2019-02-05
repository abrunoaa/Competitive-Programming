#include <bits/stdc++.h>
using namespace std;

int Z(int n){
  int z = 0;
  for(long long k = 5; k <= n; k *= 5){
    z += n / k;
  }
  return z;
}

int main(){
  cin.sync_with_stdio(0), cin.tie(0);

  int t;
  cin >> t;
  while(t--){
    int n;
    cin >> n;
    cout << Z(n) << '\n';
  }

  return 0;
}
