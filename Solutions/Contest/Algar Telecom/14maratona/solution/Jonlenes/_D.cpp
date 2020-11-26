#include <iostream>
#include <vector>
#include <math.h>
#include <queue>
#include <utility>
#include <algorithm>
#include <limits>
#include <limits.h>

using namespace std;

const long long INF = INT_MAX;

int dx[] = {1, 0, -1,  0};
int dy[] = {0, 1,  0, -1};

vector < string > map;
vector < vector<bool> > matVisit;
vector < vector<long long> > matD;


void bfs(int x, int y) {

  queue< pair<int, int>  > q;

  q.push( make_pair(x, y) );
  matD[x][y] = 0;
  matVisit[x][y] = true;


  while (!q.empty()) {
    pair<int, int> u = q.front();
    q.pop();

    for (int i = 0; i < 4; ++i) {
      int xx = u.first + dx[i];
      int yy = u.second + dy[i];

      if (xx < 0 || yy < 0 || xx >= int(map.size()) || yy >= int(map[0].size()) || matVisit[xx][yy]) {
        continue;
      }

      if (map[xx][yy] != '#') {
        matVisit[xx][yy] = true;
        matD[xx][yy] = matD[u.first][u.second] + 1;
        q.push( make_pair(xx, yy) );
      }
    }
  }
}


int main() {

  //freopen("../input.txt","r", stdin);
  //freopen("../out.txt","w", stdout);

  string s;
  int n, m;

  while (scanf(" %d %d ", &n, &m) == 2 && m && n) {

    map.clear();

    matVisit.assign(n, vector<bool> (m, false));
    matD.assign(n, vector<long long> (m, INT_MAX));

    for (int i = 0; i < n; ++i) {
      cin >> s;
      map.push_back(s);
    }

    bool f = false;
    for (int i = 0; i < n; ++i) {
      for (int j = 0; j < m; ++j)
        if (map[i][j] != '#') {
          f = true;
          bfs(i, j);
          break;
        }
      if (f) { break; }
    }

    long long maxValue = 0;
    int x, y;
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j)
        if (matVisit[i][j] && matD[i][j] > maxValue) {
          x = i, y = j, maxValue = matD[i][j];
        }


    matVisit.assign(n, vector<bool> (m, false));
    matD.assign(n, vector<long long> (m, INT_MAX));

    bfs(x, y);

    for (int i = 0; i < n; ++i)
      for (int j = 0; j < m; ++j)
        if (matVisit[i][j]) {
          maxValue = max(maxValue, matD[i][j]);
        }

    cout << maxValue << endl;
  }

  return 0;
}
