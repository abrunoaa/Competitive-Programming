#include <bits/stdc++.h>
using namespace std;

#ifdef BALLOONFIELD
__attribute__((destructor))static void __destroy__(){cerr<<"\nElapsed: "<<(double)clock()/CLOCKS_PER_SEC<<"s.\n";}

void debug(){}
template<class t,class... u> void debug(const t &x, const u &...y){cerr<<' '<<x, debug(y...);}
#define debug(x...) cerr<<"\x1b[91m"<<__LINE__<<" ["#x"] =",debug(x),cerr<<"\x1b[0m\n"
#define sleep(x) this_thread::sleep_for(chrono::milliseconds(x))
#else
#define assert(x) void(0)
#define debug(...) void(0)
#define freopen(...) void(0)
#define sleep(x) void(0)
#endif

template<class T>inline int lb(const vector<T>&v,const T&x,int l=0,int r=-1){return(int)(lower_bound(v.begin()+l,(r==-1?v.end():v.begin()+r),x)-v.begin());}
template<class T>inline int ub(const vector<T>&v,const T&x,int l=0,int r=-1){return(int)(upper_bound(v.begin()+l,(r==-1?v.end():v.begin()+r),x)-v.begin());}
template<class T>inline int lb(const T*v,int n,const T&x,int l=0,int r=-1){return(int)(lower_bound(v+l,v+(r==-1?n:r),x)-v);}
template<class T>inline int ub(const T*v,int n,const T&x,int l=0,int r=-1){return(int)(upper_bound(v+l,v+(r==-1?n:r),x)-v);}

template<class A,class B>ostream&operator<<(ostream&f,const pair<A,B>&x){return f<<'('<<x.first<<", "<<x.second<<')';}

#define DEF1(_class...) ostream&operator<<(ostream&f,const _class&x){int b=0;f<<'[';for(auto&y:x){if(b++)f<<", ";f<<y;}return f<<']';}
#define DEF2(get,_class...) ostream&operator<<(ostream&f,_class x){int b=0;f<<'[';while(x.size()){if(b++)f<<", ";f<<x.get();x.pop();}return f<<']';}
template<class T>DEF1(vector<T>) template<class T,class C>DEF1(set<T,C>) template<class T,class C>DEF1(multiset<T,C>) template<class K,class T,class C>DEF1(map<K,T,C>) template<class K,class T,class C>DEF1(multimap<K,T,C>)
template<class T>DEF2(front,queue<T>) template<class T>DEF2(top,stack<T>) template<class T,class V,class C>DEF2(top,priority_queue<T,V,C>)

#define st first
#define nd second
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define forr(i, l, r) for (int i = (int)(l); i < (int)(r); ++i)
#define fore(i, v) for (auto &i : v)

#define rand() uid(rng)
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count()); // ll = mt19937_64
uniform_int_distribution<int> uid(0, numeric_limits<int>::max());             // range

typedef long long ll;
typedef double lf;
typedef pair<int,int> ii;
typedef pair<int,ii> tri;

const int inf = 0x3f3f3f3f;
const ll infl = 0x3f3f3f3f3f3f3f3f;
const lf eps = 1e-9;
const int mod = 1000000007;
//const int maxn = ;

bool know[10];

bool eval(int d, string a, char op, string b, string c) {
  fore(ch, a) if (ch == '?') ch = (char)(d + '0');
  fore(ch, b) if (ch == '?') ch = (char)(d + '0');
  fore(ch, c) if (ch == '?') ch = (char)(d + '0');
  debug(a, b, c);
  for (auto r : {a, b, c}) {
    if (r.size() >= 2 && r[0] == '0') return 0;
    if (r.size() >= 2 && r[0] == '-' && r[1] == '0') return 0;
  }

  ll va = stoi(a);
  ll vb = stoi(b);
  ll vc = stoi(c);
  ll r;

  if (op == '+') {
    r = va + vb;
  } else if (op == '-') {
    r = va - vb;
  } else {
    r = va * vb;
  }
  return r == vc;
}

int main() {
  assert(freopen("in", "r", stdin));
  ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int t;
  cin >> t;
  while (t--) {
    string expr;
    cin >> expr;

    string a, b, c;
    char op = 0;
    int id = 0;
    bool beg = 1;
    memset(know, 0, sizeof(know));
    fore(ch, expr) {
      if (ch == '=') {
        id = 2;
        beg = 1;
      } else if (!beg && (ch == '+' || ch == '-' || ch == '*')) {
        op = ch;
        id = 1;
        beg = 1;
      } else {
        beg = 0;
        if (id == 0) {
          a.push_back(ch);
        } else if (id == 1) {
          b.push_back(ch);
        } else {
          c.push_back(ch);
        }
        if (isdigit(ch)) {
          know[(int)(ch - '0')] = 1;
        }
      }
    }
    assert(op);
    debug(a, op, b, c);

    bool ok = 0;
    forn(d, 10) {
      if (!know[d] && eval(d, a, op, b, c)) {
        cout << d << '\n';
        ok = 1;
        break;
      }
    }
    if (!ok) {
      cout << "-1\n";
    }
    debug("done");
  }
  return 0;
}
