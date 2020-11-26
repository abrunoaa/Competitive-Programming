#include <bits/stdc++.h>
using namespace std;

int main() {
  //freopen("e","r",stdin);
  int n, q, k, m;
  while (scanf(" %d %d", &n, &q), n || q) {
    string str, aux;
    cin >> str;
    while (q--) {
      aux = str;
      scanf(" %d %d", &k, &m);
      int pos = 0;
      while (m--) {
        aux[pos] = (aux[pos] == 'x' ? 'o' : 'x');
        pos += k;
        if (pos > (int) str.size() - 1) { pos -= str.size(); }
      }
      cout << aux << "\n";
    }
  }
  return 0;
}
