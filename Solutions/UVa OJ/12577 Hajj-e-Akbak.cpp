#include <bits/stdc++.h>
using namespace std;

int main() {
  int cs = 0;
  char str[20];
  string s;

  while (scanf(" %s", str), *str != '*') {
    s = str;
    printf("Case %d: Hajj-e-", ++cs);
    if (s == "Hajj") {
      puts("Akbar");
    } else {
      puts("Asghar");
    }
  }

  return 0;
}





