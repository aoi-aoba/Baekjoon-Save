// huge numbers
#include <bits/stdc++.h>
#define fastio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
using namespace std;

ll t, a, n, p;

ll Pow(ll base, ll exp, ll mod) {
    ll ret = 1;
    base %= mod;
    while (exp) {
        if (exp & 1) ret = (ret * base) % mod;
        base = (base * base) % mod;
        exp /= 2;
    }
    return ret;
}

void solve(int caseN) {
    cin >> a >> n >> p;
    ll cur = a % p;
    for (int i = 2; i <= n; ++i) {
        cur = Pow(cur, i, p);
        if (cur == 0) break;
    }

    cout << "Case #" << caseN << ": " << cur << "\n";
}

int main(void) {
    fastio();
    cin >> t;
    for (int i = 1; i <= t; i++) solve(i);
    return 0;
}