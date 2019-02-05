#include <bits/stdc++.h>
using namespace std;

string roman(int n){
  static map<int,string,bool(*)(int,int)> m({{1,"I"}, {4,"IV"}, {5,"V"}, {9,"IX"}, {10,"X"},
  {40,"XL"}, {50,"L"}, {90,"XC"}, {100,"C"}, {400,"CD"}, {500,"D"}, {900,"CM"}, {1000,"M"}},
    [](int x, int y){ return x > y; });

  string ans;
  for(auto& x : m)
    while(n >= x.first){
      n -= x.first;
      ans += x.second;
    }
  return ans;
}

int arabic(string s){
  static map<char,int> m = {
    {'\0',0}, {'I',1}, {'V',5}, {'X',10}, {'L',50}, {'C',100}, {'D',500}, {'M',1000}};

  int x = 0;
  for(int i = 0; s[i]; ++i)
    if (m[s[i]] < m[s[i + 1]]){
      x += m[s[i + 1]] - m[s[i]];
      ++i;
    }
    else{
      x += m[s[i]];
    }

  return x;
}


int main(){
  // freopen("in","r",stdin);
  cin.sync_with_stdio(0), cin.tie(0);

  string s;
  while(cin >> s){
    if(isdigit(s[0])){
      cout << roman(stoi(s)) << '\n';
    }
    else{
      cout << arabic(s) << '\n';
    }
  }

  return 0;
}
