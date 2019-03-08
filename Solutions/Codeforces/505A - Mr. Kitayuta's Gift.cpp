#include <bits/stdc++.h>
using namespace std;

#define maxn 15

int n;
char s[maxn];

bool f(){
  int i, j;
  for(i = 0, j = n; i < j && s[i] == s[j]; ++i, --j);
  return i >= j;
}

int main(){
  // freopen("in","r",stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  cin >> (s + 1);
  n = strlen(s + 1);
  for(int k = 0; k <= n; ++k){
    s[k] = s[n - k];
    if(f()){
      cout << s << '\n';
      return 0;
    }
    s[k] = s[k + 1];
  }
  cout << "NA\n";

  return 0;
}
