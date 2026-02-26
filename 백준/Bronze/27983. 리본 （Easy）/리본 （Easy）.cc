// 리본 (Easy)
#include <bits/stdc++.h>
#define fastio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

int n, ribs[1010][3];

int main(void) {
    fastio();
    cin >> n;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < n; j++) {
            if (i != 2) cin >> ribs[j][i];
            else {
                char ch;
                cin >> ch;
                ribs[j][i] = (int)ch;
            }
        }
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ribs[i][2] != ribs[j][2]) {
                int dist = abs(ribs[i][0] - ribs[j][0]);
                int len = ribs[i][1] + ribs[j][1];
                if (dist <= len) {
                    cout << "YES\n";
                    cout << i + 1 << " " << j + 1 << "\n";
                    return 0;
                }
            } else continue;
        }
    }

    cout << "NO";
    return 0;
}