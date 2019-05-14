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
#define eps 1e-9
#define zero(x) (abs(x) < eps)
#define pi acos(-1.0l)
#define inf 0x3f3f3f3f
#define infl 0x3f3f3f3f3f3f3f3f
#define mod 1000000007
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

#if !defined ONLINE_JUDGE || defined LOCAL
__attribute__((destructor)) static void destroy()
{ cerr << "\nTime elapsed: " << (lf)clock() / CLOCKS_PER_SEC << "s.\n"; }

#define db(x...) cerr << " >> [" #x "] =", db(x)
#else
#warning "JUDGE"
#define NDEBUG
#define db(...) 42
#endif

template<class t> t sq(t x) { return x * x; }

int main(){
  // freopen("in","r",stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  int q;
  while(cin >> q){
    Set<int> s;

    while(q--){
      char op;
      int x;
      cin >> op >> x, op |= 32;

      if(op == 'i'){
        s.insert(x);
      }
      else if(op == 'd'){
        s.erase(x);
      }
      else if(op == 'k'){
        if(x > (int)s.size()){
          cout << "invalid\n";
        }
        else{
          cout << *s.find_by_order(x - 1) << endl;
        }
      }
      else{
        cout << s.order_of_key(x) << endl;
      }
    }
  }

  return 0;
}
