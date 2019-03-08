#include <bits/stdc++.h>
using namespace std;

#define st first
#define nd second
#define infl 0x3f3f3f3f3f3f3f3f
#define maxn 5010

typedef long long ll;

template<class T>
struct MaxQueue{
  typedef pair<T,int> P;

  int n;
  deque<P> q;

  MaxQueue() : n(0), q() {}

  int size(){ return n; }
  T front(){ assert(n); return q.front().st; }
  void clear(){
    n = 0;
    q.clear();
  }
  void pop(){
    assert(n);
    --n;
    if(!--q.front().nd) q.pop_front();
  }
  void push(T x){
    int k = 0;
    for(; !q.empty() && x >= q.back().st; q.pop_back()) k += q.back().nd;
    q.push_back(P(x, k + 1));
    ++n;
  }
};

int A[maxn];
ll pd[maxn][maxn];

int main(){
  // freopen("in","r",stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  int n, k, x;
  cin >> n >> k >> x;
  for(int i = 0; i < n; ++i){
    cin >> A[i];
    pd[1][i] = i < n - k ? -infl : A[i];
  }
  for(int i = 2; i <= x; ++i){
    MaxQueue<ll> q;
    pd[i - 1][n] = 0;
    for(int j = n - 1; j >= 0; --j){
      q.push(pd[i - 1][j + 1]);
      if(q.size() > k) q.pop();
      pd[i][j] = A[j] + q.front();
      // cerr << " >> " << i << ' ' << j << ' ' << pd[i][j] << '\n';
    }
  }
  ll ans = 0;
  for(int i = 0; i < k; ++i){
    ans = max(ans, pd[x][i]);
  }
  if(!ans){
    ans = -1;
  }
  cout << ans << '\n';
  return 0;
}
