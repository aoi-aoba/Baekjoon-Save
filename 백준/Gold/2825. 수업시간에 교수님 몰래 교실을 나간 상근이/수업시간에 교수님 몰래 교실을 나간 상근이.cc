// 수업시간에 교수님 몰래 교실을 나간 상근이
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int int64_t
using namespace std;

// all case : 0~9 on/off 2^10
int n, ans = 0, cnt[1 << 10];
string s;

int32_t main(void) {
    fastio;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        int t = 0;
        for (auto i : s)
            t |= 1 << (i - '0');
        // ex) "12" -> (1, 2) -> 0000000110 -> 6 for t
        cnt[t]++;
    }

    // brute-force (+ self i==j and duplicate for (i, j) and (j, i))
    for (int i = 0; i < 1 << 10; i++)
        for (int j = 0; j < 1 << 10; j++)
            if (i & j) ans += cnt[i] * cnt[j];
    
    // remove self i==j and duplications
    cout << (ans - n >> 1) << '\n';
    return 0;
}