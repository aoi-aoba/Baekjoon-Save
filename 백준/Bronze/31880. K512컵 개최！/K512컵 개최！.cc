// K512컵 개최!
#include <bits/stdc++.h>
#define fastio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
using namespace std;

int n, m;

void solve() {
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int j = 0; j < m; j++) cin >> b[j];

    ll ans = 0;
    for (auto elem: a) ans += elem;
    for (auto elem: b) {
        if (elem == 0) continue;
        ans *= elem;
    }
    cout << ans;
}

int main(void) {
    fastio();
    solve();
    return 0;
}