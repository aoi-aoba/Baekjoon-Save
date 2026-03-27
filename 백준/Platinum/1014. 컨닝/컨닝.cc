// 컨닝
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;

int c, n, m;
string s;

int bitcnt(int mask) {
    int val = 0;
    while (mask) {
        val += mask & 1;
        mask >>= 1;
    }
    return val;
}

void solve() {
    cin >> n >> m;
    vector<int> seat(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> s;
        int mask = 0;
        for (int j = 0; j < m; j++)
            if (s[j] == 'x') mask |= (1 << (m - j - 1));
        seat[i] = mask;
    }

    vector<vector<int>> dp(n + 1, vector<int>(1 << m, 0));
    for (int i = 1; i <= n; i++) {
        for (int cur = 0; cur < (1 << m); cur++) {
            // 좌우 인접하지 않고 앉을 수 없는 자리 뺀 거라면
            if ((cur & (cur << 1)) == 0 && (cur & seat[i]) == 0) {
                int best = 0;
                for (int prev = 0; prev < (1 << m); prev++) {
                    int msk = (prev << 1) | (prev >> 1);
                    // 대각선 영향 받는 자리 표시하고
                    if ((cur & msk) == 0) best = max(best, dp[i - 1][prev]);
                    // 안겹치면 너 best 자격 있어
                }
                dp[i][cur] = best + bitcnt(cur);
            }
        }
    }

    cout << *max_element(dp[n].begin(), dp[n].end()) << '\n';
}

int main(void) {
    fastio;
    cin >> c;
    while (c--) solve();
    return 0;
}