// longest common subsequence

#include <bits/stdc++.h>
using namespace std;

/*
 * exemplo:
 * s1 = abcdgh -> a d h
 * s2 = aedfhr -> a d h
 * max = adh = length 3
 */

int main () {
  int i, j, n, m, mem[1010][1010];
  char s1[1010], s2[1010];

  // reseta (só precisa resetar uma vez)
  for (i = 0; i < 1010; ++i) {
    mem[0][i] = mem[i][0] = 0;
  }

  while (cin.getline(s1, 1010) && cin.getline(s2, 1010)) { // pode ter string vazia
    n = strlen(s1);
    m = strlen(s2);

    // Needleman-Wunsch’s algorithm
    for (i = 1; i <= n; ++i)
      for (j = 1; j <= m; ++j)
        if (s1[i - 1] == s2[j - 1]) {
          mem[i][j] = mem[i - 1][j - 1] + 1;  // match = +1
        } else {
          mem[i][j] = max(mem[i - 1][j], mem[i][j - 1]);  // insert/delete
        }

    printf("%d\n", mem[n][m]);                            // ans = mem[n][m]
  }

  return 0;
}
