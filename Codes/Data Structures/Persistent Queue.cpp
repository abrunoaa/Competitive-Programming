#define maxn 100003
#define maxr maxn   // nº de versões
#define maxl 17     // log2(maxn)

template<class T> struct Queue {
  struct Node {
    T x;
    int n;
    Node* p[lg(maxn)];
    Node() {}
    Node(const T &x, Node* p0) : x(x) {
      p[0] = p0;
      for (int i = 1; i < maxl; ++i) { p[i] = !p[i - 1] ? 0 : p[i - 1]->p[i - 1]; }
    }
  };

  int nv;           // nº de versões (versão 0 é flag)
  Node* back[maxr]; // tail de cada versão

  void push(int v, const T &x) { back[++nv] = new Node(x, back[v]); }
  void pop(int v) {
    memcpy(back[++nv], back[v], sizeof(Node));
    --back[nv]->n;
  }
  const T &front(int v) {
    Node* r = back[v];
    int up = r->n - 1;
    for (int i = maxl - 1; i >= 0; --i)
      if ((up >> i) & 1) {
        r = r->p[i];
      }
    return r->x;
  }
};
