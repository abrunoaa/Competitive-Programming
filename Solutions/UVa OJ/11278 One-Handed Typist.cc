#include <bits/stdc++.h>
using namespace std;

const char* qwerty = {"`1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./ ~!@#$%^&*()_+QWERTYUIOP{}|ASDFGHJKL:\"ZXCVBNM<>?\n"};
const char* dvorak = {"`123qjlmfp/[]456.orsuyb;=\\789aehtdck-0zx,inwvg' ~!@#QJLMFP?{}$%^>ORSUYB:+|&*(AEHTDCK_)ZX<INWVG\"\n"};

int main()
{
  map<char,char> convert;
  for (int i = 0; qwerty[i]; ++i) convert[qwerty[i]] = dvorak[i];

  char c;
  while (scanf("%1c", &c) == 1) printf("%c", convert[c]);

  return 0;
}
