#include <bits/stdc++.h>
#define fastio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
#define fr first
#define sc second
using namespace std;

ll gcd(ll i, ll j) {
	if (i < j) swap(i, j);
	while (j > 0) {
		int r = i % j;
		i = j;
		j = r;
	}
	return i;
}

int main() {
	fastio();

	ll A, B, j = 0;
	cin >> A >> B;
	pair<ll, ll> res;

    // A의 배수 반복 (적어도 A는 약수)
	for (ll i = A; i * i <= A * B; i += A) {
        // 나누어떨어지지 않으면 j가 소수점이 되므로 제외
		if (A * B % i != 0) continue;
        j = A * B / i;
		
        // 정말 최대공약수가 맞는지 확인
        if (gcd(i, j) != A) continue;

		if (i == A) {
			res.fr = i, res.sc = j;
			continue;
		}

		if (i + j < res.fr + res.sc)
			res.fr = i, res.sc = j;
	}
	cout << res.fr << " " << res.sc << '\n';
}