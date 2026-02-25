// 프랙탈과 점
#include <bits/stdc++.h>
#define ll long long
#define fastio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

int cs, n, k;
ll a, b;
string s, t;

auto make_ll(string s) {
    ll res = 0;
    for (char c : s) {
        if (c == '-' || c == '.') continue;
        res = 10 * res + c - '0';
    }
    if (s[0] == '-') res = -res;
    return res;
}

auto go(ll n, ll sz, ll x, ll y) {
    while (n--) {
        sz /= 3;
        if (x < 0 || x > 3 * sz || y < 0 || y > 3 * sz) return 0; // 바깥
        if (sz < x && x < sz * 2 && sz < y  && y < sz * 2) return 0; // 안
        if (x == 0 || x == sz || y == 0 || y == sz) return 1;
        if (x == sz && sz <= y && y <= sz * 2) return 1;
		if (y == sz && sz <= x && x <= sz * 2) return 1;
		if (x == sz * 2 && sz <= y && y <= sz * 2) return 1;
		if (y == sz * 2 && sz <= x && x <= sz * 2) return 1;
        if (x > sz) x -= sz;
        if (x > sz) x -= sz;
        if (y > sz) y -= sz;
        if (y > sz) y -= sz;
    }
    if (0 <= x && x <= sz && 0 <= y && y <= sz) return 1;
	return 0;
}

int main(void) {
    fastio();
    cin >> cs;

    while (cs--) {
        cin >> a >> b >> n >> k;
        cin >> s >> t;
        ll x = make_ll(s) - 1000 * a;
        ll y = make_ll(t) - 1000 * b;
        ll sz = 1000;
        for (int i = 0; i < k; i++) sz *= 3;
        cout << go(n, sz, x, y) << '\n';
    }

    return 0;
}