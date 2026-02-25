import sys
input = sys.stdin.readline

MAX = 4000001
MOD = 1000000007
facts = [1, 1]

def mod_pow(base, exp):
    res = 1
    base %= MOD
    while exp > 0:
        if exp & 1 == 1:
            res = (res * base) % MOD
        base = (base ** 2) % MOD
        exp >>= 1
    return res

def mod_inverse(n):
    return mod_pow(n, MOD - 2)

def pre_facts():
    for i in range(2, MAX):
        facts.append((facts[i - 1] * i) % MOD)

def combine_mod(n, r):
    if r > n:
        return 0
    return facts[n] * mod_inverse(facts[r]) % MOD * mod_inverse(facts[n - r]) % MOD

m = int(input())
pre_facts()
for _ in range(m):
    n, r = map(int, input().split())
    print(combine_mod(n, r))