// 집합
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

using namespace std;

int m, t, s = 0;
string op;

void jaoba22() {
    cin >> op;
    if (op != "all" && op != "empty") cin >> t;

    if (op == "add") s |= (1 << t);
    else if (op == "remove") s &= ~(1 << t);
    else if (op == "check")
        cout << (s & (1 << t) ? 1 : 0) << "\n";
    else if (op == "toggle") s ^= (1 << t);
    else if (op == "all") s = (1 << 21) - 1;
    else if (op == "empty") s = 0;
}

int main(void) {
    fastio;
    cin >> m;
    while (m--) jaoba22();
    return 0;
}