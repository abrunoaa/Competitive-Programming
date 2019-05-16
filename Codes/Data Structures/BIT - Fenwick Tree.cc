#define maxn 100010

int ft[maxn];

void upd(int i, int x){ // atualiza todos i+ somando x; O(lg n)
  for(; i < maxn; i += i & -i)
    ft[i] += x;
}

int qry(int i){ // retorna a soma de todos i-; O(lg n)
  int s = 0;
  for(; i; i -= i & -i)
    s += ft[i];
  return s;
}
