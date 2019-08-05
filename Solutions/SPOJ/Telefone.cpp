#include <cstdio>

int main() {
  char st[15];

  scanf(" %s", st);

  for (register int i = 0; i < 15 && st[i] != 0; i++) {
    if (st[i] >= 'A' && st[i] <= 'Z') {
      if (st[i] >= 'A' && st[i] <= 'C') {
        st[i] = '2';
        continue;
      }
      if (st[i] >= 'D' && st[i] <= 'F') {
        st[i] = '3';
        continue;
      }
      if (st[i] >= 'G' && st[i] <= 'I') {
        st[i] = '4';
        continue;
      }
      if (st[i] >= 'J' && st[i] <= 'L') {
        st[i] = '5';
        continue;
      }
      if (st[i] >= 'M' && st[i] <= 'O') {
        st[i] = '6';
        continue;
      }
      if (st[i] >= 'P' && st[i] <= 'S') {
        st[i] = '7';
        continue;
      }
      if (st[i] >= 'T' && st[i] <= 'V') {
        st[i] = '8';
        continue;
      }
      if (st[i] >= 'W' && st[i] <= 'Z') {
        st[i] = '9';
      }
    }
  }
  printf("%s", st);
}
