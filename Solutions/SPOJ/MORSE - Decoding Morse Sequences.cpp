#include <bits/stdc++.h>
using namespace std;

int len, n, cnt, memo[10010], trie[1000010][2], fim[1000010];
char s[10010], t[100];
map<char, string> morse;

void build () {
  int i, j;
  string s, C = "A .- B -... C -.-. D -.. E . F ..-. G --. H .... I .. J .--- K -.- L .-.. M -- N -. O --- P .--. Q --.- R .-. S ... T - U ..- V ...- W .-- X -..- Y -.-- Z --.. $$$$$";

  for (i = 0; C[i] != '$'; i = j + 1) {
    s.clear();
    for (j = i + 2; C[j] != ' '; ++j) { s.push_back(C[j]); }
    morse[C[i]] = s;
  }
}

int conta (int p) {
  if (p == len) { return 1; }
  assert(p < len);

  int &pd = memo[p];
  if (pd != -1) { return pd; }

  pd = 0;
  int r = 0;
  while (s[p]) {
    int t = trie[r][(s[p] == '.')];
    if (!t) { break; }
    if (fim[t] > 0) { pd += fim[t] * conta(p + 1); }
    r = t;
    ++p;
  }

  return pd;
}

int main() {
  build();

  int d;

  scanf("%d", &d);
  while (d--) {
    cnt = 1;
    memset(fim, 0, sizeof fim);
    memset(memo, -1, sizeof memo);
    memset(trie, 0, sizeof trie);

    string w;

    scanf(" %s%d", s, &n);
    len = strlen(s);
    for (int i = 0; i < n; ++i) {
      scanf(" %s", t);
      w.clear();
      for (int i = 0; t[i]; ++i) { w += morse[t[i]]; }

      int r = 0;
      for (int i = 0; i < (int)w.size(); ++i) {
        int &t = trie[r][(w[i] == '.')];
        if (!t) { t = cnt++; }
        r = t;
      }
      ++fim[r];
    }

    printf("%d\n", conta(0));
  }

  return 0;
}
