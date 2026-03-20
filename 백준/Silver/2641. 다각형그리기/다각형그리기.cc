// 다각형그리기
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

int n, t, cnt = 0;
int def[50], rdef[50], inp[50];
vector<string> v;

string arrToStr(int arr[]) {
    string s = "";
    for (int i = 0; i < n; i++)
        s += to_string(arr[i]) + ",";
    return s;
}

int main() {
    fastio;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> def[i];
        rdef[n - i - 1] = (def[i] <= 2) ? def[i] + 2 : def[i] - 2;
    }

    string defd = arrToStr(def) + arrToStr(def);
    string rdefd = arrToStr(rdef) + arrToStr(rdef);

    cin >> t;
    while (t--) {
        for (int i = 0; i < n; i++)
            cin >> inp[i];
        string inpStr = arrToStr(inp);

        if (defd.find(inpStr) != string::npos ||
            rdefd.find(inpStr) != string::npos) {
            
            cnt++;
            string ret = "";
            for (int i = 0; i < n; i++)
                ret += to_string(inp[i]) + " ";
            v.push_back(ret);
        }
    }

    cout << cnt << '\n';
    for (auto s : v) cout << s << '\n';
}