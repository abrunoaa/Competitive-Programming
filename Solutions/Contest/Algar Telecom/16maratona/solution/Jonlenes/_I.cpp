#include <iostream>
#include <bitset>
#include <vector>
using namespace std;

inline int h(int x) {
  return (3 * x + 1) % 7;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("../input.txt", "r", stdin);
  freopen("../out.txt", "w", stdout);
#endif

  bitset<8> r;
  int v;
  char c;

  while (true) {
    vector<int> vet;
    while (scanf("%d%c", &v, &c) != EOF) {
      vet.push_back(v);
      if (c == '\n') { break; }
    }

    if (vet.size() == 0) { break; }

    r.reset();
    for (int i = 0; i < int(vet.size()); ++i) {
      int idx = bitset<8>( h(vet[i]) ).to_string().find_last_of("1");
      if (idx != int(string::npos)) { r.set( 7 - idx, 1); }
    }

    cout << r.to_string() << endl;
  }
  return 0;
}
