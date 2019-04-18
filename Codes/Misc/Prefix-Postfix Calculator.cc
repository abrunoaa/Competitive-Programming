/// codigo com erro

char prec[128];     // nível de preferência

void build(){
  prec['('] = prec[')'] = 0;
  prec['+'] = prec['-'] = 1;
  prec['*'] = prec['/'] = 2;
}

bool isop(char c){ return c == '+' || c == '-' || c == '*' || c == '/'; }

string postfix(string s){
  string r, op;
  for(char c : s){
    if(isop(c)){
      for(; !op.empty() && prec[(int)op.back()] >= prec[(int)c]; op.pop_back())
        r.push_back(op.back());
      op.push_back(c);
    }
    else if(isdigit(c)) r.push_back(c);
    else if(c == '(') op.push_back('(');
    else if(c == ')'){
      for(; op.back() != '('; op.pop_back()) r.push_back(op.back());
      op.pop_back();
    }
  }
  for(; !op.empty(); op.pop_back()) r.push_back(op.back());
  return r;
}

string prefix(string s){
  string r, op;
  for(int i = s.size() - 1; i >= 0; --i){
    char c = s[i];
    if(isop(c)){
      for(; !op.empty() && prec[(int)op.back()] >= prec[(int)c]; op.pop_back())
        r.push_back(op.back());
      op.push_back(c);
    }
    else if(isdigit(c)) r.push_back(c);
    else if(c == ')') op.push_back(')');
    else if(c == '('){
      for(; op.back() != ')'; op.pop_back()) r.push_back(op.back());
      op.pop_back();
    }
  }
  for(; !op.empty(); op.pop_back()) r.push_back(op.back());
  reverse(r.begin(), r.end());
  return r;
}

// s = postfix; (prefix: percorre da direita para esquerda e troca x com y)
int eval(string s){
  vector<int> r;
  for(char c : s){
    if(isdigit(c)) r.push_back(c - '0');
    else{
      int x = r.back(); r.pop_back();
      int y = r.back(); r.pop_back();
      int ans = c == '+' ? x + y : c == '-' ? x - y : c == '*' ? x * y : x / y;
      r.push_back(ans);
    }
  }
  return r.back();
}
