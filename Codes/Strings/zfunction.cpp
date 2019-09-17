vector<int> zfunc(const string& s) {
  vector<int> z(s.size(), 0);
  const int n = (int)s.size();
  for (int i = 1, l = 0, r = 0; i < n; ++i) {
    z[i] = i > r ? 0 : min(r - i + 1, z[i - l]);
    while (i + z[i] < n && s[z[i]] == s[i + z[i]])
      ++z[i];
    if (i + z[i] - 1 > r)
      l = i, r = i + z[i] - 1;
  }
  return z;
}
