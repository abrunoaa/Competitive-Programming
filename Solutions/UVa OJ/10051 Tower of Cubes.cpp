// pd - coin change

#include <bits/stdc++.h>
using namespace std;

#define fst first
#define snd second

typedef pair<int, int> ii;

char faces[][10] = {"front", "back", "left", "right", "top", "bottom"};
int dp[510][110];
struct cubo { int face[6]; } cubos[510];
vector<ii> caminho;

int formaPilha (int pos, int t) {
  if (pos < 0) { return 0; }

  int &ref = dp[pos][t];                          // pd
  if (ref != -1) { return ref; }

  ref = formaPilha(pos - 1, t);                   // não inclui este cubo
  cubo &c = cubos[pos];

  for (int i = 0; i < 6; ++i)                     // tenta todas as faces
    if (t == c.face[i] || !t) {                   // checa como pode incluir
      ref = max(ref, formaPilha(pos - 1, c.face[i ^ 1]) + 1);
    }

  return ref;
}

void recupera (int pos, int t) {
  if (pos < 0) { return; }

  int &ref = dp[pos][t];                          // checa se pd não incluiu este cubo
  if (ref == formaPilha(pos - 1, t)) { return recupera(pos - 1, t); }

  cubo &c = cubos[pos];
  for (int i = 0; i < 6; ++i)
    if ((t == c.face[i] || !t) && ref == formaPilha(pos - 1, c.face[i ^ 1]) + 1) {
      // checa se faz parte do caminho
      caminho.push_back(ii(pos + 1, i ^ 1));      // faz parte do caminho
      return recupera(pos - 1, c.face[i ^ 1]);    // recupera o resta
    }
}

int main() {
  int i, j, n, cs = 0;

  while (scanf("%d", &n) == 1 && n) {
    if (cs) { puts(""); }
    printf("Case #%d\n", ++cs);

    for (i = 0; i < n; ++i)               // entrada dos cubos
      for (j = 0; j < 6; ++j) {
        scanf("%d", &cubos[i].face[j]);
      }

    memset(dp, -1, sizeof dp);            // reseta dp
    printf("%d\n", formaPilha(n - 1, 0)); // encontra maior torre e imprime o tamanho

    caminho.clear();                      // reseta caminho
    recupera(n - 1, 0);                   // recupera caminho

    for (i = caminho.size(); i--; ) {     // imprime caminho
      printf("%d %s\n", caminho[i].fst, faces[caminho[i].snd]);
    }
  }

  return 0;
}
