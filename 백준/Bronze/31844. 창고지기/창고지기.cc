// 창고지기
#include <bits/stdc++.h>
#define fastio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

string str;
int s, f, b;

int main(void) {
    fastio();
    
    cin >> str;
    for (int i = 0; i < 10; i++) {
        if (str[i] == '@') s = i;
        if (str[i] == '#') b = i;
        if (str[i] == '!') f = i;
    }

    if (s < b && b < f) cout << f - s - 1;
    else if (f < b && b < s) cout << s - f - 1;
    else cout << -1;

    return 0;
}