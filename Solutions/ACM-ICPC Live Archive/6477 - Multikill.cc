#include <bits/stdc++.h>
using namespace std;

#ifdef BALLOONFIELD
__attribute__((destructor))static void __destroy__(){cerr<<"\nElapsed: "<<(double)clock()/CLOCKS_PER_SEC<<"s.\n";}

void debug(){}
template<class t,class... u> void debug(const t&x,const u&...y){cerr<<' '<<x,debug(y...);}
# define debug(x...) cerr<<"\x1b[91m"<<__LINE__<<" ["#x"] =",debug(x),cerr<<"\x1b[0m\n"
# define sleep(x) this_thread::sleep_for(chrono::milliseconds(x))
#else
# define assert(x) void(0)
# define debug(...) void(0)
# define freopen(...) void(0)
# define sleep(x) void(0)
#endif

template<class T>inline int lb(vector<T>& v, const T& x){ return lower_bound(v.begin(), v.end(), x) - v.begin(); }
template<class T>inline int ub(vector<T>& v, const T& x){ return upper_bound(v.begin(), v.end(), x) - v.begin(); }
template<class T>inline int lb(T* v, int n, const T& x){ return lower_bound(v, v + n, x) - v; }
template<class T>inline int ub(T* v, int n, const T& x){ return upper_bound(v, v + n, x) - v; }

template<class A,class B>ostream&operator<<(ostream&f,const pair<A,B>&x){return f<<'('<<x.first<<", "<<x.second<<')';}

#define DEF1(_class...) ostream&operator<<(ostream&f,const _class&x){int b=0;f<<'[';for(auto&y:x){if(b++)f<<", ";f<<y;}return f<<']';}
#define DEF2(get,pop,_class...) ostream&operator<<(ostream&f,_class x){int b=0;f<<'[';while(x.size()){if(b++)f<<", ";f<<x.get();x.pop();}return f<<']';}
template<class T> DEF1(vector<T>) template<class T,class C> DEF1(set<T,C>) template<class T,class C> DEF1(multiset<T,C>) template<class K,class T,class C> DEF1(map<K,T,C>) template<class K,class T,class C> DEF1(multimap<K,T,C>)
template<class T> DEF2(front,pop,queue<T>) template<class T> DEF2(top,pop,stack<T>) template<class T,class V,class C> DEF2(top,pop,priority_queue<T,V,C>)

#define null nullptr
#define st first
#define nd second
#define inf 0x3f3f3f3f
#define infl 0x3f3f3f3f3f3f3f3f
#define mod 1000000007
#define maxn "abacate"

#define rand() uid(rng)
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count()); // ll = mt19937_64
uniform_int_distribution<int> uid(0, numeric_limits<int>::max());             // range for random

typedef long long ll;
typedef double lf;
typedef pair<int,int> ii;

#define eps 1e-12

inline int cmp(lf x, lf y = 0.0){ return (abs(x - y) < eps ? 0 : x < y ? -1 : 1); }

struct pt{
  lf x, y;
  pt(lf x = 0.0, lf y = 0.0) : x(x), y(y) {}
  bool operator < (const pt& p) const{ return cmp(x, p.x) == 0 ? cmp(y, p.y) < 0 : cmp(x, p.x) < 0; }
};

struct Circle{
  lf x, y, r;
  Circle(lf x = 0.0, lf y = 0.0, lf r = 0.0) : x(x), y(y), r(r) {}

  int inside(pt p){
    int k = cmp(hypot(p.x - x, p.y - y), r);
    return k == 0 ? 2 : k < 0;     // 2 = borda, 1 = dentro, 0 = fora
  }

  // interseção de círculos com raio diferente
  int intersection(Circle c, pt& i1, pt& i2){
    lf d = hypot(x - c.x, y - c.y);
    if(cmp(d, r + c.r) > 0) return 0;  // separados
    if(cmp(d, abs(r - c.r)) < 0) return 0; // um contem o outro
    if(cmp(d) == 0 && cmp(r, c.r) == 0) return 0;  // coincidentes (iguais)

    lf a = (r * r - c.r * c.r + d * d) / (2.0 * d);
    lf x2 = x + a * (c.x - x) / d;
    lf y2 = y + a * (c.y - y) / d;
    lf h = sqrt(r * r - a * a);
    if(cmp(h) == 0){
      i1 = i2 = pt(x2, y2);
      return 1;
    }

    i1 = pt(x2 + h * (c.y - y) / d, y2 - h * (c.x - x) / d);
    i2 = pt(x2 - h * (c.y - y) / d, y2 + h * (c.x - x) / d);
    return 2;
  }
};

int main(){
  freopen("in","r",stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  int t;
  cin >> t;
  while(t--){
    int n;
    lf r;
    cin >> r >> n;

    pt p[n];
    Circle c[n];

    int ans = 0;
    map<pt,int> mp;
    for(int i = 0; i < n; ++i){
      cin >> p[i].x >> p[i].y;
      c[i].x = p[i].x;
      c[i].y = p[i].y;
      c[i].r = r;
      ++mp[p[i]];
      ans = max(ans, mp[p[i]]);
    }

    for(int i = 0; i < n; ++i){
      for(int j = i + 1; j < n; ++j){
        pt a, b;
        if(c[i].intersection(c[j], a, b)){
          Circle c(a.x, a.y, r);
          int tans = 0;
          for(int k = 0; k < n; ++k){
            if(c.inside(p[k])){
              ++tans;
            }
          }
          ans = max(ans, tans);

          c = Circle(b.x, b.y, r);
          tans = 0;
          for(int k = 0; k < n; ++k){
            if(c.inside(p[k])){
              ++tans;
            }
          }
          ans = max(ans, tans);
        }
      }
    }

    cout << ans << '\n';
  }

  return 0;
}
