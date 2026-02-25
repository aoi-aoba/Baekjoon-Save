// 태상이의 훈련소 생활
#include <bits/stdc++.h>
#define ll long long
#define fastio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

int n, m, a, b, k, high[101010], diff[101010];

int main(void) {
    fastio();
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> high[i];

    // 차분 배열
    while (m--) {
        cin >> a >> b >> k;
        diff[a - 1] += k;
        if (b < n) diff[b] -= k;
    }
    
    // 누적합
    for (int i = 1; i < n; i++)
        diff[i] = diff[i - 1] + diff[i];

    // 최종 적용 및 출력
    for (int i = 0; i < n; i++) {
        high[i] += diff[i];
        cout << high[i] << ' ';
    }
    cout << '\n';

    return 0;
}