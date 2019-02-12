#include <bits/stdc++.h>
using namespace std;

#ifndef ONLINE_JUDGE
__attribute__((destructor)) static void __destroy__(){ cerr << "\nTime elapsed: " << (double)clock() / CLOCKS_PER_SEC << "s.\n"; }

void debug(){}
template<class t, class... u> void debug(const t& x, const u& ...y){ cerr << ' ' << x, debug(y...); }
#define debug(x...) cerr << "\x1b[91m[" #x "] =", debug(x), cerr << "\x1b[0m\n"
#else
#define assert(x) void(0)
#define debug(...) void(0)
#define freopen(...) void(0)
#endif

#define endl '\n'
#define maxn 200003

struct Node{
  int m, sum;
  Node* next;
  Node(){}
  Node(int m, int sum, Node* next) : m(m), sum(sum), next(next) {}
};

Node* root[maxn];

int main(){
  freopen("in","r",stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  root[0] = new Node(0, 0, 0);

  int n;
  cin >> n;
  long long ans = 0;
  for(int i = 1; i <= n; ++i){
    int t, m;
    cin >> t >> m;
    Node* r = root[t];
    root[i] = m == 0 ? r->next : new Node(m, m + r->sum, r);
    ans += root[i]->sum;
    debug(root[i]->sum);
  }
  cout << ans << endl;

  return 0;
}
