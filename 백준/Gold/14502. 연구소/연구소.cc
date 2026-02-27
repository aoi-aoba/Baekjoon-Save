// 연구소
#include <bits/stdc++.h>
#define pos pair<int, int>
#define fastio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

int n, m, board[8][8], temp[8][8];
int dr[4] = {-1, 1, 0, 0}, dc[4] = {0, 0, -1, 1};
vector<pos> empty_v, virus_v;

int bfs() {
    queue<pos> q;
    memcpy(temp, board, sizeof(board));
    for (auto v : virus_v) q.push(v);
    
    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i], nc = c + dc[i];
            if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
            if (temp[nr][nc] != 0) continue;
            
            temp[nr][nc] = 2;
            q.push({nr, nc});
        }
    }

    int safe = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (temp[i][j] == 0) safe++;

    return safe;
}

int main(void) {
    fastio();
    cin >> n >> m;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            if (board[i][j] == 0) empty_v.push_back({i, j});
            else if (board[i][j] == 2) virus_v.push_back({i, j});
        }
    }

    int ans = 0;

    for (int i = 0; i < empty_v.size(); i++) {
        for (int j = i + 1; j < empty_v.size(); j++) {
            for (int k = j + 1; k < empty_v.size(); k++) {
                auto [r1, c1] = empty_v[i];
                auto [r2, c2] = empty_v[j];
                auto [r3, c3] = empty_v[k];
                
                board[r1][c1] = board[r2][c2] = board[r3][c3] = 1;
                ans = max(ans, bfs());
                board[r1][c1] = board[r2][c2] = board[r3][c3] = 0;
            }
        }
    }

    cout << ans;
    return 0;
}