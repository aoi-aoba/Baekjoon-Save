// 별 찍기 11
#include <bits/stdc++.h>
#define ll long long
#define fastio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

bool print(ll n, ll x, ll y) {
    if (n == 3) {
        if (x == 0 && y == 2) return true;
        if (x == 1 && y % 2 == 1) return true;
        if (x == 2) return true;
        return false;
    }

    if (x < n / 2) {
        if (y < n / 2 || y >= 2 * n - n / 2 - 1) return false;
        return print(n / 2, x, y - n / 2);
    }

    if (x >= n / 2) {
        if (y == n - 1) return false;
        if (y < n - 1) return print(n / 2, x - n / 2, y);
        else return print(n / 2, x - n / 2, y - n);
    }
}

int main(void) {
    fastio();
    ll n; cin >> n;
    for (ll i = 0; i < n; i++) {
        for (ll j = 0; j < 2 * n - 1; j++) {
            if (print(n, i, j)) cout << '*';
            else cout << ' ';
        }
        cout << '\n';
    }

    return 0;
}