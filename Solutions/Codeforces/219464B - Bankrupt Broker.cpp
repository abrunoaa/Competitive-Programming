#include <bits/stdc++.h>
using namespace std;
typedef long long ll ;
typedef pair<int,int> ii;
#define maxn 300

ll f1,a,b,mod,m,n;
map<ll,int> id;
vector<ii> p;

int main()
{
  //~ freopen("in","r",stdin);
  scanf("%lld%lld%lld%lld%lld%lld",&f1,&a,&b,&mod,&m,&n);
  for(int i = 0 ; i < m;i++)
  {
    for(int j = 0; j < n;j++){

      ll num;
      scanf("%lld",&num);

      if(id.find(num) == id.end())
      {
        p.push_back(ii(1,num));
        id[num] = p.size()-1;
      }
      else
      {
        p[id[num]].first++;
      }
    }
  }


  ii price[p.size()];
  price[0] = ii(f1,0);

  for(int i = 1; i < (int)p.size();i++)
    price[i] = ii((a*price[i-1].first + b) % mod + 1,i);

  sort(p.begin(),p.end());
  sort(price,price+p.size());

  vector<ll> resp(p.size());

  for(int i = (int)p.size()-1; i >= 0 ;i--)
    resp[price[i].second] = p[i].second;

  cout<<p.size()<<endl;

  for(int i = 0; i < (int)p.size();i++){
    if(i) cout<<' ';
    cout<<resp[i];
  }
  cout<<endl;
}
