#include <bits/stdc++.h>
#define ll long long
#define fastio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MOD 1000000007
using namespace std;

ll power_inv(ll n){
    ll ret = 1, m = MOD - 2;
    while (m){
        if (m & 1) ret = ret * n % MOD;
        m = m / 2;
        n = n * n % MOD;
    }
    return ret;
}

int M, n, s;

int main() {
    fastio();
    cin >> M;
    ll answer = 0;

    while (M--) {
        cin >> s >> n;
        answer += (n * (power_inv(s))) % MOD;
    }

    cout << answer % MOD;
    return 0;
}