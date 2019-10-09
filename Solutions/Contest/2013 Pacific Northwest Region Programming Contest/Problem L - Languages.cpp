#include <bits/stdc++.h>
using namespace std;

const int maxn = 1000000;

char l[maxn];
char tmp[maxn];

void lower(char* s) {
  while (*s) {
    *s = (char)tolower(*s);
    ++s;
  }
}

vector<string> split(const char *s) {
  vector<string> v;
  string t;
  for (int i = 0; s[i]; ++i) {
    char c = s[i];
    if (isalpha(c) || c == '\'' || c == '-') {
      t.push_back(c);
    } else if (!t.empty()) {
      v.push_back(t);
      t.clear();
    }
  }
  if (!t.empty()) {
    v.push_back(t);
  }
  return v;
}

int main() {
  // assert(freopen("lin", "r", stdin));
  int n;
  scanf("%d", &n);
  map<string,string> lang;
  while (n--) {
    scanf(" %s", l);
    scanf(" %[^\n]", tmp);
    lower(tmp);
    for (auto &s : split(tmp)) {
      lang[s] = l;
    }
  }
  while (scanf(" %[^\n]", tmp) != -1) {
    lower(tmp);
    for (auto &s : split(tmp)) {
      if (lang.count(s)) {
        cout << lang[s] << '\n';
        break;
      }
    }
  }
  return 0;
}
