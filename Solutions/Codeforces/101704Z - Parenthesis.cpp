#include <bits/stdc++.h>
using namespace std;

int n;

set<string> ans;

bool vld(string str) {
  stack<char> P;

  for (int i = 0 ; i < n ; ++i) {

    if (str[i] == ')') {
      if (P.size() == 0) { return false; }
      if (P.top() == ')') { return false; }
      P.pop();
    } else {
      P.push('(');
    }
  }

  return (P.size() == 0);
}

void F(int idx, string str) {

  if (idx == n) {
    //~ cout << str << endl;
    if (vld(str)) { ans.insert(str); }
    return;
  }
  string aux = str + '(';
  F(idx + 1, aux);
  aux = str + ')';
  F(idx + 1, aux);
}



int main() {

  cin >> n;
  n *= 2;

  F(0, "");

  for (set<string>::iterator it = ans.begin() ; it != ans.end() ; ++it) {
    cout << *it << '\n';
  }



  return 0;
}
