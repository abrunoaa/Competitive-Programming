#define putc(c) putc((c), stdout)

struct IO{
  char cur, buf[100];
  IO() : cur(' ') {}

  inline operator bool(){ return cur; }

  inline void readc(){ cur = getc(stdin); }
  inline bool isblank(){ return cur <= ' '; }
  inline bool isdigit(){ return (unsigned char)(cur - '0') <= 9; }
  inline void skipBlanks(){ while(isblank()) readc(); }

  inline IO& operator >> (char &c){ skipBlanks(); c = cur; readc(); return *this; }

  inline IO& operator >> (char *s){
    skipBlanks();
    while(*s++ = cur, readc(), !isblank());
    *s = 0;
    return *this;
  }

  inline IO& operator >> (string &s){
    s.clear();
    skipBlanks();
    while(s.push_back(cur), readc(), !isblank());
    return *this;
  }

  inline IO& operator >> (double &d){ if(*this >> buf) sscanf(buf, "%lf", &d); return *this; }
  inline IO& operator >> (long double &d){ if(*this >> buf) sscanf(buf, "%Lf", &d); return *this; }

  template<class intType>
  inline IO& operator >> (intType &n){
    skipBlanks();
    int sign = +1;
    if(cur == '-') sign = -1, readc();
    else if(cur == '+') readc();
    n = cur - '0';
    while(readc(), isdigit()) n += n + (n << 3) + cur - '0';
    n *= sign;
    return *this;
  }

  inline IO& operator << (bool x){ putc((x ? '1' : '0')); return *this; }
  inline IO& operator << (char c){ putc(c); return *this; }
  inline IO& operator << (char *s){ while(*s) putc(*s++); return *this; }
  inline IO& operator << (const char *s){ while(*s) putc(*s++); return *this; }
  inline IO& operator << (const string &s){ return *this << s.data(); }

  inline char* toString(double d){ sprintf(buf, "%.9lf%c", d, '\0'); return buf; }
  inline char* toString(long double d){ sprintf(buf, "%.9Lf%c", d, '\0'); return buf; }

  template<class intType>
  char* toString(intType n){
    char* p = buf + 99;
    *p = 0;
    if(!n) *--p = '0';
    else{
      bool neg;
      if((neg = n < 0)) n = -n;
      while(n) *--p = n % 10 + '0', n /= 10;
      if(neg) *--p = '-';
    }
    return p;
  }

  template<class T> inline IO& operator << (T x){ return *this << toString(x); }
};

static IO __io__;

#define endl '\n'
#define cout __io__
#define cin __io__
