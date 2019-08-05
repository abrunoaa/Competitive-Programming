#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <algorithm>
#include <string>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main() {
  //freopen("in.txt", "r", stdin);
  //freopen("out.txt", "w", stdout);

  char c;
  string s;

  while (scanf("%c ", &c) != EOF && cin >> s && !(c == '0' && s[0] == '0' && s.size() == 1)) {
    scanf(" ");
    s.erase(remove(s.begin(), s.end(), c), s.end());
    int i;
    for (i = 0; i < int(s.size()); ++i)
      if (s[i] != '0') { break; }
    if (s.size() == 0 || i == int(s.size())) { printf("0"); }
    else {
      for (; i < int(s.size()); ++i) {
        cout << s[i];
      }
    }
    printf("\n");
  }

  return 0;
}
