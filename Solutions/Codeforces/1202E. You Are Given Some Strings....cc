#include <bits/stdc++.h>
using namespace std;

const int maxn = (int)2e5 + 3;

struct No {
  int end;
  map<char,No*> child;
  explicit No(int x) : end(x) {}
};

int n;
string t, s[maxn];
No* root;

vector<int> zfunc(const string& str) {
  vector<int> z(str.size(), 0);
  const int n = (int)str.size();
  for (int i = 1, l = 0, r = 0; i < n; ++i) {
    if (i <= r)
      z[i] = min (r - i + 1, z[i - l]);
    while (i + z[i] < n && str[z[i]] == str[i + z[i]])
      ++z[i];
    if (i + z[i] - 1 > r)
      l = i, r = i + z[i] - 1;
  }
  return z;
}

void add(const string& str) {
  No* r = root;
  for (char c : str) {
    auto &p = r->child[c];
    if (!p) {
      p = new No(0);
    }
    r = p;
  }
  ++r->end;
}

int qry(int i) {
  int ans = 0;
  No *r = root;
  for (; i < (int)t.size(); ++i) {
    r = r->child[t[i]];
    if (!r) {
      break;
    }
    ans += r->end;
  }
  return ans;
}

vector<int> get() {
  root = new No(0);
  const int r = (int)sqrt(maxn);
  vector<int> matches(t.size());
  for (int i = 0; i < n; ++i) {
    if ((int)s[i].size() <= r) {
      add(s[i]);
    } else {
      vector<int> z = zfunc(s[i] + "$" + t);
      for (int j = 0; j < (int)t.size(); ++j) {
        matches[j] += (z[j + (int)s[i].size() + 1] == (int)s[i].size());
      }
    }
  }
  for (int i = 0; i < (int)t.size(); ++i) {
    matches[i] += qry(i);
  }
  return matches;
}

int main() {
  // assert(freopen("in", "r", stdin));
  cin.sync_with_stdio(0), cin.tie(0);
  cin >> t >> n;
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
  }
  auto u = get();
  reverse(t.begin(), t.end());
  for (int i = 0; i < n; ++i) {
    reverse(s[i].begin(), s[i].end());
  }
  auto v = get();
  reverse(v.begin(), v.end());
  long long ans = 0;
  for (int i = 1; i < (int)t.size(); ++i) {
    ans += (long long)v[i - 1] * u[i];
  }
  cout << ans << '\n';
  return 0;
}
