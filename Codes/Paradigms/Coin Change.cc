#include <iostream>
#include <algorithm>
using namespace std;

#define maxn 101
#define maxm 1000001
#define inf 0x3f3f3f3f

int n;
int v[maxn];
int mem[maxm];

void coinChange(){
  mem[0] = 0;
  for(int c = 1; c < maxm; ++c){
    auto& dp = mem[c] = inf;
    for(int i = 0; i < n; ++i)
      if(c >= v[i])
        dp = min(dp, mem[c - v[i]] + 1);
  }
}

/// testes
int main(){
  n = 4;
  v[0] = 1;
  v[1] = 3;
  v[2] = 4;
  v[3] = 5;
  coinChange();
  for(int c = 0; c <= 20; ++c)
    cout << c << " = " << mem[c] << " coins\n";
  return 0;
}