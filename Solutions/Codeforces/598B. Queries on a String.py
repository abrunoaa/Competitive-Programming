s = input()
for q in range(int(input())):
  l, r, k = map(int, input().split())
  l -= 1
  k %= r - l
  s = s[: l] + s[r - k: r] + s[l: r - k] + s[r:]
print(s)
