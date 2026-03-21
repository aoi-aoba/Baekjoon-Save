// 좋은수열
#include <bits/stdc++.h>
#define fastio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

int n;

bool good_seq(string s) {
    int len = s.size();
    // 바로 옆에 있는 같은 수만큼의 substring 비교
    for (int i = 1; i <= len / 2; i++)
        if (s.substr(len - i, i) == s.substr(len - 2 * i, i))
            return false;
    return true;
}

void tracker(string s) {
    if (s.size() == n) {
        cout << s;
        exit(0);
    }

    // 어차피 1, 2, 3 순서로 가면 사전순 최소는 보장됨
    for (char c = '1'; c <= '3'; c++) {
        string nxt = s + c;
        if (good_seq(nxt)) tracker(nxt);
    }
}

int main(void) {
    fastio();
    cin >> n;
    tracker("");
    return 0;
}