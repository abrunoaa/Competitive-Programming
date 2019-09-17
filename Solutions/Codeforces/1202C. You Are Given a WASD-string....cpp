#include <bits/stdc++.h>
using namespace std;

vector<int> sum(const string& s, char plus, char minus) {
  vector<int> u(1, 0);
  for (char c : s) {
    if (c == plus) {
      u.push_back(u.back() + 1);
    } else if (c == minus) {
      u.push_back(u.back() - 1);
    }
  }
  return u;
}

int calc(const vector<int>& s) {
  int mi = 0, ma = 0;
  for (int x : s) {
    mi = min(mi, x);
    ma = max(ma, x);
  }
  // cerr << " ## " << mi << ' ' << ma << endl;
  return ma - mi + 1;
}

int f(vector<int> s) {
  if (s.size() == 2) {
    return 2;
  }
  int ans = (int)1e9;
  for (int k = 0; k < 2; ++k) {
    int mn = 0, mx = 0;
    int firstmin = 0, lastmax = 0;
    for (int i = 0; i < (int)s.size(); ++i) {
      int x = s[i];
      if (x >= mx) {
        mx = x;
        lastmax = i;
      }
      if (x < mn) {
        mn = x;
        firstmin = i;
      }
    }
    for (int &x : s) {
      x *= -1;
    }
    ans = min(ans, mx - mn + (lastmax >= firstmin));
  }
  // cerr << " $$ " << min << ' ' << max << endl;
  return ans;
}

int main() {
  // assert(freopen("in", "r", stdin));
  cin.sync_with_stdio(0), cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    auto ws = sum(s, 'W', 'S');
    auto ad = sum(s, 'A', 'D');
    cerr << " >> " << calc(ws) << ' ' << f(ad) << ' ' << f(ws) << ' ' << calc(ad) << endl;
    cout << min(1ll * calc(ws) * f(ad), 1ll * f(ws) * calc(ad)) << '\n';
  }
  return 0;
}

/*
const string moves = "WASD";

struct Area {
  int minx, maxx;
  int miny, maxy;

  Area() : minx(0), maxx(0), miny(0), maxy(0) {}

  ll eval() {
    return (ll)(maxx - minx + 1) * (maxy - miny + 1);
  }
};

ostream& operator << (ostream& out, Area a) {
  return out << '(' << a.minx << ", " << a.maxx << "; " << a.miny << ", " << a.maxy << ')';
}

int main() {
  // assert(freopen("in", "r", stdin));
  cin.sync_with_stdio(0), cin.tie(0);
  map<char,int> dirx = {{'A', -1}, {'D', +1}};
  map<char,int> diry = {{'S', -1}, {'W', +1}};
  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;
    vector<Area> back(s.size() + 1);
    for (int i = (int)s.size() - 1; i >= 0; --i) {
      int dx = dirx[s[i]];
      int dy = diry[s[i]];
      back[i].minx = min(0, back[i + 1].minx + dx);
      back[i].maxx = max(0, back[i + 1].maxx + dx);
      back[i].miny = min(0, back[i + 1].miny + dy);
      back[i].maxy = max(0, back[i + 1].maxy + dy);
    }
    ll ans = back[0].eval();
    // cerr << " >> " << ans << endl;
    int x = 0, y = 0;
    Area u;
    for (int i = 0; i < (int)s.size(); ++i) {
      for (char c : moves) {
        Area v = back[i];
        int dx = dirx[c];
        int dy = diry[c];
        // cerr << " $$ " << v << ' ' << dx << ' ' << dy << endl;
        v.minx += x + dx;
        v.maxx += x + dx;
        v.miny += y + dy;
        v.maxy += y + dy;
        // cerr << " §§ " << u << ' ' << v << endl;
        Area w;
        w.minx = min(u.minx, v.minx);
        w.maxx = max(u.maxx, v.maxx);
        w.miny = min(u.miny, v.miny);
        w.maxy = max(u.maxy, v.maxy);
        ans = min(ans, w.eval());
        // cerr << " -- " << i << ' ' << c << " == " << w.eval() << endl;
      }
      x += dirx[s[i]];
      y += diry[s[i]];
      u.minx = min(u.minx, x);
      u.maxx = max(u.maxx, x);
      u.miny = min(u.miny, y);
      u.maxy = max(u.maxy, y);
    }
    cout << ans << '\n';
  }
  return 0;
}
//*/
