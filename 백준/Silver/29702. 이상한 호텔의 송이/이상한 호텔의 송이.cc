// 이상한 호텔의 송이
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
using namespace std;

ll t, n;

void jaoba22() {
    cin >> n;
    
    ll lev = 0;
    for (int i = 1; i <= 60; i++) {
        if (n <= (1ll << i) - 1) {
            lev = i;
            break;
        }
    }

    ll idx = n - ((1ll << (lev - 1)) - 1);
    while (lev >= 1) {
        printf("%lld%018lld\n", lev, idx);
        idx = (idx + 1) / 2;
        lev--;
    }
}

int main(void) {
    fastio;
    cin >> t;
    while (t--) jaoba22();
    return 0;
}