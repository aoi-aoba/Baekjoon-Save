// XOR 방정식
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
using namespace std;

ll s, x;
// a+b=(a^b)+2(a&b), so s=x+2(a&b); a&b=(s-x)/2

ll cnt(ll x) {
    int cnt = 0;
    while (x) {
        x &= (x - 1);
        cnt++;
    }
    return cnt;
}

ll jaoba22() {
    // s - x = 2k >= 0 (for integer k)
    if (s < x || (s - x) % 2) return 0;

    ll and_v = (s - x) / 2;
    // x=a^b (diff bit) a&b (same bit), so x&(a&b)==0
    if (and_v & x) return 0;

    ll ans = 1ll << cnt(x);
    // 0 is not positive number
    if (s == x) ans -= 2;
    return ans;
}

int main(void) {
    fastio;
    cin >> s >> x;
    cout << jaoba22();
    return 0;
}