/// Algoritmo de Mo

#define maxn 100010
#define maxm 100010

struct Qry{ int l, r, id; };

int cur, ans[maxm];
int n, m, v[maxn];
Qry q[maxm];

/* adiciona/remove um elemento e atualiza a resposta */
void add(int){}
void rem(int){}

void mo(){
  int bs = sqrt(n);
  sort(q, q + m, [bs](const Qry& x, const Qry& y){
    int bx = x.l / bs, by = y.l / bs;
    if(bx != by) return bx < by;
    return bx % 2 == 0 ? x.r < y.r : x.r > y.r;
  });

  int mol = 0, mor = -1;
  for(int i = 0; i < m; ++i){
    int l = q[i].l;
    int r = q[i].r;
    int id = q[i].id;

    while(mor < r) add(++mor);
    while(mor > r) rem(mor--);
    while(mol < l) rem(mol++);
    while(mol > l) add(--mol);

    ans[id] = cur;  // resposta para o intervalo atual O(1)
  }
}
