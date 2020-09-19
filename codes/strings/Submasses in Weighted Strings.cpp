const int maxfft = (1 << (32 - __builtin_clz(2 * 26 * maxn - 1))) + 3;

cpx p[maxfft], q[maxfft];

void compute(string s) {
  int mu = 0, k = 0;
  for (int i = 0; i < (int)s.size(); ++i) {
    mu += s[i] - 'a' + 1;     // valor da letra
    p[mu] = 1.0;
  }
  for (int i = 0; i < (int)s.size(); ++i) {
    q[mu - k] = 1.0;
    k += s[i] - 'a' + 1;      // valor da letra
  }
  conv(p, mu + 1, q, mu + 1); // p e q devem 'aguentar' o valor de mu
}

int numberSubmasses() {
  int ans = 0;
  for (int i = mu + 1; i < 2 * (mu + 1); ++i)
    if (p[i].a > 0.5) // p[i].a != 0
      ++ans;
  return ans;
}

vector<int> submasses() {
  vector<int> sub;
  for (int i = mu + 1; i < 2 * (mu + 1); ++i)
    if (p[i].a > 0.5) // p[i].a != 0
      sub.push_back(int(p[i].a + 0.5));
  return sub;
}
