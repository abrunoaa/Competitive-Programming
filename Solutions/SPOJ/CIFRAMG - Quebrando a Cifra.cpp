#include <bits/stdc++.h>
using namespace std;

#define maxn 4000010

typedef long long ll;

ll bit[maxn];

void upd(int i, ll x) {
  for (++i; i < maxn; i += i & -i) {
    bit[i] += x;
  }
}

ll qry(int i) {
  ll s = 0;
  for (++i; i; i -= i & -i) {
    s += bit[i];
  }
  return s;
}

int main() {
  // freopen("in","r",stdin);
  ios::sync_with_stdio(0), cin.tie(0);

  int n;
  while (cin >> n && n) {
    memset(bit, 0, sizeof bit);
    cout << "MENSAGEM: [";

    bool finished = 0;
    for (int i = 0; i < n; ++i) {
      int op;
      cin >> op;

      if (finished) {
        continue;
      }
      if (op == 0) {
        finished = true;
      } else if (op == 18) {
        int a, b, x;
        cin >> a >> b >> x;
        i += 3;
        upd(a, +x);
        upd(b + 1, -x);
      } else {
        int p;
        cin >> p;
        i += 1;
        ll x = qry(p) - qry(p - 1);
        cout << (char)(x < 0 ? ' ' : x % 26 + 'A');
      }
    }
    cout << "]\n";
  }

  return 0;
}
