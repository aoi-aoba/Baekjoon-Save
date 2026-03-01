// 정점들의 거리
#include <bits/stdc++.h>
#define ll long long
#define fastio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

int n, m, u, v, w;
const int MAX = 40001;
const int LOG = 16;

ll dist[MAX]; // 루트부터 누적 가중치
bool visited[MAX];
int depth[MAX], parent[LOG][MAX];
// 루트 기준 깊이, 2^i번째 부모
vector<pair<int, int>> tree[MAX];

void dfs(int node, int prnt, int dph) {
    parent[0][node] = prnt; // 직계 부모
    depth[node] = dph; // 깊이

    for (auto [next, weight] : tree[node]) {
        if (next == prnt) continue;

        // root -> next의 거리 저장 후 dfs 계속 순회
        dist[next] = dist[node] + weight;
        dfs(next, node, dph + 1);
    }
}

int lca(int u, int v) {
    // 항상 u가 더 깊게 해서 깊이 차 계산
    if (depth[u] < depth[v]) swap(u, v);
    int diff = depth[u] - depth[v];

    // diff를 이진수로 분해하여 비트단위 계산, 그만큼 점프
    for (int k = 0; k < LOG; k++)
        if (diff & (1 << k)) u = parent[k][u];
    
    if (u == v) return u;
    
    // 동시 점프 (큰 점프부터, 부모 다를 때만)
    for (int k = LOG - 1; k >= 0; k--)
        if (parent[k][u] != parent[k][v])
            u = parent[k][u], v = parent[k][v];

    return parent[0][u];
}

ll getDist(int u, int v) {
    int lca_v = lca(u, v);
    return dist[u] + dist[v] - 2LL * dist[lca_v];
}

int main(void) {
    fastio();
    cin >> n;

    for (int i = 0; i < n - 1; i++) {
        cin >> u >> v >> w;
        tree[u].push_back({v, w});
        tree[v].push_back({u, w});
    }

    dist[1] = 0; // 루트를 1로 가정
    dfs(1, 0, 0);

    // 2^k번째 부모 = 2^(k-1)번째 부모의 2^(k-1)번째 부모
    for (int k = 1; k < LOG; k++) {
        for (int i = 1; i <= n; i++) {
            parent[k][i] = parent[k-1][ parent[k-1][i] ];
        }
    }

    cin >> m;
    while (m--) {
        cin >> u >> v;
        cout << getDist(u, v) << "\n";
    }

    return 0;
}