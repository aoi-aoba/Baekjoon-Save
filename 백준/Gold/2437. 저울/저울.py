# 저울

import sys
input = sys.stdin.readline

n = int(input())
arr = sorted([int(item) for item in input().strip().split()])

# 현재까지의 추로 1~sum을 만들 수 있다면, 다음 추 x > sum + 1이면 못 만들고 아니면 확장 가능
# 그 확장 가능성은 x <= sum + 1에 대하여 1~sum+x까지 확장 가능

sum = 0
for item in arr:
    if sum + 2 <= item:
        break
    sum += item
print(sum + 1)