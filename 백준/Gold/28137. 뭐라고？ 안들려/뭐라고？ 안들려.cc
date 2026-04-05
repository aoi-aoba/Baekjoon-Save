#include <bits/stdc++.h>
#define fastio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
using namespace std;

int n, k, x, y;
map<ll, int> pts;

int main(void) {
    fastio();
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        pts[y-(ll)k * x]++;
    }

    ll cnt = 0;
    for (auto itr = pts.begin(); itr != pts.end(); itr++)
        cnt += (ll)(itr->second)*(itr->second - 1);

    cout << cnt;
    return 0;
}