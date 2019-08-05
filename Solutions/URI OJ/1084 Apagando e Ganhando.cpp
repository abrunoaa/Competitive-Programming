#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, d, need, i, val;
  vector < int > v;

  while (scanf("%d%d", &n, &d), n || d) {
    v.clear();
    need = n - d;                               // qtde necessária no final

    for (i = 0; i < n; ++i) {
      scanf("%1d", &val);                       // lê o próximo número
      while (!v.empty() && d && val > v.back()) { // guloso: remove os menores
        v.pop_back();
        --d;                                    // removeu +1
      }
      if ((int)v.size() < need) {               // se ainda não encheu
        v.push_back(val);  // add
      }
    }

    for (i = 0; i < need; ++i) {                // imprime
      printf("%d", v[i]);
    }
    puts("");
  }

  return 0;
}
