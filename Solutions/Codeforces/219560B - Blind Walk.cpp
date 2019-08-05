#include <bits/stdc++.h>
using namespace std;

bool vis[100][100] = {};
int X[] = {-1, 1, 0, 0};
int Y[] = {0, 0, -1, 1};
char resp[20];
char dir[][20] = {"NORTH", "SOUTH", "WEST", "EAST"};

inline bool check(int x, int y) { return !vis[x][y]; }

void go(int x, int y) {
  vis[x][y] = 1;
  for (int k = 0; k < 4; ++k) {
    if (check(x + X[k], y + Y[k])) {
      puts(dir[k]);
      fflush(stdout);
      scanf(" %s", resp);
      if (resp[0] == 'E') {
        go(x + X[k], y + Y[k]);
        //~ cerr << " >> " << k << ' ' << (k ^ 1) << endl;
        puts(dir[k ^ 1]);
        fflush(stdout);
        scanf(" %*s");
      }
    }
  }
}

int main() {
  go(50, 50);
  puts("DONE");
  fflush(stdout);
  return 0;
}
