// 승강장의 깊이
#include <bits/stdc++.h>
#define fastio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

int main(void) {
    fastio();
    int n, cur_a = 0, cur_b = 0, a, b;
    cin >> n;
    while (n--) {
        cin >> a >> b;
        cur_a += a;
        cur_b += b;
        cout << cur_a - cur_b << '\n';
    }

    return 0;
}