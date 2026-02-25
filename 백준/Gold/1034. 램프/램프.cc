// 램프

#include <bits/stdc++.h>
#define fastio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

string input, rows[50];
int n, m, k, board[50][50];

int main(void) {
    fastio();
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> input;
        rows[i] = input;
        for (int j = 0; j < m; j++)
            board[i][j] = input[j] - '0';
    }
    cin >> k;

    int max_rows = 0;
    for (int i = 0; i < n; i++) { // 기준 행을 잡아서
        // 꺼진 램프 확인
        int zero_count = 0;
        for (int j = 0; j < m; j++)
            if (board[i][j] == 0) zero_count++;

        // 행 켤 조건 : 꺼진 램프 개수 K 이하 + (K-zero) 짝수
        if (zero_count <= k && zero_count % 2 == k % 2) {
            int cur_patt_cnt = 0;
            for (int j = 0; j < n; j++) {
                if (rows[j] == rows[i]) cur_patt_cnt++;
            }
            max_rows = max(max_rows, cur_patt_cnt);
        }
    }

    cout << max_rows;
    return 0;
}