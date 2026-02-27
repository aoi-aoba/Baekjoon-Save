s = str(input().rstrip())
ans = [0, 0]

target = s[0]
for idx in range(1, len(s) - 1):
    if target != s[idx]:
        ans[int(target) - 0] += 1
        target = s[idx]

if target == s[-1]:
    ans[int(target) - 0] += 1

else:
    ans[0] += 1
    ans[1] += 1

print(min(ans))