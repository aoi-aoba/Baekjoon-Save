// 월드컵
#include <bits/stdc++.h>
#define fastio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

vector<pair<int, int>> games;
int target[6][3], res[6][3]; // {승, 무, 패}
bool possible;

void dfs(int idx) {
    if (possible) return;
    if (idx == 15) {
        possible = true;
        return;
    }
    
    int a = games[idx].first;
    int b = games[idx].second;

    // a 승, b 패
    if (res[a][0] + 1 <= target[a][0] && res[b][2] + 1 <= target[b][2]) {
        res[a][0]++, res[b][2]++;
        dfs(idx + 1);
        res[a][0]--, res[b][2]--;        
    }
    // 무승부
    if (res[a][1] + 1 <= target[a][1] && res[b][1] + 1 <= target[b][1]) {
        res[a][1]++, res[b][1]++;
        dfs(idx + 1);
        res[a][1]--, res[b][1]--;        
    }
    // b 승, a 패
    if (res[a][2] + 1 <= target[a][2] && res[b][0] + 1 <= target[b][0]) {
        res[a][2]++, res[b][0]++;
        dfs(idx + 1);
        res[a][2]--, res[b][0]--;        
    }
}

int main(void) {
    fastio();
    // 전체 게임 경우의 수 {0, 1} ~ {4, 5}
    for (int i = 0; i < 6; i++)
        for (int j = i + 1; j < 6; j++)
            games.push_back({i, j});
    
    // 입력처리
    for (int t = 0; t < 4; t++) {
        int totWin = 0, totLose = 0, totSum = 0;
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 3; j++) {
                cin >> target[i][j];
                res[i][j] = 0;
                totSum += target[i][j];
            }
            totWin += target[i][0];
            totLose += target[i][2];
        }

        possible = false;
        // 경기 수가 현실적으로 가능한 경우만
        if (totSum == 30 && totWin == totLose) dfs(0);
        cout << (possible ? 1 : 0) << " ";
    }

    cout << '\n';
    return 0;
}