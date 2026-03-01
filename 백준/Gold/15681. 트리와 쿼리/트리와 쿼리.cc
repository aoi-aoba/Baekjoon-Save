// 트리와 쿼리
#include <bits/stdc++.h>
#define fastio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

const int MAX = 101010;

int n, r, q, u, v;
vector<int> tree[MAX];
int sz[MAX];

void dfs(int node, int parent) {
    sz[node] = 1; // 자기 자신을 포함
    for (int nxt : tree[node]) {
        if (nxt == parent) continue;
        dfs(nxt, node);
        sz[node] += sz[nxt];
    }
}

int main() {
    fastio();
    cin >> n >> r >> q;

    for (int i = 0; i < n - 1; i++) {
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }

    dfs(r, 0); // r은 루트, 부모 0번 노드는 없음

    while (q--) {
        cin >> u;
        cout << sz[u] << '\n';
    }
}