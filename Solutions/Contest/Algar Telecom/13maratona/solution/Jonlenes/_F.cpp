#include <bits/stdc++.h>

using namespace std;

const long N = 100001;


unsigned long long fat[N];

int main() {

  //freopen("in.txt", "r", stdin);
  //freopen("out.txt", "w", stdout);

  fat[1] = 1;
  fat[2] = 2;
  fat[3] = 1;

  for (int i = 4; i < N; ++i) {
    fat[i] = (fat[i - 1] * i) % 1000000009;
  }

  int n;
  while (cin >> n && n) {
    cout << fat[n] << endl;
  }

}
