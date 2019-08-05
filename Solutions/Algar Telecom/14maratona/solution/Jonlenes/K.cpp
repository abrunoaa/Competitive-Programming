#include <iostream>

using namespace std;

int  main() {

  unsigned long long vet[100001];

  vet[0] = 1;
  vet[1] = 2;
  for (int i = 2; i < 100001; ++i) {
    vet[i] = vet[i - 1] + vet[i - 2];
  }

  freopen("../input.txt", "r", stdin);
  freopen("../out.txt", "w", stdout);

  int n, v;

  cin >> n;
  while (n--) {
    cin >> v;
    cout << vet[v - 1] << endl;
  }


  return 0;
}
