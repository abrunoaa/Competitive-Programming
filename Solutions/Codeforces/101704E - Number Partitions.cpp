#include <bits/stdc++.h>
using namespace std;

vector<int> v;

void f(int n, int m) {
  if (!n) {
    for (int i = 0; i < (int)v.size(); ++i) {
      if (i) { cout << '+'; }
      cout << v[i];
    }
    cout << '\n';
  }

  for (int k = min(n, m); k; --k) {
    v.push_back(k);
    f(n - k, k);
    v.pop_back();
  }
}

int main() {
  int n;
  cin >> n;
  f(n, n);

  return 0;
}
