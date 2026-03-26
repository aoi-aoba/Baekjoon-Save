// Rick-Roll Virus
#include <bits/stdc++.h>
#define fastio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

bool jaoba22() {
    int never, gonna, give;
    cin >> never >> gonna >> give;
    string you; cin >> you;
    string up = you;

    for (int i = 0; i < never; i++) {
        if (you[i] != 'R') continue;
        for (int j = max(0, i - give); j <= min(never - 1, i + give); j++)
            up[j] = 'R';
    }

    return count(up.begin(), up.end(), 'R') <= gonna;
}

int main(void) {
    fastio();
    cout << (jaoba22() ? "Yes" : "No");
    return 0;
}