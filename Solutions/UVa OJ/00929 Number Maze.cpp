#include <bits/stdc++.h>
using namespace std;

typedef pair < int, int > ii;
typedef pair < int, ii > iii;
typedef vector < iii > viii;

#define inf (static_cast < int > (1e9))

int dx[] = { 0, 1, 0, -1};
int dy[] = { 1, 0, -1, 0};

int mat[1000][1000], dis[1000][1000];

uint n, m;

inline bool val(register uint i, register uint j)
{ return i < n && j < m; }

int proc () {
  register int i, x, y;
  iii fr;
  priority_queue < iii, viii, greater<iii> > pq;

  dis[0][0] = mat[0][0];
  pq.push(iii(mat[0][0], ii(0, 0)));
  while (!pq.empty()) {
    fr = pq.top();
    pq.pop();  // pega um p/ processar
    x = fr.second.first;
    y = fr.second.second;
    if (fr.first > dis[x][y]) {
      continue;  // não pode ter um menor
    }

    for (i = 0; i < 4; ++i) {
//printf(" >> %d %d %d\n", x+dx[i], x+dy[i], val(x+dx[i], y+dy[i]) ? 1 : 0);
      // checa se está na matriz e se é o menor
      if (val(x + dx[i], y + dy[i]) && dis[x][y] + mat[x + dx[i]][y + dy[i]] < dis[x + dx[i]][y + dy[i]]) {
// printf(" >> add %d %d\n", x+dx[i], y+dy[i]);
        dis[x + dx[i]][y + dy[i]] = dis[x][y] + mat[x + dx[i]][y + dy[i]]; // atualiza
        pq.push(iii(dis[x + dx[i]][y + dy[i]], ii(x + dx[i], y + dy[i]))); // adiciona
      }
    }
  }

  return dis[n - 1][m - 1];
}

int main() {
  //freopen("in", "r", stdin);

  register uint i, j;
  int T;

  scanf("%d", &T);
  while (T--) {
    scanf(" %d %d", &n, &m);
    for (i = 0; i < n; ++i)
      for (j = 0; j < m; ++j) {
        scanf(" %d", &mat[i][j]);
        dis[i][j] = inf;
      }
    printf("%u\n", proc());
    /*
        for (i = 0; i < n; ++i)
        {
          for (j = 0; j < m; ++j)
            printf("%2d ", mat[i][j]);
          printf("\n");
        }
        printf("\n");
        for (i = 0; i < n; ++i)
        {
          for (j = 0; j < m; ++j)
            printf("%2d ", dis[i][j] == inf ? -1 : dis[i][j]);
          printf("\n");
        }
        printf("\n");
    //*/
  }
  return 0;
}
