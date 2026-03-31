// 포닉스와 달구
#include <bits/stdc++.h>
#define fastio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

int n, bSpace = 0, isSym = 1;
// 남은 칸이 2칸 이하면 차피 달구 승리 확정

int main(void) {
    fastio();
    cin >> n;
    vector<int> board(n);

    for (int i = 0; i < n; i++) {
        cin >> board[i];
        if (!board[i]) bSpace++;
    }

    if (bSpace <= 2) {
        cout << "DALGU";
        return 0;
    }

    for (int i = 0; i < n / 2; i++)
        if (board[i] != board[n - i - 1])
            isSym = 0;

    // n이 짝수일 때 대칭이면 포닉스가 둔 반대에 달구가 돌을 두어 항상 대칭.
    if (n % 2 == 0 && isSym) cout << "DALGU";
    // n이 홀수면 게임판이 초기에 대칭이며 가운데가 차 있어야 달구가 승리.
    else if (n % 2 == 1 && board[n / 2] && isSym) cout << "DALGU";
    else cout << "PONIX";

    return 0;
}