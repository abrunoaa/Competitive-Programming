#include <bits/stdc++.h>
using namespace std;

int main() {
  int cs = 0;
  char str[20];
  string s;

  while (scanf(" %[^\n]", str), *str != '#') {
    s = str;
    printf("Case %d: ", ++cs);
    if (s == "HELLO") {
      puts("ENGLISH");
    } else if (s == "HOLA") {
      puts("SPANISH");
    } else if (s == "HALLO") {
      puts("GERMAN");
    } else if (s == "BONJOUR") {
      puts("FRENCH");
    } else if (s == "CIAO") {
      puts("ITALIAN");
    } else if (s == "ZDRAVSTVUJTE") {
      puts("RUSSIAN");
    } else {
      puts("UNKNOWN");
    }
  }

  return 0;
}





