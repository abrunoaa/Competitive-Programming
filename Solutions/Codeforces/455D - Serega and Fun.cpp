#include <bits/stdc++.h>
using namespace std;

void db() { cerr << endl; }

template<class t, class... u>
void db(t x, u... y)
{ cerr << " " << x, db(y...); }

#define gcd __gcd
#define st first
#define nd second
#define pb push_back
#define eps 1e-9
#define zero(x) (abs(x) < eps)
#define inf 0x3f3f3f3f
#define mod 1000000007
#define maxn 100010

typedef long long ll;
typedef long double lf;
typedef pair<int,int> ii;
typedef pair<ii,int> tri;
typedef vector<int> vi;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> Set;
typedef tree<int,int,less<int>,rb_tree_tag,tree_order_statistics_node_update> Map;

#ifdef LOCAL
struct _ { _() { assert(freopen("in","r",stdin)); } } _;
#define db(x...) cerr << " >>", db(x)
#else
struct _ { _() { cin.sync_with_stdio(0), cin.tie(0); } } _;
#define db(x...)
#endif

#define sqn 410

int n, bs, f[sqn][maxn] = {};
deque<int> v[sqn];

void upd(int l, int r){
  int bl = l / bs, br = r / bs;
  if (bl == br){
    auto &u = v[bl];
    int k = u[r % bs];
    // cerr << " >> "; for (int i = l; i <= r; ++i) cerr << u[i] << ' '; cerr << endl;
    u.erase(u.begin() + r % bs);
    u.insert(u.begin() + l % bs, k);
    // cerr << " >> "; for (int i = l; i <= r; ++i) cerr << u[i] << ' '; cerr << endl;
  }
  else{
    int k = v[br][r % bs];
    v[br].erase(v[br].begin() + r % bs);
    --f[br][k];
    v[bl].insert(v[bl].begin() + l % bs, k);
    ++f[bl][k];

    for (int i = bl + 1; i <= br; ++i){
      int k = v[i - 1].back();
      v[i - 1].pop_back();
      --f[i - 1][k];
      v[i].push_front(k);
      ++f[i][k];
    }
  }
}

int qry(int l, int r, int k){
  int ans = 0;
  int bl = l / bs, br = r / bs;
  if (bl == br){
    auto &u = v[bl];
    for (int i = l % bs; i <= r % bs; ++i){
      if (u[i] == k){
        ++ans;
      }
    }
  }
  else{
    auto &u = v[bl];
    for (int i = l % bs; i < bs; ++i){
      if (u[i] == k){
        ++ans;
      }
    }
    auto &t = v[br];
    for (int i = r % bs; i >= 0; --i){
      if (t[i] == k){
        ++ans;
      }
    }
    for (int i = bl + 1; i < br; ++i){
      ans += f[i][k];
    }
  }

  return ans;
}

int main(){
  cin >> n;
  bs = sqrt(n);
  for (int i = 0, t; i < n; ++i){
    cin >> t;
    v[i / bs].pb(t);
    ++f[i / bs][t];
  }

  int q, lastans = 0;
  cin >> q;
  while (q--){
    int op, l, r, k;
    cin >> op >> l >> r;
    l = (l + lastans - 1) % n;
    r = (r + lastans - 1) % n;
    if (l > r) swap(l, r);
    if (op == 1){
      upd(l, r);
    }
    else{
      cin >> k;
      k = (k + lastans - 1) % n + 1;
      lastans = qry(l, r, k);
      cout << lastans << '\n';
    }
  }

  return 0;
}

