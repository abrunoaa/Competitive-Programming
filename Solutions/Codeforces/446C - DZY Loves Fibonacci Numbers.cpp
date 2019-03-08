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
#define mod 1000000009
#define maxn 300003

typedef long long ll;
typedef long double lf;
typedef pair<int,int> ii;
typedef pair<ii,int> tri;
typedef vector<int> vi;
typedef vector<ii> vii;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> Set;
typedef tree<int,int,less<int>,rb_tree_tag,tree_order_statistics_node_update> Map;

#ifndef ONLINE_JUDGE
struct _ { _() { assert(freopen("in","r",stdin)); } } _;
#define db(x...) cerr << " >>", db(x)
#else
#warning "ONLINE_JUDGE"
struct _ { _() { cin.sync_with_stdio(0), cin.tie(0); } } _;
#define db(x...)
#endif

#define bs 550

int n, m, f[maxn], fsum[maxn], hasq[maxn], op[maxn], l[maxn], r[maxn];

inline void add(int &x, int y){
  x += y;
  if(x >= mod) x -= mod;
  else if(x < 0) x += mod;
}

struct block{
  int ans, beg, u[bs];
  vi upd;

  void change(){
    if(upd.empty()) return;

    int x = 0, y = 0;
    for(int l : upd){
      add(x, f[beg - l + 1]);
      add(y, f[beg - l + 2]);
    }
    upd.clear();

    add(u[0], x);
    add(u[1], y);
    for(int i = 2; i < bs; ++i){
      int z = x;
      add(z, y);
      add(u[i], z);
      x = y;
      y = z;
    }
  }
} blk[bs];

void build(){
  f[0] = fsum[0] = 0;
  f[1] = fsum[1] = 1;
  for(int i = 2; i < maxn; ++i){
    f[i] = f[i - 2];
    add(f[i], f[i - 1]);
    fsum[i] = fsum[i - 1];
    add(fsum[i], f[i]);
  }

  for(int i = 0, k = 0; i < bs; ++i, k += bs){
    blk[i].beg = k;
  }
}

void upd(int l, int r){
  int a = l / bs, b = r / bs;
  if(a == b){
    l %= bs;
    r %= bs;
    auto &b = blk[a].u;
    auto &ans = blk[a].ans;
    for(int k = 1; l <= r; ++k, ++l){
      add(b[l], f[k]);
      add(ans, f[k]);
    }
  }
  else{
    for(int i = l % bs, k = 1; i < bs; ++i, ++k){
      add(blk[a].u[i], f[k]);
      add(blk[a].ans, f[k]);
    }
    for(int i = r % bs, k = r - l + 1; i >= 0; --i, --k){
      add(blk[b].u[i], f[k]);
      add(blk[b].ans, f[k]);
    }
    while(++a < b){
      int x = fsum[(a + 1) * bs - l];
      add(x, -fsum[a * bs - l]);
      add(blk[a].ans, x);
      if(hasq[a]){
        blk[a].upd.pb(l);
        if((int)blk[a].upd.size() > 60000) blk[a].change();
      }
    }
  }
}

int qry(int l, int r){
  int ans = 0;
  int a = l / bs, b = r / bs;
  l %= bs;
  r %= bs;
  blk[a].change();

  if(a == b){
    for(int i = l, j = r; i <= j; ++i){
      add(ans, blk[a].u[i]);
    }
  }
  else{
    blk[b].change();
    for(int i = l; i < bs; ++i){
      add(ans, blk[a].u[i]);
    }
    for(int i = r; i >= 0; --i){
      add(ans, blk[b].u[i]);
    }
    while(++a < b){
      add(ans, blk[a].ans);
    }
  }
  return ans;
}

int main(){
  cin >> n >> m;
  build();
  for(int i = 0, j = 0, k = 0, x; i < n; ++i){
    cin >> x;
    blk[j].u[k++] = x;
    add(blk[j].ans, x);
    if(k == bs){
      ++j;
      k = 0;
    }
  }

  for(int i = 0; i < m; ++i){
    cin >> op[i] >> l[i] >> r[i], --l[i], --r[i];
    if(op[i] == 2){
      ++hasq[l[i] / bs];
      ++hasq[r[i] / bs];
    }
  }
  for(int i = 0; i < m; ++i){
    if(op[i] == 1){
      upd(l[i], r[i]);
    }
    else{
      --hasq[l[i] / bs];
      --hasq[r[i] / bs];
      cout << qry(l[i], r[i]) << '\n';
    }
  }

  return 0;
}

// cap 2 2.2, 2.3, 2.4
