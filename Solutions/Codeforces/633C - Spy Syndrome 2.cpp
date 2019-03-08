#include <bits/stdc++.h>
using namespace std;

#define sz(x) (int)x.size()

struct no
{
  int fim;
  map<char,no*> t;
  no () : fim(-1) {}
} trie;

bool memo[10010] = {};
int n, m;
string ans, text, dict[100010];

void add(int id, const string& s)
{
  no *r = &trie;
  for (int i = 0; i < sz(s); ++i)
  {
    char c = tolower(s[i]);
    if (!r->t[c]) r->t[c] = new no;
    r = r->t[c];
  }
  r->fim = id;
}

bool solve(int i)
{
  if (i == n) return 1;
  if (memo[i]++) return 0;

  no *r = &trie;
  while (1)
  {
    char c = text[i];
    if (!r->t.count(c)) return 0;
    ++i;
    r = r->t[c];
    if (r->fim != -1 && solve(i))
    {
      ans = dict[r->fim] + " " + ans;
      return 1;
    }
  }
}

int main()
{
  // freopen("in", "r", stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  string w;

  cin >> n >> text >> m;
  for (int i = 0; i < m; ++i)
  {
    cin >> dict[i];
    w = dict[i];
    reverse(w.begin(), w.end());
    add(i, w);
  }

  solve(0);
  cout << ans << '\n';

  return 0;
}
