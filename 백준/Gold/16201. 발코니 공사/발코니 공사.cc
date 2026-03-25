// 발코니 공사
#include <bits/stdc++.h>
#define fastio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long

using namespace std;

const int mod = 1e9+7;

typedef struct {
    ll R, C;
} pos;
pos arr[1000];

int comp(const void* m, const void* n) {
    pos a = *(pos*)m, b = *(pos*)n;
    if (a.R == b.R) return a.C - b.C;
    else return a.R - b.R;
}

int bound(int s, int e, ll k, bool isup) {
    while (s < e) {
        int m = (s + e) / 2;
        if (isup) {
            if (arr[m].R <= k) s = m + 1;
            else e = m;
        } else {
            if (arr[m].R < k) s = m + 1;
            else e = m;
        }
    } return e;
}

ll pow_mod(ll x, ll y) {
    ll ret = 1;
    while (y) {
        if (y % 2) ret = ret * x % mod;
        x = x * x % mod;
        y /= 2;
    }
    return ret;
}

ll r, c, k;

int main(void) {
    fastio();
    cin >> r >> c >> k;
    for (int i = 0; i < k; i++)
        cin >> arr[i].R >> arr[i].C;
    qsort(arr, k, sizeof(pos), comp);

    ll cnt_totR = r, cnt_t = 0, way_t = 1;
    for (int i = 0; i < k; i++) {
        int upper = bound(0, k - 1, arr[i].R, true);
        int lower = bound(0, k - 1, arr[i].R, false);
        if (arr[lower].R == arr[upper].R) upper++;

        for (int j = lower; j < upper; j++) {
            int len = (j == lower) ? arr[lower].C - 1 : arr[j].C - arr[j-1].C - 1;
            way_t = (len % 2) ? (way_t * ((len / 2) + 1) % mod) : way_t;
            cnt_t += len / 2;
        }

        int last_len = c - arr[upper - 1].C;
        way_t = (last_len % 2) ? (way_t * ((last_len / 2) + 1) % mod) : way_t;
        cnt_t += last_len / 2;

        i = upper - 1;
        cnt_totR -= 1;
    }

    int way_totT = (c % 2) ? c / 2 + 1 : 1;
    cnt_t += cnt_totR * (c / 2);
    way_t = way_t * pow_mod(way_totT, cnt_totR) % mod;

    cout << cnt_t << ' ' << way_t;
    return 0;
}