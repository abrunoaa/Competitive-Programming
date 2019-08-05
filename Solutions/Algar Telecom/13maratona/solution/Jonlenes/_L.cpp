#include <bits/stdc++.h>

using namespace std;

const long long INF = -2000000000000LL;

int m, n, k;
vector<string> padroes;
int mat[101][101];
long long dp[101][101];


bool compativel(string s1, string s2) {
  for (int i = 0; i < int(s1.size()); ++i)
    if (!(s1[i] != s2[i] || s1[i] == '.' || s2[i] == '.')) {
      return false;
    }
  return true;
}

long long soma(int linha, string &pradrao) {
  long long r = 0;

  for (int i = 0; i < m; ++i) {
    if (pradrao[i] == '+') { r += mat[linha][i]; }
    else if (pradrao[i] == '-') { r -= mat[linha][i]; }
  }

  //cout << "R: " << r << endl;

  return r;
}

long long calcular(int linha, int padrao) {
  if (linha == n) { return 0; }

  if (dp[linha][padrao] == INF) {
    for (int i = 0; i < k; ++i)
      if (compativel(padroes[padrao], padroes[i])) {
        dp[linha][padrao] = max(dp[linha][padrao], calcular(linha + 1, i) + soma(linha, padroes[i]));
      }
  }

  return dp[linha][padrao];
}

int main() {

  //freopen("../input.txt","r", stdin);
  //freopen("../out.txt","w", stdout);

  int i, j;

  while (cin >> n >> m && n && m) {

    for (i = 0; i < n; ++i)
      for (j = 0; j < m; ++j) {
        cin >> mat[i][j];
      }

    cin >> k;

    //cout << k << endl;

    string padrao;

    padroes.clear();
    for (int i = 0; i < k; ++i) {
      cin >> padrao;
      padroes.push_back(padrao);
    }

    for (int i = 0 ; i < n; ++i)
      for (int j = 0 ; j < k; ++j) {
        dp[i][j] = INF;
      }

    long long r = INF;
    for (int i = 0; i < k; ++i) {
      r = max(r, calcular(1, i) + soma(0, padroes[i]));
    }

    cout << r << endl;

  }

  return 0;
}
