#include<bits/stdc++.h>
using namespace std;

int main(){

  //freopen("in5", "r", stdin);
  int t;
  cin>>t;

  cout<<setprecision(4)<<fixed;
  while(t--){
    int m1, a1;
    int m2, a2;
    cin>>m1>>a1>>m2>>a2;
    if(a1 == a2){
      cout<<((double)0.5/(12.- m1 + 1 ))*(m2-m1)<<endl;
    }else{
      double y = a2-a1-1;
      double r = 1./12.*(m2-1);
      double l = 0.5;
      cout<<l+y+r<<endl;
    }
  }
}
