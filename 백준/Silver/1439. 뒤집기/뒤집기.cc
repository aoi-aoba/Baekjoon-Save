// 뒤집기
#include <bits/stdc++.h>
#define fastio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

char ch;
string s;
int ans[2] = {0, 0};

int main(void) {
    fastio();
    cin >> s;
    ch = s[0];

    for (int i = 1; i < s.size() - 1; i++) {
        if (ch != s[i]) {
            ans[ch - '0']++;
            ch = s[i];
        }
    }

    if (ch == s[s.size() - 1])
        ans[ch - '0']++;
    else {
        ans[0]++;
        ans[1]++;
    }

    cout << min(ans[0], ans[1]);
    return 0;
}