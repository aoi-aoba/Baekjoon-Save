// 알프수
#include <bits/stdc++.h>
#define fastio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

string s;
vector<int> v;

bool jaoba22() {
    for (int i = 0; i <= v.size() - 1; i++)
        if (v[i] == 0) return false;
    if (v[0] < 0 || v.back() > 0) return false;
    for (int i = 0; i <= v.size() - 2; i++)
        if ((v[i] > 0 && v[i + 1] > 0) || (v[i] < 0 && v[i + 1] < 0))
            if (v[i] != v[i + 1]) return false;
    return true;
}

int main(void) {
    fastio();
    cin >> s;

    for (int i = 0; i <= s.size() - 2; i++)
        v.push_back(s[i + 1] - s[i]);
    
    cout << (jaoba22() ? "ALPSOO" : "NON ALPSOO");
    return 0;
}