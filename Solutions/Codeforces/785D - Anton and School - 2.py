mod = 10 ** 9 + 7

s = input()
n = len(s)

f = [1] * (n + 1)
for i in range(1, n + 1): f[i] = i * f[i - 1] % mod
finv = [pow(x, mod - 2, mod) for x in f]

op = 0
cl = s.count(')')
ans = 0
if cl > 0:
  for c in s:
    if c == '(':
      op += 1
      ans += f[op + cl - 1] * finv[cl - 1] * finv[op]
    elif cl <= 1:
      break
    else:
      cl -= 1
print(ans % mod)

#bruno