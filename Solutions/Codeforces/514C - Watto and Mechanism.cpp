#include <bits/stdc++.h>
using namespace std;

#define maxn 600010

bool fim[maxn] = {};
char s[maxn];
int n, m;
int cnt = 0, trie[maxn][3] = {};

void insert () {
  int r = 0;
  for (int i = 0; s[i]; ++i) {
    int k = s[i] - 'a';
    int &t = trie[r][k];
    if (!t) { t = ++cnt; }
    r = t;
  }

  fim[r] = 1;
}

bool contains (int r = 0, int i = 0, int err = 0) {
  if (err > 1) { return 0; }
  if (!s[i]) { return err == 1 && fim[r]; }

  for (int c = 0; c < 3; ++c)
    if (trie[r][c] && contains(trie[r][c], i + 1, err + (s[i] - 'a' != c))) {
      return 1;
    }

  return 0;
}

int main() {
  cin.sync_with_stdio(0), cin.tie(0);

  cin >> n >> m;

  while (n--)
    cin >> s,
        insert();

  while (m--)
    cin >> s,
        cout << (contains() ? "YES" : "NO") << '\n';

  return 0;
}
