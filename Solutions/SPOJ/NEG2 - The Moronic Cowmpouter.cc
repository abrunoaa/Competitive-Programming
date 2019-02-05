#include <bits/stdc++.h>
using namespace std;

string toneg(int n, int b){
  if(n == 0)
    return "0";

  string m;
  while(n){
    int r = n % b;
    n /= b;

    if(r < 0){
      r += -b;
      ++n;
    }

    m.push_back(r + '0');
  }
  reverse(m.begin(), m.end());
  return m;
}

int main(){
  cin.sync_with_stdio(0), cin.tie(0);

  int n;
  while(cin >> n){
    cout << toneg(n, -2) << '\n';
  }
  return 0;
}
