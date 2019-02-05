# import sys
# sys.stdin = open('in','r')


maxn = 10 ** 6 + 10


ndpf = [0 for x in range(maxn)]
for i in range(2, maxn):
  if ndpf[i] == 0:
    for j in range(i, maxn, i):
      ndpf[j] += 1


while True:
  n = int(input())
  if n == 0:
    break

  print(n, ':', ndpf[n])
