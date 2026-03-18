// 데뷔의 꿈
#include <bits/stdc++.h>
#define fastio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

int b[13] = { 0, 20, 19, 21, 20, 21, 22, 23, 23, 23, 23, 23, 22 };
int v[13], n, m, d;

struct dte {
    int m, d;
    bool operator<(const dte& other) const {
        if (m == other.m) return d < other.d;
        return m < other.m;
    } 
};

vector<dte> ans;

int main(void) {
    fastio();

    for (int i = 0; i < 7; i++) {
        cin >> m >> d;
        
        if (d < b[m]) {
            m--;
            if (!m) m = 12;
        }
        
        v[m] = 1;
    }

    cin >> n;
    while (n--) {
        cin >> m >> d;
        if (d < b[m]) {
            int tmp = m - 1;
            if (!tmp) tmp = 12;
            if (!v[tmp]) ans.push_back({m, d});
        }
        else if (!v[m]) ans.push_back({m, d});
    }

    sort(ans.begin(), ans.end());
    
    if (ans.empty()) cout << "ALL FAILED";
    else for (const dte& dt : ans)
        cout << dt.m << " " << dt.d << "\n";

    return 0;
}