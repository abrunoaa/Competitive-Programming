typedef double lf;

struct cp{
  lf a, b;

  inline lf real() const { return a; }
  inline lf imag() const { return b; }

  cp operator + (const cp& x) const { return {a + x.a, b + x.b}; }
  cp operator - (const cp& x) const { return {a - x.a, b - x.b}; }
  cp operator * (const cp& x) const { return {a * x.a - b * x.b, a * x.b + b * x.a}; }
  cp operator / (lf d) const { return {a / d, b / d}; }

  cp& operator += (const cp& x){
    a += x.a;
    b += x.b;
    return *this;
  }

  cp& operator -= (const cp& x){
    a -= x.a;
    b -= x.b;
    return *this;
  }

  cp& operator *= (const cp& x){ return (*this = *this * x); }

  cp& operator /= (lf d){
    a /= d;
    b /= d;
    return *this;
  }
};
