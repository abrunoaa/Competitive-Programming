//11:22
//11:23
//11:25
//11:29

#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;


int main() {

  //freopen("../input.txt","r", stdin);
  //freopen("../out.txt","w", stdout);

  int n, v;

  while (cin >> n && n) {

    vector< pair<int, int> > vet;

    for (int i = 0; i < n; ++i) {
      cin >> v;
      vet.push_back( make_pair(v, i) );
    }

    sort(vet.begin(), vet.end());

    cout << vet[ vet.size() - 2].second + 1 << endl;

  }

  return 0;
}

