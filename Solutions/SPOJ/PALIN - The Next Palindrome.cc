#include <bits/stdc++.h>
using namespace std;

int main(){
  // freopen("in","r",stdin);
  ios::sync_with_stdio(0), cin.tie(0);

  int t;
  cin >> t;

  string n;
  while(t--){
    cin >> n;
    int len = n.size();

    bool changed = 0;
    for(int i = (n.size() - 1) / 2; i >= 0; --i){
      int j = len - i - 1;

      if(changed){
        n[j] = n[i];
      }
      else if(n[i] > n[j]){
        n[j] = n[i];
        changed = 1;
      }
      else if(n[i] < n[j]){
        int k;
        for(k = (n.size() - 1) / 2; k > i; --k){
          int r = len - k - 1;
          if(n[k] != '9'){
            if(k != r) ++n[r];
            ++n[k];
            break;
          }
          else{
            n[k] = n[r] = '0';
          }
        }
        if(k == i){
          ++n[i];
        }
        n[j] = n[i];
        changed = 1;
      }
    }

    if(!changed){
      int i;
      for(i = (n.size() - 1) / 2; i >= 0; --i){
        int j = len - i - 1;
        if(n[i] != '9'){
          if(i != j) ++n[j];
          ++n[i];
          break;
        }
        else{
          n[i] = n[j] = '0';
        }
      }
      if(i < 0){
        n = "1" + string(n.begin(), n.end() - 1) + "1";
      }
    }

    cout << n << '\n';
  }

  return 0;
}
