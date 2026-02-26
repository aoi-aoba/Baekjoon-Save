// 마인크래프트
#include <bits/stdc++.h>
#define ll long long
#define fastio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

int n, m, b;
int minh = 2100000000, maxh = 0, time_min = 2100000000;
int height = -1, ret_time = 0, tmp_block, field[500][500];
double sum = 0;

int main(void) {
    fastio();
    cin >> n >> m >> b;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> field[i][j];
            maxh = max(maxh, field[i][j]);
            minh = min(minh, field[i][j]);
        }
    }

    int build = 0, remove = 0;
    
    for (int h = minh; h <= maxh; h++) {
        build = remove = 0;

        // 특정 높이 h에 대하여 각 칸의 '설치 블록' 개수와 '회수 블록' 개수 측정
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                tmp_block = field[i][j];
                if (h > tmp_block) build += h - tmp_block;
                if (h < tmp_block) remove += tmp_block - h;
            }
        }

        // 설치할 블록 개수는 회수 블록 + 인벤토리 기존 개수보다 적어야 함
        if (build <= remove + b) { 
            ret_time = remove * 2 + build;
            if (time_min >= ret_time) {
                if (height > h) continue;
                time_min = ret_time;
                height = h;
            }
        }
    }

    cout << time_min << " " << height << "\n";
    return 0;
}