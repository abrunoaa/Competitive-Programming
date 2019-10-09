#include<bits/stdc++.h>
using namespace std;

int n;
int ans[20];
char c[20];
bool can[20];
int l[20],r[20];
void brute(int i, int last){
  // cout << i << '\n';
  if(i == n) {
    for(int j = 0 ; j < n ; ++j){
      cout << ans[j] << " " << c[j] << '\n';
    }
    exit(0);
  }
  else{
    for(int j = 0 ; j < n ; ++j){
      if(can[j]){
        can[j] = false;
        ans[i] = j+1;
        if(last == l[j]){
          c[i] = 'a';
          brute(i+1,r[j]);
        }
        if(last == r[j]){
          c[i] = 'b';
          brute(i+1,l[j]);
        }
        can[j] = true;
      }
    }
  }
}


int main(){
  // freopen("hin","r",stdin);
  cin.sync_with_stdio(0);
  cin.tie(0);
  cout.tie();

  cin >> n;
  memset(can,1,sizeof can);
  set<int> st;
  for(int i = 0; i < n ; ++i){
    cin >> l[i] >> r[i];
    st.insert(l[i]);
    st.insert(r[i]);
  }
  for(auto i : st){
    brute(0,i);
  }
  return 0;
}
