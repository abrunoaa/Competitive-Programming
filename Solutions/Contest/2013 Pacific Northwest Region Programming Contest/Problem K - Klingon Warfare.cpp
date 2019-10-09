#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;

struct No {
  int size, style;
  vector<No*> child;
};

struct Cmp {;
  bool operator()(const vi& x, const vi& y) {
    if (x.size() != y.size()) {
      return x.size() < y.size();
    }
    return x < y;
  }
};

const int maxn = 10003;

bool first;
int ans, cnt, memPos;
set<int> clan;
map<vi,int,Cmp> sub[30];
No mem[2 * maxn];

void init() {
  ans = cnt = memPos = 0;
  clan.clear();
  for (auto &x : sub) x.clear();
}

int getid(int style, vi &child) {
  int &id = sub[style][child];
  if (!id) id = ++cnt;
  return id;
}

int check(No* r) {
  vi child;
  for (No* c : r->child) {
    child.push_back(check(c));
    r->size += c->size;
  }
  int id = getid(r->style, child);
  if (first) {
    clan.insert(id);
  } else if (clan.count(id)) {
    ans = max(ans, r->size);
  }
  return id;
}

void read(int n, int diff) {
  No* root = 0;
  while (n--) {
    char s;
    int p;
    cin >> s >> p;
    No* ptr = mem + memPos++;
    ptr->size = 1;
    ptr->style = s - 'A';
    ptr->child.clear();
    if (p == -1) {
      root = ptr;
    } else {
      mem[p + diff].child.push_back(ptr);
    }
  }
  check(root);
}

int main() {
  // assert(freopen("in", "r", stdin));
  cin.sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    init();
    int m, n;
    cin >> m >> n;
    first = 1;
    read(m, 0);
    first = 0;
    read(n, m);
    cout << ans << '\n';
  }
  return 0;
}
