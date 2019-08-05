#include <bits/stdc++.h>
using namespace std;

#ifdef BALLOONFIELD
__attribute__((destructor))static void __destroy__() { cerr << "\nElapsed: " << (double)clock() / CLOCKS_PER_SEC << "s.\n"; }

void debug() {}
template<class t, class... u> void debug(const t &x, const u &...y) { cerr << ' ' << x, debug(y...); }
#define debug(x...) cerr<<"\x1b[91m[" #x "] =",debug(x),cerr<<"\x1b[0m\n"
#else
#define assert(x) void(0)
#define debug(...) void(0)
#define freopen(...) void(0)
#endif

int n, m, mus[100003], susp[10003], b[10003];
map<string, int> notas;

void start() {
  notas["A"] = 0;
  notas["Bb"] = notas["A#"] = 1;
  notas["B"] = notas["Cb"] = 2;
  notas["C"] = notas["B#"] = 3;
  notas["Db"] = notas["C#"] = 4;
  notas["D"] = 5;
  notas["Eb"] = notas["D#"] = 6;
  notas["E"] = notas["Fb"] = 7;
  notas["F"] = notas["E#"] = 8;
  notas["Gb"] = notas["F#"] = 9;
  notas["G"] = 10;
  notas["Ab"] = notas["G#"] = 11;
}

void kmp() {
  b[0] = -1;
  for (int i = 0, j = -1; i <= m; b[++i] = ++j) {
    while (j >= 1 && susp[i] != susp[j]) {
      j = b[j];
    }
  }
}

bool find() {
  int j = 1;
  for (int i = 1; i < n && j < m; ++i, ++j) {
    while (j >= 1 && mus[i] != susp[j]) {
      j = b[j];
    }
  }
  return (j == m);
}

int main() {
  freopen("in", "r", stdin);
  ios::sync_with_stdio(0), cin.tie(0);

  start();
  string s;
  while (cin >> n >> m && (n || m)) {
    for (int i = 0; i < n; ++i) {
      cin >> s;
      mus[i] = notas[s];
    }
    for (int i = 0; i < m; ++i) {
      cin >> s;
      susp[i] = notas[s];
    }
    for (int i = n - 1; i > 0; --i) {
      mus[i] = (mus[i] - mus[i - 1] + 12) % 12;
    }
    for (int i = m - 1; i > 0; --i) {
      susp[i] = (susp[i] - susp[i - 1] + 12) % 12;
    }
    kmp();
    cout << (find() ? 'S' : 'N') << '\n';
  }
  return 0;
}
