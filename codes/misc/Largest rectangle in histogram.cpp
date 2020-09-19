int n, h[100003];

ll f() {
  stack<int> s;
  ll ans = 0;
  h[n] = 0;
  for (int i = 0; i <= n; ++i) {
    while (!s.empty() && h[i] < h[s.top()]) {
      int x = h[s.top()];
      s.pop();
      ans = max(ans, (ll)x * (s.empty() ? i : i - s.top() - 1));
    }
    s.push(i);
  }
  return ans;
}
