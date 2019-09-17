struct Qry { int l, r, id; };

const int maxn = 100003;
const int maxq = 100003;

int cur, ans[maxq];
int n, m, v[maxn];
Qry q[maxq];

/* adiciona/remove um elemento e atualiza a resposta */
void add(int) {}
void rem(int) {}

void mo() {
  int bs = (int)sqrt(n);
  sort(q, q + m, [bs](const Qry & x, const Qry & y) {
    int bx = x.l / bs, by = y.l / bs;
    if (bx != by) return bx < by;
    return bx % 2 == 0 ? x.r < y.r : x.r > y.r;
  });
  int mol = 0, mor = -1;
  for (int i = 0; i < m; ++i) {
    int l = q[i].l;
    int r = q[i].r;
    int id = q[i].id;
    while (mor < r) add(++mor);
    while (mor > r) rem(mor--);
    while (mol < l) rem(mol++);
    while (mol > l) add(--mol);
    ans[id] = cur;  // resposta para o intervalo atual O(1)
  }
}
