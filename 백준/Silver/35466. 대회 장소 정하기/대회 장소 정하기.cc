// 대회 장소 정하기
#include <bits/stdc++.h>
#define fastio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

int dist(int a, int b, int N) {
    int d = abs(a - b);
    return min(d, N - d);
}

int N, a, b, c, p, q;

int main() {
    cin >> N >> a >> b >> c >> p >> q;
    int U = 0;

    for (int x : {a, N - a}) {
        x %= N;
        for (int sign : {1, -1}) {
            int y = (x + sign * b) % N;
            if (y < 0) y += N;
            if (dist(U, y, N) != c) continue;

            for (int t : {p, N - p}) {
                t %= N;
                if (dist(x, t, N) != q) continue;
                cout << dist(y, t, N);
                return 0;
            }
        }
    }
}