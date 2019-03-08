#include <bits/stdc++.h>
using namespace std;

#define gcd __gcd
#define popcnt __builtin_popcount
#define ctz __builtin_ctz
#define clz __builtin_clz
#define endl '\n'
#define st first
#define nd second
#define pb push_back
#define eps
#define zero(x) (abs(x) < eps)
#define pi acos(-1.0l)
#define inf 0x3f3f3f3f
#define infl 0x3f3f3f3f3f3f3f3f
#define mod
#define maxn 100010

typedef long long ll;
typedef long double lf;
typedef pair<int,int> ii;
typedef pair<ii,int> tri;
typedef pair<ii,ii> qua;
typedef vector<int> vi;
typedef vector<ii> vii;

#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

template<class t>
using Set = tree<t,null_type,less<t>,rb_tree_tag,tree_order_statistics_node_update>;
template<class t,class u>
using Map = tree<t,u,less<t>,rb_tree_tag,tree_order_statistics_node_update>;

void db() { cerr << endl; }

template<class t, class... u>
void db(t x, u... y)
{ cerr << ' ' << x, db(y...); }

#ifndef ONLINE_JUDGE
__attribute__((destructor)) static void destroy()
{ cerr << "\nTime elapsed: " << (lf)clock() / CLOCKS_PER_SEC << "s.\n"; }

#define db(x...) cerr << " >> [" #x "] =", db(x)
#else
#warning "JUDGE"
#define NDEBUG
#define db(...) 42
#endif

template<class t> t sq(t x) { return x * x; }

#define L (2 * k)
#define R (L + 1)
#define M ((l + r) / 2)

struct no{
  int lazy, n[26];
};

int n, q;
string s;
no st[4 * maxn];

no merge(const no& x, const no& y){
  no z;
  z.lazy = 0;
  for(int i = 0; i < 26; ++i){
    z.n[i] = x.n[i] + y.n[i];
  }
  return z;
}

no build(int k = 1, int l = 0, int r = n - 1){
  if(l == r){
    st[k].n[s[l] - 'a'] = 1;
    return st[k];
  }
  return st[k] = merge(build(L, l, M), build(R, M+1, r));
}

void prop(int k, int len){
  no &s = st[k];
  if(s.lazy){
    memset(s.n, 0, sizeof s.n);
    s.n[s.lazy - 'a'] = len;

    if(len > 1){
      st[L].lazy = st[R].lazy = s.lazy;
    }
    s.lazy = 0;
  }
}

no upd(int i, int j, int x, int k = 1, int l = 0, int r = n - 1){
  if(i <= l && r <= j){
    st[k].lazy = x;
    prop(k, r - l + 1);
    return st[k];
  }
  prop(k, r - l + 1);
  if(r < i || j < l) return st[k];
  return st[k] = merge(upd(i, j, x, L, l, M), upd(i, j, x, R, M+1, r));
}

no qry(int i, int j, int k = 1, int l = 0, int r = n - 1){
  if(r < i || j < l) return no{ 0, {} };
  prop(k, r - l + 1);
  if(i <= l && r <= j) return st[k];
  return merge(qry(i, j, L, l, M), qry(i, j, R, M+1, r));
}

void print(int k = 1, int l = 0, int r = n - 1){
  prop(k, r - l + 1);
  if(l == r){
    for(int i = 0; i < 26; ++i){
      if(st[k].n[i]){
        cout << char(i + 'a');
        while(++i < 26){
          assert(st[k].n[i] == 0);
        }
        return;
      }
    }
    db(l);
    assert(0);
  }
  print(L, l, M);
  print(R, M+1, r);
}

int main(){
  // freopen("in","r",stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  cin >> n >> q >> s;
  build();
  while(q--){
    int l, r, t;
    cin >> l >> r >> t, --l, --r;

    no x = qry(l, r);
    if(t == 1){
      for(int i = 'a', k = l; i <= 'z'; ++i){
        if(x.n[i - 'a']){
          upd(k, k + x.n[i - 'a'] - 1, i);
          k += x.n[i - 'a'];
        }
      }
    }
    else{
      for(int i = 'z', k = l; i >= 'a'; --i){
        if(x.n[i - 'a']){
          upd(k, k + x.n[i - 'a'] - 1, i);
          k += x.n[i - 'a'];
        }
      }
    }
  }
  print();
  cout << endl;

  return 0;
}
