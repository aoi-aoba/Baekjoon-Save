// 악질 검거
#include <bits/stdc++.h>
#define fastio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

int n, m;
string name;

void jaoba22() {
    set<int> streaks;
    vector<pair<int, string>> lst;

    while (n--) {
        char cur, prev = '*';
        int max_streak = 0, rev = 0;
        
        for (int i = 0; i < m; i++) {
            cin >> cur;
            if (cur == '.') rev += 1;
            if (cur != prev && cur == '*') {
                max_streak = max(rev, max_streak);
                rev = 0;
            }
            prev = cur;
        }
        
        max_streak = max(rev, max_streak);
        cin >> name;
        lst.push_back({max_streak, name});
        streaks.insert(max_streak);
    }
    
    cout << streaks.size() << '\n';
    for (auto elem: lst) cout << elem.first << ' ' << elem.second << '\n';
}

int main(void) {
    fastio();
    cin >> n >> m;
    jaoba22();
    return 0;
}