#include <bits/stdc++.h>
using namespace std;

uint toi (char* s, register uint b) {
  register uint n = 0, i;
  for (i = 0; s[i]; ++i) {
    n = n * b + s[i] - 48;
  }
  return n;
}

uint toi (char* s) { // hex
  register uint n = 0, i;
  for (i = 0; s[i]; ++i) {
    n = n * 16 + s[i] - (s[i] >= 'a' ? 87 : 48);
  }
  return n;
}

string tobin(uint n)
{ return n > 1 ? tobin(n >> 1) + (n & 1 ? "1" : "0") : (n & 1 ? "1" : "0"); }

int main() {
  register int n;
  int T, c = 0;
  char num[100], base[100];

  scanf("%d", &T);
  while (T--) {
    printf("Case %d:\n", ++c);
    scanf(" %[^ ] %[^\n]", num, base);

    if (!strcmp(base, "bin")) {
      n = toi(num, 2);
      printf("%d dec\n%x hex\n", n, n);
    } else if (!strcmp(base, "dec")) {
      n = toi(num, 10);
      printf("%x hex\n%s bin\n", n, tobin(n).data());
    } else { // hex
      n = toi(num);
      printf("%d dec\n%s bin\n", n, tobin(n).data());
    }

    puts("");
  }
  return 0;
}
