// 합 구하기
#include <bits/stdc++.h>
#define fastio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
using namespace std;

// S(1, n) = S(0, 1) + S(0, 2) + .. + S(0, n) = n(n+1)/2
// S(2, n) = Sum(i(i+1)/2) for i = 1~n = n(n+1)(n+2)/6
// S(3, n) = Sum((n^3 + 3n^2 + 2n)/6) for i = 1~n = n(n+1)(n+2)(n+3)/24
// So, numerator = n(n+1)(n+2)(n+3)...(n+s), denominator = (n+1)!
// fuck math

ll s, n;
const int mod = 1e9 + 7;

ll Pow(ll base, ll exp) {
    ll ret = 1;
    while (exp) {
        if (exp & 1) ret = ret * base % mod;
        base = base * base % mod;
        exp >>= 1;
    }
    return ret;
}

ll mod_inv(ll a) {
    return Pow(a, mod - 2);
}

int main(void) {
    fastio();
    cin >> s >> n;

    ll nrt = 1, dnt = 1;
    for (int i = 0; i <= s; i++)
        nrt = nrt * (n + i) % mod;
    for (int i = 1; i <= s + 1; i++)
        dnt = dnt * i % mod;

    cout << nrt * mod_inv(dnt) % mod;
    return 0;
}