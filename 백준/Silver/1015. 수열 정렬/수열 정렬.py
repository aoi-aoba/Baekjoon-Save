import sys
input = sys.stdin.readline

n = int(input())
arr = [int(i) for i in input().rstrip().split()]
p = []
for i in range(n):
    p.append(0)
num, cnt = 1, 0

for j in range(1000):
    for i in range(n):
        if arr[i] == num:
            p[i] = cnt
            cnt += 1
    num += 1
print(' '.join(map(str, p)))