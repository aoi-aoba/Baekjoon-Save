// U-DeeP-See
#include <bits/stdc++.h>
#define fastio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

int N, K;

int main(void) {
    fastio();
    cin >> N >> K;

    vector<vector<int>> A(N, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> A[i][j];
        }
    }

    // K = 1이면 불가능
    if (K == 1) {
        cout << "LOSE\n";
        return 0;
    }

    vector<vector<int>> B = A;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i % K == 0 && j % K == 0)B[i][j] += 1;
            if (i % K == 1 && j % K == 0) B[i][j] -= 1;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << B[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}