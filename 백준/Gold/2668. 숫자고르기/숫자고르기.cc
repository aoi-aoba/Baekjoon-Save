// 숫자고르기
#include <bits/stdc++.h>
#define fastio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

int n, v;
int arr[101], visited[101];
bool inCycle[101];
vector<int> path;

void dfs(int u) {
    visited[u] = 1;
    path.push_back(u);
    
    int v = arr[u];
    if (visited[v] == 0) dfs(v); // 방문 X
    else if (visited[v] == 1) {
        // 탐색 중에 사이클을 발견 = 해당 사이클 요소들만 true로
        for (int i = path.size() - 1; i >= 0; i--) {
            inCycle[path[i]] = true;
            if (path[i] == v) break;
        }
    }

    visited[u] = 2;
    path.pop_back();
}

int main(void) {
    fastio();
    cin >> n;
    for (int u = 1; u <= n; u++) {
        cin >> v;
        arr[u] = v;
    }

    for (int i = 1; i <= n; i++)
        if (visited[i] == 0) dfs(i);

    vector<int> answer;
    for (int i = 1; i <= n; i++)
        if (inCycle[i]) answer.push_back(i);
    
    sort(answer.begin(), answer.end());
    cout << answer.size() << '\n';
    for (int x : answer) cout << x << '\n';

    return 0;
}