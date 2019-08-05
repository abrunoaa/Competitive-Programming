#include <bits/stdc++.h>
using namespace std;

#define m 200000

typedef long long ll;

int n;
vector<ll> pr;
bitset<m> isp;

void sieve() {
  pr.reserve(n + 5);
  isp.set();
  isp[0] = isp[1] = 0;

  for (ll i = 2; (int)pr.size() < n + 2; ++i) {
    //~ cerr << " >> " << pr.size() << endl;
    if (isp[i]) {
      //~ cerr << i << endl;
      pr.push_back(i);
      for (ll j = i * i; j < m; j += i) { isp[j] = 0; }
    }
  }
}

int main() {
  cin >> n;
  sieve();
  cout << pr[n - 1] << '\n';

  return 0;
}
