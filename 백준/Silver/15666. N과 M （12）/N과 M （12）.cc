// N과 M (12)
#include <bits/stdc++.h>
#define fastio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

int n, m;
int ans[9] = {0, }, pre[9] = {0, };
vector<int> v;

void print(void) {
    for (int i = 0; i < m; i++)
        cout << ans[i] << " ";
    cout << '\n';
}

void seq(int x, int len) {
    if (m == len) {
        print();
        return;
    }
    int temp = 0;
    for (int i = x; i < v.size(); i++) {
        if (v[i] != temp) {
            ans[len] = v[i];
            temp = ans[len];
            seq(i, len + 1);
        }
    }
}

int main(void) {
    fastio();
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(), v.end());
    seq(0, 0);
    return 0;
}