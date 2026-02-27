// 최소 스패닝 트리
#include <bits/stdc++.h>
#define ll long long
#define fastio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

struct Edge {
    int u, v;
    ll w;
    bool operator<(const Edge &other) const {
        return w < other.w;
    }
};

int v, e, a, b, parent[101010];
ll w;
vector<Edge> edges;

int Find(int x) {
    if (parent[x] == x) return x;
    return parent[x] = Find(parent[x]);
}

bool Union(int x, int y) {
    x = Find(x), y = Find(y);
    if (x != y) {
        parent[y] = x;
        return true;
    }
    return false;
}

int main(void) {
    fastio();
    cin >> v >> e;

    for (int i = 0; i < e; i++) {
        cin >> a >> b >> w;
        edges.push_back({a, b, w});
    }

    sort(edges.begin(), edges.end());
    for (int i = 0; i <= v; ++i) parent[i] = i;

    ll cost = 0;
    int cnt = 0;

    for (auto &edge : edges) {
        if (Union(edge.u, edge.v)) {
            cost += edge.w;
            cnt++;
            if (cnt == v - 1) break;
        }
    }

    cout << cost;

    return 0;
}