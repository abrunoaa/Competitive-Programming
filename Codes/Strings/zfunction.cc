/// Z Function

void zfunc(const string& s, int* z){
  int n = s.size();
  // z[0] = 0 ou n;
  for(int i = 1, l = 0, r = 0; i < n; ++i){
    for(z[i] = i > r ? 0 : min(r - i + 1, z[i - l]); i + z[i] < n && s[z[i]] == s[i + z[i]]; ++z[i]);
    if(i + z[i] - 1 > r){
      l = i;
      r = i + z[i] - 1;
    }
  }
}
