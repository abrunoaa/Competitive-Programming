#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;
typedef pair<int, double> id;
typedef pair<double, int> di;

const long long INF = INT_MAX;
const double EPS = 1e-10;

bool inCircle(ii p, ii c, int r, double &d) {
  double dx = p.first - c.first;
  double dy = p.second - c.second;
  double Euc = dx * dx + dy * dy;
  double rSq = r * r;

  d = sqrt(Euc);

  return (Euc <= rSq + EPS);
}

vector< vector<double> > adjMat;

void floydWarshall(int V) {
  // precondition: AdjMat[i][j] contains the weight of edge (i, j)
  // or INF (1B) if there is no such edge
  // AdjMat is a 32-bit signed integer array
  for (int k = 0; k < V; k++) // remember that loop order is k->i-
    for (int i = 0; i < V; i++)
      for (int j = 0; j < V; j++) {
        adjMat[i][j] = min(adjMat[i][j], adjMat[i][k] + adjMat[k][j]);
      }
}


int main() {

  //freopen("../input.txt","r", stdin);
  //freopen("../out.txt","w", stdout);

  int n, c, a1, a2, i, j;
  long long r;
  double d;
  vector< ii > ptos;
  vector<int> raios;

  while (cin >> n && n) {

    ptos.assign(n, ii());
    raios.assign(n, 0);
    adjMat.assign(n, vector< double > (n, INF));

    for (i = 0; i < n; ++i) {
      cin >> ptos[i].first >> ptos[i].second >> raios[i];
    }


    for (i = 0; i < n; ++i)
      for (j = 0; j < n; ++j)
        if (i != j && inCircle(ptos[j], ptos[i], raios[i], d)) {
          adjMat[i][j] = d;
        }

    floydWarshall(n);

    cin >> c;
    while (c--) {
      cin >> a1 >> a2;
      --a1, --a2;
      if (a1 == a2) { r = 0; }
      else if (adjMat[a1][a2] == INF) { r = -1; }
      else { r = trunc(adjMat[a1][a2]); }
      cout << r << endl;
    }
  }

}
