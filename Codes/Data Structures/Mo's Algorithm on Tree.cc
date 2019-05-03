struct Qry{ int i, j, w, id; };

void dfs(int u = 1, int p = 0){         // vetoriza a árvore (na entrada e na saída)
  in[u] = cnt;
  order[cnt] = u;                       /// lembrar de declarar com 2*n posições!
  ++cnt;
  for(int v : g[u])
    if(v != p)
      dfs(v, u);
  out[u] = cnt;
  order[cnt] = u;
  ++cnt;
}

void update(int u){
  u = order[u];     // pega o vértice correspondente
  used[u] ^= 1;     // insere/remove
  if(used[u])
    // insere u na resposta
  else
    // remove u da resposta
}

void mo(){
  int bs = (int)sqrt(2 * n);
  sort(q, q + m, [bs](const Qry& x, const Qry& y){
    int bx = x.i / bs, by = y.i / bs;
    return (bx != by ? bx < by : bx % 2 == 0 ? x.j < y.j : x.j > y.j);
  });

  int l = 0, r = -1;
  for(int k = 0; k < m; ++k){
    int i = q[k].i;
    int j = q[k].j;
    int w = q[k].w;
    int id = q[k].id;

    while(r < j) update(++r);
    while(r > j) update(r--);
    while(l < i) update(l++);
    while(l > i) update(--l);

    if(w != -1) update(w);
    ans[id] = cur;
    if(w != -1) update(w);
  }
}

int main(){
  dfs();
  for(int i = 0; i < m; ++i){                     // lê as consultas
    int u, v;
    cin >> u >> v;
    int w = lca(u, v);
    if(in[u] > in[v]) swap(u, v);
    if(w == u) q[i] = { in[u], in[v], -1, i };    // caso especial
    else q[i] = { out[u], in[v], in[w], i };
  }

  mo();
  for(int i = 0; i < m; ++i) cout << ans[i] << '\n';
  return 0;
}
