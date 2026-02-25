// 언더프라임

#include <bits/stdc++.h>
#define fastio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

const int MAX = 100000;
bool isPrime[MAX + 1];
int factorCnt[MAX + 1];

// 에라토스테네스의 체를 활용하여 밑작업
void find_prime() {
    fill(isPrime, isPrime + MAX + 1, true);
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i <= MAX; i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= MAX; j += i)
                isPrime[j] = false;
        }
    }
}

// 소인수분해 전처리 함수
void prime_factorization() {
    for (int i = 2; i <= MAX; i++) {
        if (isPrime[i]) {
            for (int j = i; j <= MAX; j += i) {
                int temp = j;
                while (temp % i == 0) {
                    factorCnt[j]++;
                    temp /= i;
                }
            }
        }
    }
}


int main(void) {
    fastio();
    find_prime();
    prime_factorization();

    int a, b;
    cin >> a >> b;

    int ans = 0;
    for (int i = a; i <= b; i++) {
        if (isPrime[factorCnt[i]])
            ans++;
    }

    cout << ans;
    return 0;
}