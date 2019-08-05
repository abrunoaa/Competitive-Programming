//10:28
//10:29
//10:35
//11:00

#include <iostream>
using namespace std;


int main() {

  //freopen("../input.txt","r", stdin);
  //freopen("../out.txt","w", stdout);

  int n, v;

  while (cin >> n >> v && (n || v)) {

    long long r = 0;
    bool possivel = false;
    ++v;
    while (--v && !possivel) {
      r = 0;
      for (int i = v; i >= 1; --i) {
        for (int j = 0; j < i; ++j) {
          r += i;
          //cout << r << endl;
          if (r == n) {
            possivel = true;
            break;
          }
        }
        if (possivel) { break; }
      }
    }

    if (possivel) { cout << "possivel\n"; }
    else { cout << "impossivel\n"; }

  }

  return 0;
}

