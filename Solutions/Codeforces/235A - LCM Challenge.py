n = int(input())

if n < 3:   ans = n
elif n % 2: ans = n * (n - 1) * (n - 2)
elif n % 3: ans = n * (n - 1) * (n - 3)
else:       ans = (n - 1) * (n - 2) * (n - 3)

print (ans)
