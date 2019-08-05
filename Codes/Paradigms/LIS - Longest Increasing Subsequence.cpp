#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
using namespace std;

#define maxn 1010 // para os testes

/// lis O(n lg n)
#define lbound(vec, x) (lower_bound(vec.begin(), vec.end(), x) - vec.begin())

int n;// n números
int a[maxn];// vetor

int lis() {
  vector<int> ans = {a[0]};
  for (int i = 1; i < n; ++i)
    if (a[i] > ans.back()) {
      ans.push_back(a[i]);
    } else {
      ans[lbound(ans, a[i])] = a[i];
    }
  return ans.size();
}

/// lis com reconstrução
#define st first
#define nd second

typedef pair<int, int> ii;

int b[maxn];// memória para reconstruir
ii ft[maxn];

void rec(int i) {
  if (i < 0) { return; }
  rec(b[i]);
  // cout << a[i] << ' ';
  assert(b[i] == -1 || a[b[i]] < a[i]);
}

void upd(int i, ii x) {
  for (; i < maxn; i += i & -i) {
    ft[i] = max(ft[i], x);
  }
}

ii qry(int i) {
  ii ans(0, -1);
  for (; i; i -= i & -i) {
    ans = max(ans, ft[i]);
  }
  return ans;
}

ii recLis() {
  memset(ft, -1, sizeof ft);
  ii ans(0, -1);
  for (int i = 0; i < n; ++i) {
    ii x = qry(a[i]);// assume a[i] > 0
    b[i] = x.nd;
    ++x.st;
    x.nd = i;
    ans = max(ans, x);
    upd(a[i] + 1, x);
  }
  return ans;
}

/// testes
int lis_brute() {
  int ans = 0, lis[maxn];
  for (int i = 0, j; i < n; ++i) {
    lis[i] = 1;
    for (j = i - 1; j >= 0; --j)
      if (a[j] < a[i]) {
        lis[i] = max(lis[i], lis[j] + 1);
      }
    ans = max(ans, lis[i]);
  }
  return ans;
}

void test() {
  n = rand() % 1000 + 1;
  int max = 100;
  for (int i = 0; i < n; ++i) {
    a[i] = rand() % max + 1;
    // cout << " >> " << a[i] << '\n';
  }
  int l = lis();
  ii rl = recLis();
  int ans = lis_brute();
  // cout << " == " << ans << " " << l << " " << rl.st << " " << rl.nd << endl;
  assert(ans == l);
  assert(ans == rl.st);
  rec(rl.nd);
}

int main() {
  srand(0);
  int T = 500;
  for (int t = 1; t <= T; ++t) {
    cout << "test " << t << '\n';
    test();
  }
  cout << "all ok!\n";
  return 0;
}