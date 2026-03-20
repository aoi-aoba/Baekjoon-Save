// 뱀
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int t, n, k, cnt, tempY, tempX, l, x;
int a[104][104], visited[104][104];
int dy[] = {0, 1, 0, -1};
int dx[] = {1, 0, -1, 0};
char c;
queue<pair<int, char>> turn, q;

bool check(pair<int, int> p) {
    if (p.first < 0 || p.second < 0 || p.first >= n || p.second >= n)
        return false;
    if (visited[p.first][p.second] == 1)
        return false;
    return true;
}

int main() {
    cin >> n >> k;

    for (int i = 0; i < k; i++) {
        cin >> tempY >> tempX;
        a[tempY-1][tempX-1] = 1;
    }

    cin >> l;
    for (int i = 0; i < l; i++) {
        cin >> x >> c;
        turn.push({x, c});
    }

    int flag = 0;
    q.push({0, 0});
    visited[0][0] = 1;

    while (true) {
        cnt++;
        int grow = 0;
        pair<int, int> next = {q.back().first + dy[flag], q.back().second + dx[flag]};

        if (check(next) == false) break;

        q.push(next);
        visited[next.first][next.second] = 1;

        if (turn.size() && cnt == turn.front().first) {
            if (turn.front().second == 'D')
                flag = (flag + 1) % 4;
            else flag = (flag + 3) % 4;
            turn.pop();
        }

        if (a[next.first][next.second] == 1) {
            a[next.first][next.second] = 0;
            grow = 1;
        }

        if (grow != 1) {
            visited[q.front().first][q.front().second] = 0;
            q.pop();
        }
    }

    cout << cnt << "\n";
}