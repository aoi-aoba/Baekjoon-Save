#include <bits/stdc++.h>
#define fastio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
using namespace std;

ll Init(vector<ll> &arr, vector<ll> &tree, int n, int s, int e) {
    if (s == e) return tree[n] = arr[s];
    int m = (s + e) / 2;
    return tree[n] = Init(arr, tree, n * 2, s, m) + Init(arr, tree, n * 2 + 1, m + 1, e);
}

ll Sum(vector<ll> &tree, int n, int s, int e, int l, int r) {
    if (l > e || r < s) return 0;
    if (l <= s && e <= r) return tree[n];
    int m = (s + e) /2;
    return Sum(tree, n * 2, s, m, l, r) + Sum(tree, n * 2 + 1, m + 1, e, l, r);
}

void Update(vector<ll> &tree, int n, int s, int e, int idx, ll diff) {
    if (idx < s || idx > e) return;
    tree[n] = tree[n] + diff;
    if (s != e) {
        int m = (s + e) / 2;
        Update(tree, n * 2, s, m, idx, diff);
        Update(tree, n * 2 + 1, m + 1, e, idx, diff);
    }
}

int n, m, k;
ll op, b, c;

int main(void) {
    fastio();
    cin >> n >> m >> k;

    vector<ll> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    
    vector<ll> tree(4 * n);
    Init(arr, tree, 1, 0, n - 1);

    for (int i = 0; i < m + k; i++) {
        cin >> op >> b >> c;
        if (op == 1) {
            int tar_idx = b - 1;
            ll val = c, diff = val - arr[tar_idx];
            arr[tar_idx] = val;
            Update(tree, 1, 0, n - 1, tar_idx, diff);
        } else cout << Sum(tree, 1, 0, n - 1, b - 1, c - 1) << '\n';
    }

    return 0;
}