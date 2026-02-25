// !제곱수 순열
#include <bits/stdc++.h>
#define fastio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

// k와 k+1의 합 2k+1이 제곱수려면 홀수 s=2m+1에 대하여 2k+1=(2m+1)^2=4m^2+4m+1, k=2m(m+1) 꼴
// 그러면 k=4, 12, 24, 40, ... 위치에서는 제곱수가 되기 때문에 이 k를 경계로 구간을 뒤집으면 됨

int t, n;

int main(void) {
    fastio();
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> v(n + 1, 0);
        for (int i = 1; i <= n; i++) v[i] = i;
        for (int i = 1; ; i++) {
            // 경계는 2m(m+1) 꼴이므로 이전 경계는 2(i-1)i이고 현재 경계는 2i(i+1)
            int a = 2 * (i - 1) * i;
            int b = 2 * i * (i + 1);
            if (b >= n) break;
            reverse(v.begin() + a + 1, v.begin() + b + 1);
            // (a + 1, b] with reverse area for [start, end) 
        }
        for (int i = 1; i <= n; i++)
            cout << v[i] << ' ';
        cout << '\n';
    }

    return 0;
}