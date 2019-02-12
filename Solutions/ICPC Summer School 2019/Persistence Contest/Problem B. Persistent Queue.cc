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
#define lg(x) (63 - __builtin_clzll(x))
#define maxn 200003
#define maxl lg(maxn)

struct Node{
  int n, x;
  Node* p[maxl];
  Node(){}
  Node(int n, int x, Node* p0) : n(n), x(x){
    p[0] = p0;
    for(int i = 1; i < maxl; ++i){
      p[i] = !p[i - 1] ? 0 : p[i - 1]->p[i - 1];
    }
  }
};

Node* q[maxn];

void push(Node* q, Node*& newq, int x){
  newq = new Node(q->n + 1, x, q);
}

int pop(Node* q, Node*& newq){
  Node* front = q;
  for(int i = maxl - 1, up = q->n - 1; i >= 0; --i){
    if(up >= (1 << i)){
      front = front->p[i];
      up -= 1 << i;
    }
  }
  newq = new Node();
  memcpy(newq, q, sizeof *q);
  --newq->n;
  return front->x;
}

int main(){
  freopen("in","r",stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  q[0] = new Node();
  q[0]->n = q[0]->x = 0;
  memset(q[0]->p, 0, sizeof q[0]->p);

  int n;
  cin >> n;
  for(int i = 1; i <= n; ++i){
    int t, v;
    cin >> t >> v;
    if(t == 1){
      int x;
      cin >> x;
      push(q[v], q[i], x);
    }
    else{
      cout << pop(q[v], q[i]) << endl;
    }
  }

  return 0;
}
