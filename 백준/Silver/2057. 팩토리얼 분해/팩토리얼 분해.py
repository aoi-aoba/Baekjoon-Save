import sys
input = sys.stdin.readline

def fact(n):
    if n == 0:
        return 1
    else:
        return n * (fact(n-1))

fac_num = [fact(i) for i in range(21)]

n = int(input())

if n == 0:
    print('NO')
else:
    for i in range(20, -1, -1):
        if n >= fac_num[i]:
            n -= fac_num[i]
    print("YES" if n == 0 else "NO")