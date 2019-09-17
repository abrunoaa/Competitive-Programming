#define torad(x) (pi / 180.0 * (x))
#define todeg(x) (180.0 / pi * (x))

typedef long double lf;

const lf pi = acos(-1.0);
const lf eps = 1e-9;

inline int cmp(lf x, lf y = 0.0) { return (abs(x - y) < eps ? 0 : x < y ? -1 : 1); }
