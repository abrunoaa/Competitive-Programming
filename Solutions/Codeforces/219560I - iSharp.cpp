#include<bits/stdc++.h>
using namespace std;

int main()
{
  freopen("isharp.in","r",stdin);
  freopen("isharp.out","w",stdout);

  string a,b,aa;
  cin>>a;
  int f2 = 1;
  while(f2)
  {
    aa = a;
    cin>>b;

    if(b[b.size()-1] == ';') f2 = 0;

    b.pop_back();

    bool flag = 1;

    while(flag)
    {
      for( int i = b.size()-1; i >= 0 ; i--)
      {
        if(tolower(b[i]) >= 'a' && tolower(b[i]) <= 'z'){
          b = string(b.begin(),b.begin()+i+1);
          flag = 0; break;
        }

        if(b[i] == '*' || b[i] == '&')
        {
          aa.push_back(b[i]);
        }
        else
        {
          b.pop_back(); b.pop_back();
          aa += "[]";
          i--;
        }
      }
    }

    cout<<aa<<' '<<b<<';'<<endl;
  }
}
