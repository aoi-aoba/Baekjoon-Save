// 역시 내 이세계 수열은 잘못됐다 << 문제 이름 수준 ㅋㅋㅋㅋ
#include <bits/stdc++.h>
#define fastio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
using namespace std;

ll n, k, cnt = 0;

void jaoba22() {
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    for (int i = 0; i < n / 2; i++) {
        int tar = n - i - 1;
        if (a[i] != a[tar]) {
            ll big = max(a[i], a[tar]), small = min(a[i], a[tar]);
            ll cnt1 = (big - small) / k + (big - small) % k;
            ll divVal = (big - small) / k + 1;
            ll cnt2 = divVal + (k * divVal + small - big);
            cnt += min(cnt1, cnt2);
        }
    }

    cout << cnt;
}

int main(void) {
    fastio();
    cin >> n >> k;
    jaoba22();
    return 0;
}