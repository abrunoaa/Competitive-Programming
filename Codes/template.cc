#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template<class t> using tset = tree<t,null_type,less<t>,rb_tree_tag,tree_order_statistics_node_update>;

#ifdef BALLOONFIELD
__attribute__((destructor))static void __destroy__(){ cerr<<"\nElapsed: "<<(double)clock()/CLOCKS_PER_SEC<<"s.\n"; }

void debug(){}
template<class t,class... u> void debug(const t& x,const u& ...y){ cerr<<' '<<x,debug(y...); }
#define debug(x...) cerr<<"\x1b[91m[" #x "] =",debug(x),cerr<<"\x1b[0m\n"
#else
#define assert(x) void(0)
#define debug(...) void(0)
#define freopen(...) void(0)
#endif

#define st first
#define nd second
#define pb push_back
#define zero(x) (abs(x)<eps)
#define pi acos(-1.0l)
#define inf 0x3f3f3f3f
#define infl 0x3f3f3f3f3f3f3f3f
#define gcd __gcd
#define popcnt __builtin_popcountll
#define ctz __builtin_ctzll
#define clz __builtin_clzll
#define lg(x) (63-clz(x))

template<class t1,class t2>ostream&operator<<(ostream&out,const pair<t1,t2>&x){return out<<'('<<x.st<<", "<<x.nd<<')';}

#define PRINT_DS bool flag=0;out<<'[';for(auto&x:ds){if(flag)out<<", ";else flag=1;out<<x;}return out<<']'
template<class t>ostream&operator<<(ostream&out,const vector<t>&ds){PRINT_DS;}
template<class t>ostream&operator<<(ostream&out,const set<t>&ds){PRINT_DS;}
template<class t>ostream&operator<<(ostream&out,const tset<t>&ds){PRINT_DS;}
template<class t1,class t2>ostream&operator<<(ostream&out,const map<t1,t2>&ds){PRINT_DS;}

typedef long long ll;
typedef unsigned long long ull;
typedef double lf;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

#define eps 1e-9
#define mod 1000000007
#define maxn "abacate"

int main(){
  freopen("in","r",stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  return 0;
}
