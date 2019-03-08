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

#define maxm 12

char mat[maxn][maxm] = {};
int n, m, q, bs;
ii go[maxn][maxm] = {};

inline int getb(int x){ return (x - 1) / bs; }

ii build(int x, int y, int b){
  if (getb(x) != b) return ii(x, y);

  ii &pd = go[x][y];
  if (pd.st || pd.nd) return pd;

  char c = mat[x][y];
  if (c == '^') return pd = build(x - 1, y, b);
  if (c == '<'){
    if (mat[x][y - 1] == '>'){
      return pd = ii(-1,-1);
    }
    return pd = build(x, y - 1, b);
  }
  if (mat[x][y + 1] == '<'){
    return pd = ii(-1,-1);
  }
  return pd = build(x, y + 1, b);
}

void rebuild(int x, int y, int b, ii ans){
  go[x][y] = ans;
  char c = mat[x][y];
  if (mat[x + 1][y] == '^' && b == getb(x + 1)) rebuild(x + 1, y, b, ans);
  if (mat[x][y - 1] == '>' && c != '<') rebuild(x, y - 1, b, ans);
  if (mat[x][y + 1] == '<' && c != '>') rebuild(x, y + 1, b, ans);
}

void upd(){
  char c;
  int x, y;
  cin >> x >> y >> c;
  if (mat[x][y] == c) return;

  mat[x][y] = c;
  int b = getb(x);

  if (c == '>'){
    if (mat[x][y + 1] == '<'){
      rebuild(x, y + 1, b, ii(-1,-1));
    }
    rebuild(x, y, b, go[x][y + 1]);
  }
  else if (c == '<'){
    if (mat[x][y - 1] == '>'){
      rebuild(x, y - 1, b, ii(-1,-1));
    }
    rebuild(x, y, b, go[x][y - 1]);
  }
  else{
    if (b != getb(x - 1)){
      rebuild(x, y, b, ii(x - 1, y));
    }
    else{
      rebuild(x, y, b, go[x - 1][y]);
    }
  }
}

void qry(){
  ii ans;
  cin >> ans.st >> ans.nd;
  while (ans.st >= 1 && ans.nd >= 1 && ans.nd <= m){
    ans = go[ans.st][ans.nd];
  }
  cout << ans.st << ' ' << ans.nd << '\n';
}

int main(){
  cin >> n >> m >> q;
  bs = sqrt(n);
  for (int i = 1; i <= n; ++i){
    cin >> (mat[i] + 1);
  }
  for (int i = 0; i <= n; ++i){
    go[i][0] = ii(i, 0);
    go[i][m + 1] = ii(i, m + 1);
  }
  for (int i = 1; i <= m; ++i){
    go[0][i] = ii(0, i);
  }
  for (int i = 1; i <= n; ++i){
    for (int j = 1; j <= m; ++j){
      build(i, j, getb(i));
    }
  }
  while (q--){
    char c;
    cin >> c;
    if (c == 'C'){
      upd();
    }
    else{
      qry();
    }
  }

  return 0;
}
