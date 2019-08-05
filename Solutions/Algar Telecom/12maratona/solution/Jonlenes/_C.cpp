#include <algorithm>
#include <iostream>
#include <utility>
#include <numeric>
#include <stack>
#include <queue>
#include <list>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <bitset>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <climits>
using namespace std;

struct aresta {

  aresta() {
    d = INT_MAX;
  }

  int u, v, d;

};

bool cmp (aresta a, aresta b) { return a.d < b.d; }

vector <aresta> edges;
vector <int> pai;
vector <int> peso;

int find(int x) {
  if (pai[x] == x) { return x; }
  return pai[x] = find(pai[x]);
}

void join( int u, int v ) {
  u = find(u);
  v = find(v);

  if (peso[u] < peso[v]) { pai[u] = v; }
  else if (peso[v] < peso[u]) { pai[v] = u; }
  else {
    pai[u] = v;
    peso[v]++;
  }
}




int main() {

  //freopen("input.txt","r", stdin);
  //freopen("out.txt","w", stdout);

  int cases, n, m, v;
  string s1, s2;


  scanf("%d ", &cases);

  //cout << n << endl;

  while (cases--) {

    cin >> n >> m;
    scanf(" ");

    edges.assign(m + 1, aresta());

    pai.assign(n, -1);
    for (int i = 0; i < n; i++) {
      pai[i] = i;
    }

    peso.assign(n, 0);

    map<string, int> mp;
    for (int i = 0; i < m; i++) {
      cin >> s1 >> s2 >> v;

      //cout << "'" << s1 << "'" << endl;
      if (mp.find(s1) == mp.end()) {
        int kkk = mp.size();
        mp[s1] = kkk;
      }

      //cout << "'" << s2 << "'" << endl;
      if (mp.find(s2) == mp.end()) {
        int kkk = mp.size();
        mp[s2] = kkk;
      }

      edges[i].u = mp[s1];
      edges[i].v = mp[s2];
      edges[i].d = v;

      //printf("%d %d %d\n", edges[i].u, edges[i].v, edges[i].d);
    }

    sort(edges.begin(), edges.end(), cmp);
    vector< aresta > mst;

    for (int i = 0; i < m; ++i) {
      if ( find(edges[i].u) != find(edges[i].v) ) {
        join(edges[i].u, edges[i].v);

        mst.push_back(edges[i]);
      }
    }

    long long soma = 0;
    for (int i = 0; i < int (mst.size()); ++i) {
      soma += mst[i].d;
    }

    cout << soma << endl;
    if (cases) { printf("\n"); }
  }

  return 0;
}


