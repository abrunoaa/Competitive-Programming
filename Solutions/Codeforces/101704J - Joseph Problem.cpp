#include <bits/stdc++.h>
using namespace std;


int f(int i, int k)
{
  if(i == 1) return 0;
  return (f(i-1,k) + k)%i;
}

int main()
{
  int n,k;
  cin>>n>>k;
  cout<<f(n,k)+1<<endl;
}
