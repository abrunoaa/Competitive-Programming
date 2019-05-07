/// Baby-step Giant-step

typedef long long ll;

int mpow(int b, int e, int m){
  int x = 1;
  while(e){
    if(e % 2) x = (ll)x * b % m;
    e /= 2;
    b = (ll)b * b % m;
  }
  return x;
}

// retorna {x | a^x = b (mod m) ou -1 se não existir}, m é primo
int baby(int a, int b, int m){          // O(sqrt(m))
  assert(a < m && b < m);

  int n = (int)ceil(sqrt(m));
  int an = mpow(a, n, m);

  map<int,int> vals;
  for(int i = 1, cur = an; i <= n; ++i){
    if(!vals.count(cur)) vals[cur] = i;
    cur = (ll)cur * an % m;
  }

  for(int i = 0, cur = b; i <= n; ++i){
    if(vals.count(cur)){
      int ans = vals[cur] * n - i;
      if(ans < m) return ans;
    }
    cur = (ll)cur * a % m;
  }

  return -1;
}
