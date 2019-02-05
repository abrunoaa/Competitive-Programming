#include <bits/stdc++.h>
using namespace std;

#define maxn 50000  // sqrt(2^31)

typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

bitset<maxn> isp;
vi pr;

void build(){
  isp.set();
  isp[0] = isp[1] = 0;
  for(int i = 2; i < maxn; ++i){
    if(isp[i]){
      pr.push_back(i);
      for(int j = 2 * i; j < maxn; j += i){
        isp[j] = 0;
      }
    }
  }
}

void printFactors(int n){
  bool flag = 0;
  auto print = [&flag](int x){
    cout << (flag ? " x " : " ") << x;
    flag = 1;
  };

  if(n < 0){
    print(-1);
    n *= -1;
  }
  for(int p : pr){
    if(p * p > n){
      break;
    }
    while(n % p == 0){
      n /= p;
      print(p);
    }
  }
  if(n > 1){
    print(n);
  }
  cout << '\n';
}

int main(){
  build();

  int g;
  while(cin >> g && g){
    cout << g << " =";
    printFactors(g);
  }

  return 0;
}
