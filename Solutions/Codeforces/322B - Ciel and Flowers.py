r,g,b = map(int, input().split())
print(max((r - i) // 3 + (g - i) // 3 + (b - i) // 3 + i if i <= min(r,g,b) else 0 for i in range(3)))
