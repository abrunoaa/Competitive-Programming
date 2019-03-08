a = input().split()
s = 0
for i in range(int(a[0])):
  s += (i + 1) * int(a[i + 1])
print(s)
