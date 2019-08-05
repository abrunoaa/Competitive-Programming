// g++ -std=c++11 -o "%e" "%f" -fsanitize=address -fno-omit-frame-pointer -DBALLOONFIELD -Wall -Wextra -Wfloat-equal -Wconversion -Winline -Wlogical-op

#include <bits/stdc++.h>
using namespace std;

#ifdef BALLOONFIELD
__attribute__((destructor))static void __destroy__() {cerr << "\nElapsed: " << (double)clock() / CLOCKS_PER_SEC << "s.\n";}

void debug() {}
template<class t, class... u> void debug(const t &x, const u &...y) {cerr << ' ' << x, debug(y...);}
# define debug(x...) cerr<<"\x1b[91m"<<__LINE__<<" ["#x"] =",debug(x),cerr<<"\x1b[0m\n"
# define sleep(x) this_thread::sleep_for(chrono::milliseconds(x))
#else
# define assert(x) void(0)
# define debug(...) void(0)
# define freopen(...) void(0)
# define sleep(x) void(0)
#endif

template<class T>inline int lb(vector<T> &v, const T &x) { return lower_bound(v.begin(), v.end(), x) - v.begin(); }
template<class T>inline int ub(vector<T> &v, const T &x) { return upper_bound(v.begin(), v.end(), x) - v.begin(); }
template<class T>inline int lb(T* v, int n, const T &x) { return lower_bound(v, v + n, x) - v; }
template<class T>inline int ub(T* v, int n, const T &x) { return upper_bound(v, v + n, x) - v; }

template<class A, class B>ostream &operator<<(ostream &f, const pair<A, B> &x) {return f << '(' << x.first << ", " << x.second << ')';}

#define DEF1(_class...) ostream&operator<<(ostream&f,const _class&x){int b=0;f<<'[';for(auto&y:x){if(b++)f<<", ";f<<y;}return f<<']';}
#define DEF2(get,pop,_class...) ostream&operator<<(ostream&f,_class x){int b=0;f<<'[';while(x.size()){if(b++)f<<", ";f<<x.get();x.pop();}return f<<']';}
template<class T> DEF1(vector<T>) template<class T, class C> DEF1(set<T, C>) template<class T, class C> DEF1(multiset<T, C>) template<class K, class T, class C> DEF1(map<K, T, C>) template<class K, class T, class C> DEF1(multimap<K, T, C>)
template<class T> DEF2(front, pop, queue<T>) template<class T> DEF2(top, pop, stack<T>) template<class T, class V, class C> DEF2(top, pop, priority_queue<T, V, C>)

#define st first
#define nd second
#define inf 0x3f3f3f3f
#define infl 0x3f3f3f3f3f3f3f3f
#define mod 1000000007
#define maxn 200003

#define rand() uid(rng)
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count()); // int = mt19937_64
uniform_int_distribution<int> uid((int) -1e9, (int)1e9);            // range for random

typedef long long ll;
typedef double lf;
typedef pair<int, int> ii;

#define offset (int)1e9
#define M ((l + r) / 2)
typedef int Int;
#define int ll

struct Node {
  Node* left, *right;
  multiset<ii> x;
  Node() : left(0), right(0) {}
};

Node* root;
int x[maxn], y[maxn];
map<int, vector<int>> at_x;
vector<int> ans;

void add(int i, int x, int id, Node* &t, int l = 0, int r = (int)3e9 + 3) {
  if (!t) { t = new Node(); }
  t->x.insert({x, id});
  if (l != r) {
    if (i <= M) { add(i, x, id, t->left, l, M); }
    else { add(i, x, id, t->right, M + 1, r); }
  }
}

void rem(int i, int x, int id, Node* t, int l = 0, int r = (int)3e9 + 3) {
  assert(t);
  t->x.erase({x, id});
  if (l != r) {
    if (i <= M) { rem(i, x, id, t->left, l, M); }
    else { rem(i, x, id, t->right, M + 1, r); }
  }
}

void qry(int i, int j, int a, int b, Node* &t, int l = 0, int r = (int)3e9 + 3) {
  assert(i <= j);
  assert(a <= b);
  if (!t) { return; }
  if (r < i || j < l) { return; }
  if (i <= l && r <= j) {
    // debug(i, j, a, b, l, r);
    for (auto it1 = t->x.lower_bound(ii(a, (int) -1e9)), it2 = t->x.upper_bound(ii(b, (int)1e9)); it1 != it2; ++it1) {
      ans.push_back(it1->nd);
    }
    return;
  }
  qry(i, j, a, b, t->left, l, M);
  qry(i, j, a, b, t->right, M + 1, r);
}

Int main() {
  assert(freopen("in", "r", stdin));
  assert(freopen("out", "w", stdout));
  assert(freopen("input", "w", stderr));
  ios_base::sync_with_stdio(0), cin.tie(0);
  int n;
  // cin >> n;
  n = 2e5;
  cerr << n << '\n';
  for (int i = 1; i <= n; ++i) {
    // cin >> x[i] >> y[i];
    x[i] = rand();
    y[i] = abs(rand());
    if (y[i] == 0) { ++y[i]; }
    cerr << x[i] << ' ' << y[i] << '\n';
    assert((int) -1e9 <= x[i] && x[i] <= (int)1e9);
    assert(y[i] > 0);
    x[i] += offset;
    ans.clear();
    qry(x[i] + 1, x[i] + 2 * y[i] - 1, x[i] - 2 * y[i] + 1, x[i] - 1, root);
    auto &at = at_x[x[i]];
    ans.insert(ans.end(), at.begin(), at.end());
    at.clear();
    sort(ans.begin(), ans.end());
    ans.resize(unique(ans.begin(), ans.end()) - ans.begin());
    cout << ans.size();
    for (int r : ans) {
      cout << ' ' << r;
      rem(x[r], x[r] - 2 * y[r], r, root); // esquerda
      rem(x[r] + 2 * y[r], x[r], r, root); // direita
    }
    cout << '\n';
    add(x[i], x[i] - 2 * y[i], i, root); // esquerda
    add(x[i] + 2 * y[i], x[i], i, root); // direita
    at_x[x[i]].push_back(i);
  }
  return 0;
}
