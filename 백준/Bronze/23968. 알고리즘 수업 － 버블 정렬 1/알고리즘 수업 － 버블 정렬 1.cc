// 알고리즘 수업 - 버블 정렬 1
#include <bits/stdc++.h>
#define fastio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

int n, k;

void jaoba22() {
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    int cnt = 0, ans = -1;
    for (int i = n - 1; i >= 0; i--)
        for (int j = 0; j < i; j++)
            if (a[j] > a[j + 1]) {
                cnt++;
                swap(a[j], a[j + 1]);
                if (cnt == k) {
                    cout << a[j] << ' ' << a[j + 1];
                    return;
                }
            }
    
    cout << ans;
    return;
}

int main(void) {
    fastio();
    jaoba22();
    return 0;
}