#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5+100;
int x[maxn],y[maxn];
// bool mark[maxn];
#define xx first
#define yy second

typedef pair<long double,long double> pt;

long double get(long double x0,long double y0,long double x1,long double y1,long double h){
  return (+(y0*x1)+(x0*h)+(h*x1)+(x0*y1) ) / (y0-y1);
}

vector<pt> make1(int l, int r){
  vector<pt> v;
  for(int i = l ; i < r ; ++i){
    v.push_back(pt(x[i],y[i]));
  }
  v.push_back(pt(get(x[r],y[r],x[r-1],y[r-1],y[l]),y[l]));
  v.push_back(pt(x[l],y[l]));
  return v;
}

vector<pt> make2(int l, int r){
  vector<pt> v;
  for(int i = r ; i > l ; --i){
    v.push_back(pt(x[i],y[i]));
  }
  v.push_back(pt(get(x[l],y[l],x[l+1],y[l+1],y[r]),y[r]));
  v.push_back(pt(x[r],y[r]));
  return v;
}


long double area(vector<pt> P){
  long double A = 0.0,x1,y1,x2,y2;
  for(int i = 0 ; i < (int)P.size()-1 ; ++i){
    x1 = P[i].xx; x2 = P[i+1].xx;
    y1 = P[i].yy; y2 = P[i+1].yy;
    A += (x1*y2 - x2*y1);
  }
  return fabs(A);
}


int main(){
  freopen("fin","r",stdin);

  // cin.sync_with_stdio(0);
  // cin.tie(0);
  // cout.tie(0);

  int n;
  cin >> n;
  for(int i = 0 ; i < n ; ++i) cin >> x[i] >> y[i];

  int i = 0, j = 0;
  long double ans = 0;
  while(n > i){
    j = i+1;
    cerr << "A" << '\n';
    while( n > j && y[i] > y[j]){
      j++;
    }
    if(n > j && j-i+1 >= 3){
      cout <<" ## " << i << " " << j << "\n";
      ans += area(make1(i,j));
    }
    i = j;
  }

  i = n-1;
  while(i >= 0){
    j = i-1;
    cerr << "B" << '\n';
    while( j >= 0 && y[i] > y[j]){
      j--;
    }
    if(j >= 0 && y[i] != y[j] && i-j+1 >= 3){

      cout <<" ## " << j << " " << i << "\n";
      ans += area(make2(j,i));
    }
    i = j;
  }

  cout << ans/2.0 << '\n';

  return 0;
}
