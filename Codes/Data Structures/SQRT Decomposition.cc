#define maxn 100010

int v[maxn];

int main(){
  int n, q;
  cin >> n >> q;

  int bs = sqrt(n);
  for(int i = 0; i * bs < n; ++i){
    int m = min(n, (i + 1) * bs);
    for(int j = i * bs; j < m; ++j){
      cin >> v[j];
    }
    // calcula resposta do bloco i
  }

  while(q--){
    int l, r;
    cin >> l >> r, --l, --r;

    int bl = l / bs, br = r / bs;       // bloco de l e de r
    if(bl == br){
      for(int i = l; i <= r; ++i)
        // calcula resposta com força bruta entre l e r
    }
    else{
      for(int i = bl + 1; i < br; ++i)
        // pega resposta dos blocos entre (exclusivo) l e r
      for(int i = l, up = (bl + 1) * bs; i < up; ++i)
        // calcula resposta do bloco da esquerda com força bruta
      for(int i = (br - 1) * bs; i <= r; ++i)
        // calcula resposta do bloco da direita com força bruta
    }
  }

  return 0;
}
