#include <algorithm>
#include <iostream>
#include <utility>
#include <numeric>
#include <stack>
#include <queue>
#include <list>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <bitset>
#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <climits>
#include <utility>

using namespace std;

string vetPositivo[] = {"excelente", "bom", "otimo", "adoro", "amo"};
string vetNegativo[] = {"ruim", "pessimo", "odeio", "droga", "fraco"};

int main() {

  //freopen("../input.txt","r", stdin);
  //freopen("../out.txt","w", stdout);

  int n;
  string s;
  int valor, qtde;

  while (scanf(" %d ", &n) != EOF) {

    qtde = 0;
    while (n--) {
      getline(cin, s);

      valor = 0;
      for (int i = 0; i < 5; ++i) {
        if (s.find(vetPositivo[i]) != string::npos) {
          if (s.find("nao " + vetPositivo[i]) != string::npos) { valor--; }
          else { valor++; }
        }
        if (s.find(vetNegativo[i]) != string::npos) {
          if (s.find("nao " + vetNegativo[i]) != string::npos) { valor++; }
          else { valor--; }
        }
      }
      if (valor > 0) { qtde++; }
      else if (valor < 0) { qtde--; }
    }

    printf("%s\n", (qtde > 0) ? "positivo" : (qtde < 0) ? "negativo" : "neutro");

  }

  return 0;
}