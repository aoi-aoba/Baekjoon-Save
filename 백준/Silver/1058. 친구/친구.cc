// 친구

#include <bits/stdc++.h>
#define INF 1e9
#define fastio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

int n, adj[51][51];

int main(void) {
    fastio();

    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < n; j++) { // adj 거리 초기화
            if (i == j) adj[i][j] = 0;
            else if (s[j] == 'N') adj[i][j] = INF;
            else adj[i][j] = 1;
        }
    }

    // 플로이드-워셜 알고리즘 활용
    for (int k = 0; k < n; k++) 
        for (int i = 0; i < n; i++) 
            for (int j = 0; j < n; j++) 
                adj[i][j] = min(adj[i][j], adj[i][k] + adj[k][j]);

    int ans = 0;

    // 플로이드-워셜을 쓴 경우에 대하여 거리가 <= 2이면 2-친구임
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (int j = 0; j < n; j++)
            if (i != j && adj[i][j] <= 2)
                cnt++;
        ans = max(ans, cnt);
    }

    cout << ans;
    return 0;
}