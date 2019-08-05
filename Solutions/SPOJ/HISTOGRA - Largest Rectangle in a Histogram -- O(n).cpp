#include <iostream>
#include <stack>
using namespace std;

typedef long long ll;

int n, h[100003];

ll f() {
  stack<int> s;
  ll ans = 0;
  for (int i = 0; i < n; ++i) {
    while (!s.empty() && h[i] < h[s.top()]) {
      int x = h[s.top()];
      s.pop();
      ans = max(ans, (ll)x * (s.empty() ? i : i - s.top() - 1));
    }
    s.push(i);
  }
  while (!s.empty()) {
    int x = h[s.top()];
    s.pop();
    ans = max(ans, (ll)x * (s.empty() ? n : n - s.top() - 1));
  }
  return ans;
}

int main() {
  cin.sync_with_stdio(0), cin.tie(0);
  while (cin >> n && n) {
    for (int i = 0; i < n; ++i) { cin >> h[i]; }
    cout << f() << '\n';
  }
  return 0;
}
