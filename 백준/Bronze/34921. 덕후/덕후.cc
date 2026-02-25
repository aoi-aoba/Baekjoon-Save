// 덕후

#include <bits/stdc++.h>
#define fastio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

int main(void) {
    fastio();
    int a, t, p;
    cin >> a >> t;
    p = 10 + 2 * (25 - a + t);

    if (p < 0) cout << 0;
    else cout << p;
    return 0;
}