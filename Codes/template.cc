#include <bits/stdc++.h>
using namespace std;

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

template<class A,class B>ostream&operator<<(ostream&f,const pair<A,B>&x){return f<<'('<<x.first<<", "<<x.second<<')';}

#define PRINT int b=0;f<<'[';for(auto&y:x){if(b++)f<<", ";f<<y;}return f<<']';
template<class T>ostream&operator<<(ostream&f,const vector<T>&x){PRINT;}
template<class T,class C>ostream&operator<<(ostream&f,const set<T,C>&x){PRINT;}
template<class T,class C>ostream&operator<<(ostream&f,const multiset<T,C>&x){PRINT;}
template<class K,class T,class C>ostream&operator<<(ostream&f,const map<K,T,C>&x){PRINT;}
template<class K,class T,class C>ostream&operator<<(ostream&f,const multimap<K,T,C>&x){PRINT;}

#define PRINT2(funcGet,funcPop) int b=0;f<<'[';while(!x.empty()){if(b++)f<<", ";f<<x.funcGet();x.funcPop();}return f<<']';
template<class T>ostream&operator<<(ostream&f,queue<T>x){PRINT2(front,pop)}
template<class T>ostream&operator<<(ostream&f,stack<T>x){PRINT2(top,pop)}
template<class T,class V,class C>ostream&operator<<(ostream&f,priority_queue<T,V,C>x){PRINT2(top,pop)}

#define null nullptr
#define st first
#define nd second
#define inf 0x3f3f3f3f
#define infl 0x3f3f3f3f3f3f3f3f
#define mod 1000000007
#define maxn "abacate"

typedef long long ll;
typedef double lf;
typedef pair<int,int> ii;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
mt19937_64 rngll(chrono::high_resolution_clock::now().time_since_epoch().count());

int main(){
  freopen("in","r",stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  return 0;
}
