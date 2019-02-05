#include <iostream>
#include <map>
using namespace std;

string post(const string& a){
  static map<char,int> p = {{'(',0}, {'+',1}, {'-',1}, {'*',2}, {'/',2}};
  string b, op;
  for(char c : a)
    if(isalpha(c)) b.push_back(c);// assume que cada n° tem 1 dígito
    else if(c == '(') op.push_back(c);
    else if(c == ')'){
      for(; op.back() != '('; op.pop_back()) b.push_back(op.back());
      op.pop_back();
    }
    else{
      for(; !op.empty() && p[op.back()] >= p[c]; op.pop_back()) b.push_back(op.back());
      b.push_back(c);
    }
  for(; !op.empty(); op.pop_back()) b.push_back(op.back());
  return b;
}

int main(){
  return 0;
}