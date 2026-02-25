// 제곱수 찾기

#include <bits/stdc++.h>
#define fastio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

string s;
int n, m, arr[10][10];

bool is_square(int num) {
    int root = (int)sqrt(num);
    return root * root == num;
}

int main(void) {
    fastio();
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        cin >> s;
        for (int j = 0; j < m; j++)
            arr[i][j] = s[j] - '0';
    }

    int ans = -1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int x = -n; x < n; x++) { // 행등차
                for (int y = -m; y < m; y++) { // 열등차
                    if (x == 0 && y == 0) continue; // 무한루프 방지
                    int a = i, b = j, res = 0;
                    // 범위 내에서 움직이면서
                    while (a >= 0 && a < n && b >= 0 && b < m) {
                        res = res * 10 + arr[a][b];
                        if (is_square(res) && res > ans) 
                            ans = res;
                        a += x;
                        b += y; // 등차만큼 표 이동
                    }
                }
            }
        }
    }

    cout << ans;
    return 0;
}