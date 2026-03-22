// 피보나치
#include <bits/stdc++.h>
#define fastio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

int t, n, idx;
vector<int> v;

void precompute() {
    v.push_back(1);
    v.push_back(2);

    while (true) {
        int sz = v.size();
        int next = v[sz-1] + v[sz-2];
        if (next > 1e9) break;
        v.push_back(next);
    }
}

void solve() {
    cin >> n;
    vector<int> ans;
    idx = v.size() - 1;
    
    while (n > 0) {
        if (v[idx] <= n) {
            ans.push_back(v[idx]);
            n -= v[idx];
        }
        idx--;
    }

    for (int i = ans.size() - 1; i >= 0; i--)
        cout << ans[i] << ' ';
    cout << '\n';
}

int main(void) {
    fastio();
    cin >> t;
    precompute();
    while (t--) solve();
    return 0;
}