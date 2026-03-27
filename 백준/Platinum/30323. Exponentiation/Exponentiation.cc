// Exponentiation
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ui128 unsigned __int128
#define ull unsigned long long
using namespace std;

// Assume that f_n = x^n + 1 / x^n -> f_0 = 2, f_1 = a
// f_2n = (f_n)^2 - 2 (mod m) by f_2 = (f_1)^2 - 2 = a^2 - 2
// f_2np1 = (f_n)(f_np1) - (f_1) (mod m) by f_3 = (f_2)(f_1) - f_1

ull aph, bet, mod; // positive less than 2^64

int get_msb(ull n) {
    if (n == 0) return -1;
    for (int i = 63; i >= 0; i--)
        if ((n >> i) & 1) return i;
    return 0;
}

void solve() {
    if (bet == 1) {
        cout << (ull)(aph % mod) << '\n';
        return;
    }

    int msb = get_msb(bet);
    ui128 f_n = 2, f_np1 = aph % mod;
    // prevent negative-modulo calc by using (A + m - B) % m
    for (int i = msb; i >= 0; i--) {
        if ((bet >> i) & 1) { // n -> 2n + 1
            ui128 nxt_f_n = (f_n * f_np1 + mod - (aph % mod)) % mod;
            ui128 nxt_f_np1 = (f_np1 * f_np1 + mod - 2) % mod;
            f_n = nxt_f_n, f_np1 = nxt_f_np1;
        } else { // n -> 2n
            ui128 nxt_f_n = (f_n * f_n + mod - 2) % mod;
            ui128 nxt_f_np1 = (f_n * f_np1 + mod - (aph % mod)) % mod;
            f_n = nxt_f_n, f_np1 = nxt_f_np1;
        }
    }

    cout << (ull)(f_n % mod) << '\n';
}

int main(void) {
    fastio;
    cin >> aph >> bet >> mod;
    solve();
    return 0;
}