// 미션 도네이션
#include <bits/stdc++.h>
#define fastio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
using namespace std;

ll arr[100][3], k, d, a, n;

int main(void) {
    fastio();
    cin >> n;

    while (n--) {
        ll ans = 0, m;
        cin >> m;

        for (int i = 0; i < m; i++)
            cin >> arr[i][0] >> arr[i][1] >> arr[i][2];

        cin >> k >> d >> a;

        for (int i = 0; i < m; i++)
            ans += max(arr[i][0] * k - arr[i][1] * d + arr[i][2] * a, 0ll);
        
        cout << ans << '\n';
    }

    return 0;
}