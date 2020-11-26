
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main() {

  //freopen("../input.txt","r", stdin);
  //freopen("../out.txt","w", stdout);

  int n, m, v, i;

  while (cin >> n >> m) {

    vector<int> vet;
    while (n--) {
      cin >> v;
      vet.push_back(v);
    }

    sort(vet.begin(), vet.end());

    for (i = 1; i < vet.size(); ++i)
      if (vet[i - 1] == vet[i]) { break; }

    cout << (i != vet.size() ? 1 : 0) << endl;

  }

  return 0;
}