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


typedef vector<int> vi;
typedef pair<int, int> ii;

class UnionFind { // OOP style
  private:
    vi p, rank; // remember: vi is vector<int>
  public:
    UnionFind(int N) {
      rank.assign(N, 0);
      p.assign(N, 0);
      for (int i = 0; i < N; i++) {
        p[i] = i;
      }
    }

    int findSet(int i) {
      return (p[i] == i) ? i : (p[i] = findSet(p[i]));
    }

    bool isSameSet(int i, int j) { return findSet(i) == findSet(j); }

    void unionSet(int i, int j) {
      if (!isSameSet(i, j)) { // if from different set
        int x = findSet(i), y = findSet(j);
        if (rank[x] > rank[y]) { p[y] = x; } // rank keeps the tree short
        else {
          p[x] = y;
          if (rank[x] == rank[y]) { rank[y]++; }
        }
      }
    }
};

vector< pair<int, ii> > EdgeList; // (weight, two vertices) of the edge
vector< pair<int, ii> > mst;

int kruskal(int V) {

  sort(EdgeList.begin(), EdgeList.end());
  //printf("initi kruskal \n");

  // note: pair object has built-in comparison function
  int mst_cost = 0;
  UnionFind UF(V); // all V are disjoint sets initially
  for (int i = 0; i < int(EdgeList.size()); i++) { // for each edge, O(E)
    pair<int, ii> front = EdgeList[i];
    if (!UF.isSameSet(front.second.first, front.second.second)) { // check
      mst_cost += front.first; // add the weight of e to MST
      UF.unionSet(front.second.first, front.second.second); // link them
      mst.push_back(front);
    }
  } // note: the runtime cost of UFDS is very light
  // note: the number of disjoint sets must eventually be 1 for a valid MST

  //printf("MST cost = %d (Kruskal’s)\n", mst_cost);

  return mst_cost;
}




int main() {

  freopen("../input.txt", "r", stdin);
  freopen("../out.txt", "w", stdout);

  int cases, n, m, v;
  string s1, s2;


  scanf("%d ", &cases);


  while (cases--) {

    cin >> n >> m;
    scanf(" ");

    map<string, int> mp;
    EdgeList.clear();
    mst.clear();


    for (int i = 0; i < m; i++) {
      cin >> s1 >> s2 >> v;

      if (mp.find(s1) == mp.end()) {
        int kkk = mp.size();
        mp[s1] = kkk;
      }

      if (mp.find(s2) == mp.end()) {
        int kkk = mp.size();
        mp[s2] = kkk;
      }

      EdgeList.push_back( make_pair(v, ii(mp[s1], mp[s2]) ) );
    }

    cout << kruskal(n) << endl;
    if (cases) { printf("\n"); }
  }

  return 0;
}
