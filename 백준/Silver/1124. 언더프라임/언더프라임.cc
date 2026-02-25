// 언더프라임

#include <bits/stdc++.h>
#define fastio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

int a, b, sieve[101010], ans = 0;

// 에라토스테네스의 체를 활용하여 밑작업
void find_prime() {
    fill(sieve, sieve + 101010, 1);
    sieve[0] = sieve[1] = 0;

    for (int i = 2; i * i < 101010; i++) {
        if (sieve[i]) {
            for (int j = i * i; j < 101010; j += i) {
                sieve[j] = 0;
            }
        }
    }
}

// 소인수분해 함수
int prime_factorization(int n) {
    int cnt = 0;
    if (sieve[n]) return 1; // 소수면
    
    int i = 2;
    while (n > 1) {
        if (n % i == 0) {
            n /= i;
            cnt++;
        } else i++;
    }
    return cnt;
}

int main(void) {
    fastio();
    find_prime();

    cin >> a >> b;
    for (int i = a; i <= b; i++) {
        if (sieve[prime_factorization(i)])
            ans++;
    }

    cout << ans;
    return 0;
}