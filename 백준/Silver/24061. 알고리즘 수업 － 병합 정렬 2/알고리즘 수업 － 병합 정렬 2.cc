// 알고리즘 수업 - 병합 정렬 2
#include <bits/stdc++.h>
#define fastio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

int n, k, cnt;
vector<int> v;

void prt() {
    for (int i = 0; i < n; i++)
        cout << v[i] << ' ';
}

void mrg(int s, int e, int m) {
    int buf[n], l = s, r = m + 1, idx = s;
    while (l <= m && r <= e) {
        if (v[l] < v[r]) buf[idx++] = v[l++];
        else buf[idx++] = v[r++];
    }

    while (l <= m) buf[idx++] = v[l++];
    while (r <= e) buf[idx++] = v[r++];

    for (int i = s; i <= e; i++) {
        v[i] = buf[i];
        if (++cnt == k) prt();
    }
}

void mrgsort(int s, int e) {
    if (s >= e) return;
    int m = (s + e) / 2;
    mrgsort(s, m);
    mrgsort(m + 1, e);
    mrg(s, e, m);
}

int main(void) {
    fastio();
    cin >> n >> k;
    
    int num;
    for (int i = 0; i < n; i++) {
        cin >> num;
        v.push_back(num);
    }

    mrgsort(0, n - 1);
    if (cnt < k) cout << -1;
    return 0;
}