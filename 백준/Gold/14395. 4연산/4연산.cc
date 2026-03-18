// 4연산
#include <bits/stdc++.h>
#define ll long long
#define fastio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

ll s, t;

void bfs(ll s, ll t) {
    ll max = 1000000000ll;
    unordered_set<int> visited;
    queue<pair<ll, string>> q;

    q.push(make_pair(s, ""));
    visited.insert(s);

    while (!q.empty()) {
        auto [p, op] = q.front();
        q.pop();

        if (p == t) {
            cout << op;
            return;
        }

        if ((0 <= p * p && p * p <= max)
            && (visited.find(p * p) == visited.end())) {
                visited.insert(p * p);
                q.push(make_pair(p * p, op + "*"));
            }

        if ((0 <= p + p && p + p <= max)
            && (visited.find(p + p) == visited.end())) {
                visited.insert(p + p);
                q.push(make_pair(p + p, op + "+"));
            }
        
        if ((0 <= p - p && p - p <= max)
            && (visited.find(p - p) == visited.end())) {
                visited.insert(p - p);
                q.push(make_pair(p - p, op + "-"));
            }

        if ((p != 0 && 0 <= p / p && p / p <= max)
            && (visited.find(p / p) == visited.end())) {
                visited.insert(p / p);
                q.push(make_pair(p / p, op + "/"));
            }
    }

    cout << -1;
}

int main(void) {
    fastio();
    vector<string> opers;
    cin >> s >> t;

    if (s == t) {
        cout << 0;
        return 0;
    }

    bfs(s, t);
    return 0;
}