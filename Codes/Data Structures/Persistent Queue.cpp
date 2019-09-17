const int maxn = 100003;
const int maxr = 100003;                // nº de versões
const int maxl = (int)log2(maxn) + 1;

template<class T> struct Queue {
  struct Node {
    T x;
    int n;
    Node* p[maxl];
    Node() : x(), n(0), p{} {}
    Node(const T &t, int sz, Node* p0) : x(t), n(sz) {
      p[0] = p0;
      for (int i = 1; i < maxl; ++i) p[i] = !p[i - 1] ? nullptr : p[i - 1]->p[i - 1];
    }
  };

  int nv;
  vector<Node> tail;    // tail de cada versão

  Queue() : nv(0), tail(maxr) {}  // DEVE alocar todo espaço antes de começar

  void push(int v, const T &x) { tail[++nv] = Node(x, tail[v].n + 1, &tail[v]); }
  void pop(int v) {
    memcpy(&tail[++nv], &tail[v], sizeof(Node));
    --tail[nv].n;
  }
  const T &front(int v) {
    Node* r = &tail[v];
    assert(r);
    for (int i = maxl - 1, up = r->n - 1; i >= 0; --i)
      if (up & (1 << i))
        r = r->p[i];
    return r->x;
  }
};
