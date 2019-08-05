#include <bits/stdc++.h>
using namespace std;

int n, L[50000];

int f(deque<int> v) {
  int lis = 0;
  for (int i = 0; i < (int)v.size(); ++i) {
    int pos = lower_bound(L, L + lis, v[i]) - L;
    // cerr << pos << ' ' << v[i] << endl;
    L[pos] = v[i];
    lis = max(lis, pos + 1);
  }
  return lis;
}

int g(deque<int> v) {
  reverse(v.begin(), v.end());
  return f(v);
}

int main() {
  int n;
  cin >> n;
  int root = sqrt(n) + 1e-12;
  deque<int> ans, t;
  while (n >= 1) {
    t.clear();
    for (int i = 0; i < root && n >= 1; ++i, --n) {
      t.push_back(n);
    }
    ans.insert(ans.begin(), t.begin(), t.end());
  }
  for (int x : ans) {
    cout << x << ' ' ;
  }
  cout << '\n';
  return 0;

  int cnt = 0;
  deque<int> v(ans.size());
  for (int &x : v) {
    x = ++cnt;
  }
  int k = 1e9;
  do {
    int p = f(v) + g(v);
    if (p < k) {
      k = p;
      ans = v;
    }
  } while (next_permutation(v.begin(), v.end()));
  cout << k << endl;
  for (int x : ans) {
    cout << x << ' ' ;
  }
  cout << endl;

  return 0;
}
