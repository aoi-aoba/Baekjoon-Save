// 연속부분최대곱
#include <bits/stdc++.h>
#define fastio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

int n;
double arr[10101], dp[10101];

int main(void) {
    fastio();
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    dp[0] = arr[0];
    double ans = dp[0];

    for (int i = 1; i < n; i++) {
        dp[i] = max(arr[i], dp[i - 1] * arr[i]);
        ans = max(ans, dp[i]);
    }
    
    cout << fixed << setprecision(3) << ans;
    return 0;
}