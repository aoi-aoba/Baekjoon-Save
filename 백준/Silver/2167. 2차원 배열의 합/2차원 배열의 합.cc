// 2차원 배열의 합
#include <bits/stdc++.h>
#define fastio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

int n, m, k;
int arr[301][301], sum[301][301];

void arrsum(void) {
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            sum[i][j] = sum[i-1][j] + sum[i][j-1] + arr[i][j] - sum[i-1][j-1];
}
int main(void) {
    fastio();
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> arr[i][j];

    arrsum();

    cin >> k;
    int i, j, x, y;

    while (k--) {
        cin >> i >> j >> x >> y;
        cout << sum[x][y] - sum[x][j-1] - sum[i-1][y] + sum[i-1][j-1] << '\n';
    }
    return 0;
}