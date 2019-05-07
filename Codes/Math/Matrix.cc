// Matriz

typedef vector<vector<int>> matrix;

// retorna a[n,m] * b[m,p]
matrix operator * (const matrix& a, const matrix& b){
  int n = a.size();
  int m = b.size();
  int p = b[0].size();
  matrix c;
  c.resize(n);
  for(int i = 0; i < n; ++i){
    c[i].assign(p, 0);
    for(int j = 0; j < p; ++j)
      for(int k = 0; k < m; ++k)
        c[i][j] += a[i][k] * b[k][j];       // tirar mod aqui!
  }
  return c;
}

// retorna b[n,n] ** e
matrix pow(matrix b, int e){
  matrix x(n);
  for(int i = 0; i < n; ++i){
    x[i].assign(n, 0);
    x[i][i] = 1;
  }
  while(1){                   // fastExp normal
    if(e % 2) x = x * b;
    if(!(e /= 2)) return x;
    b = b * b;
  }
}

// retorna matriz transposta de a
matrix transpose(const matrix& a){
  int n = a[0].size();  // n colunas em a
  int m = a.size();     // m linhas em a
  matrix t(n);

  for(int i = 0; i < n; ++i){
    t[i].resize(m);
    for(int j = 0; j < m; ++j)
      t[i][j] = a[j][i];
  }
  return t;
}

// retorna fib(n) ==> fib(0) = 0 (i.e. começa a partir do zero)
int nthFib(int n){
  if(n == 0) return 0;
  return pow(matrix{{1,1},{1,0}}, n - 1)[0][0];
}

void print(const matrix& a){
  for(int i = 0; i < (int)a.size(); ++i){
    for(int j = 0; j < (int)a[0].size(); ++j){
      cout << a[i][j] << ' ';
    }
    cout << '\n';
  }
}
