#define maxn 100003
#define maxr maxn   // nº de versões

template<class T> struct Stack{
  struct Node{
    T x;
    Node* next;
    Node(){}
    Node(const T& x, Node* next) : x(x), next(next) {}
  };

  int nv;           // nº de versões (versão 0 é flag)
  Node* root[maxr]; // raízes de cada versão

  Stack() : nv(0) { root[0] = 0; }

  void push(int v, const T& x){ root[++nv] = new Node(x, root[v]); }
  void pop(int v){ root[++nv] = root[v]->next; }
  const T& top(int v) const { return root[v]->x; }
};
