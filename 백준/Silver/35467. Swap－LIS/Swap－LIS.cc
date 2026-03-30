// Swap-LIS
#include <bits/stdc++.h>
#define fastio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

// LIS의 길이는 LIS일 때 감소할 수밖에 없고, 아닌 곳이 있으면 바꾸면 그만임

int n, arr[1000001];

int main(void) {
    fastio();
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> arr[i];

    bool ans = false;
    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[i + 1]) {
            cout << "YES\n";
            cout << i << " " << i + 1;
            return 0;
        }
    }

    cout << "NO";
    return 0;
}