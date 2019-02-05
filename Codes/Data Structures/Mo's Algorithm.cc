/// Algoritmo de Mo

#define maxn 100010
#define maxq 100010

struct qry_t{
  int l, r, id;
};

int cur;
int n, q, v[maxn], ans[maxq];
qry_t qry[maxq];

/* adiciona/remove um elemento e atualiza a resposta */
void add(int){}
void rem(int){}

void mo(){
  int bs = sqrt(n);
  sort(qry, qry + q, [bs](const qry_t& x, const qry_t& y){
    int bx = x.l / bs, by = y.l / bs;
    if(bx != by) return bx < by;
    return bx % 2 == 0 ? x.r < y.r : x.r > y.r;
  });

  int mol = 0, mor = -1;
  for(int i = 0; i < q; ++i){
    int l = qry[i].l;
    int r = qry[i].r;
    int id = qry[i].id;

    while(mor < r) add(++mor);
    while(mor > r) rem(mor--);
    while(mol < l) rem(mol++);
    while(mol > l) add(--mol);

    ans[id] = cur;  // resposta para o intervalo atual O(1)
  }
}
