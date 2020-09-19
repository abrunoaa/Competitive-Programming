for t in range(int(input())):
    a, b = map(int, input().split())
    print("Tuzik" if a * b % 2 == 0 else "Vanka")
