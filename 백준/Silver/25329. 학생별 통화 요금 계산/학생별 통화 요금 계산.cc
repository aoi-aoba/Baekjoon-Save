// 학생별 통화 요금 계산
#include <bits/stdc++.h>
#define fastio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define fs first
#define sc second
using namespace std;

int n;
string s_t, s_n;
unordered_map<string, int> sdts;

int calc(int t) {
    return 10 + (max(0, t - 100) + 49) / 50 * 3;
}

bool cmp(const pair<string, int> &a, const pair<string, int> &b) {
    if (a.sc != b.sc) return a.sc > b.sc;
    return a.fs < b.fs;
}

void jaoba22() {
    cin >> n;
    while (n--) {
        cin >> s_t >> s_n;
        sdts[s_n] += stoi(s_t.substr(0, 2)) * 60 + stoi(s_t.substr(3, 2));
    }

    vector<pair<string, int>> ans;
    for (auto &p : sdts) ans.push_back({p.first, calc(p.sc)});
    sort(ans.begin(), ans.end(), cmp);

    for (auto &p : ans) cout << p.fs << ' ' << p.sc << "\n";
}

int main(void) {
    fastio();
    jaoba22();
    return 0;
}