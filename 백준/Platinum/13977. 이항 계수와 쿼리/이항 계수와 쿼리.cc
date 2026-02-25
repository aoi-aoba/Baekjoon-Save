// 이항 계수와 쿼리

#include <bits/stdc++.h>
#define ll long long
#define fastio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

const ll MAX = 4000001;
const ll MOD = 1000000007;
ll m, n, r, facts[MAX + 1];

ll mod_pow(ll base, ll exp) {
    ll res = 1;
    base %= MOD;
    while (exp > 0) {
        if (exp & 1 == 1)
            res = (res * base) % MOD;
        base = (base * base) % MOD;
        exp >>= 1;
    }
    return res;
}

void pre_facts() {
    facts[0] = facts[1] = 1;
    for (int i = 2; i <= MAX; i++)
        facts[i] = (facts[i - 1] * i) % MOD;
}

ll combine_mod(ll n, ll r) {
    if (r > n) return 0;
    return facts[n] * mod_pow(facts[r], MOD - 2) % MOD *
        mod_pow(facts[n - r], MOD - 2) % MOD;
}

int main(void) {
    fastio();

    cin >> m;
    pre_facts();

    while (m--) {
        cin >> n >> r;
        cout << combine_mod(n, r) << '\n';
    }

    return 0;
}