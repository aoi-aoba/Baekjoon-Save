#include <bits/stdc++.h>
#define fastio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

int n, m, k;

int main(void) {
    fastio();
    cin >> n >> m >> k;
    int mat[n][m];

    int ki = 0, kj = 0, cnt = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!i || !j) mat[i][j] = 1;
            else mat[i][j] = mat[i-1][j] + mat[i][j-1];
            if (cnt == k) ki = i, kj = j;
            cnt++;
        }
    }

    cout << mat[ki][kj] * mat[n-ki-1][m-kj-1];
    return 0;
}