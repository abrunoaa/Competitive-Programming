#include <cstdio>
#include <queue>
#include <vector>
using namespace std;

const int inf = 1e9;

int main() {
  register int i, s, e, f, n, t, dis[2505], boom, day, b;
  vector < int > adj[2505];
  queue < int > q;

  scanf("%d", &e);
  for (i = -1; ++i < e; ) {
    scanf("%d", &n);
    while (n--) {
      scanf("%d", &f);
      adj[i].push_back(f);
    }
  }

  /*
  printf("------------------------------------------------\n");
  for (i = 0; i < e; i++)
  {
    printf("%d :", i);
    for (s = 0; s < (int)adj[i].size(); s++)
      printf(" %d", adj[i][s]);
    printf("\n");
  }
  printf("------------------------------------------------\n");
  //*/

  scanf("%d", &t);
  while (t--) {
    for (i = e; i--; dis[i] = inf);
    scanf("%d", &s);
    dis[s] = 0;
    q.push(s);
    while (!q.empty()) {
      s = q.front();
      q.pop();
      for (i = adj[s].size(); i--; )
        if (dis[adj[s][i]] == inf) {
          dis[adj[s][i]] = dis[s] + 1;
          q.push(adj[s][i]);
        }
    }
    /*
    printf(" >> ");
    for (i = 0; i < e; i++)
      printf("%3d", dis[i] == inf ? -1 : dis[i]);
    printf("\n");
    //*/
    for (boom = 0, day = inf, i = 0; ; ) {
      while ((!dis[i] || dis[i] == inf) && ++i < e);
      if (i == e) {
        break;
      }
      for (s = i, b = 1; ++s < e; )
        if (dis[i] == dis[s]) {
          b++, dis[s] = 0;
        }
      if (b > boom) {
        boom = b, day = dis[i];
      } else if (b == boom && dis[i] < day) {
        boom = b, day = dis[i];
      }
      dis[i] = 0;
      /*
      printf(" !! ");
      for (int i = 0; i < e; i++)
        printf("%3d", dis[i] == inf ? -1 : dis[i]);
      printf("\n");
      //*/
    }

    if (boom > 0) { printf("%d %d\n", boom, day); }
    else { printf("0\n"); }
  }

  return 0;
}
