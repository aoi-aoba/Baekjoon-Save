#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define MOD 1000000007

using namespace std;

int dp[301][1<<18];
int n, m;

int f(int idx, int bit){
    if (idx == n * m) return 1;
    if (dp[idx][bit] != -1) return dp[idx][bit];

    dp[idx][bit] = f(idx + 1, bit >> 1) % MOD;

    if (idx % m == 0)
        dp[idx][bit] += f(idx + 1, (bit >> 1) | (1 << m)) % MOD;
    else {
        if (!(bit & (1 << m)) || !(bit & 2) || !(bit & 1))
            dp[idx][bit] += f(idx + 1, (bit >> 1) | (1 << m)) % MOD;
    }
    return dp[idx][bit] % MOD;
}

int main(void) {
    fastio;
    cin >> n >> m;

    if (n < m) swap(n, m);
    memset(dp, -1, sizeof dp);
    cout << f(0, 0) << '\n';
    return 0;
}
