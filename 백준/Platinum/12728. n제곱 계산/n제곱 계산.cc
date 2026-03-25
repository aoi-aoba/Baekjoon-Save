// n제곱 계산
#include <bits/stdc++.h>
#define fastio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
#define pin pair<int, int>
#define fs first
#define sc second

using namespace std;

// why math again fuuuuuuuck
// (3 + sqt(5))^n = a + bsqt(5), (3 - sqt(5))^n = a - bsqt(5)
// (3 + sqt(5))^n + (3 - sqt(5))^n = 2a
// (3 - sqt(5))^n < 1, so int((3 + sqt(5))^n) = 2a - 1

ll t, n;

pin cal(int n) {
    if (n == 1) return {3, 1};
    pin x = cal(n / 2);
    pin ret = {(x.fs * x.fs + x.sc * x.sc * 5) % 1000,
               2 * x.fs * x.sc % 1000}; // (a+bsqt(5))^2 = a^2+5b^2 + 2ab
    
    if (n % 2) return {(ret.fs * 3 + ret.sc * 5) % 1000, (ret.fs + 3 * ret.sc) % 1000};
    else return ret;
}

void solve(int caseN) {
    cin >> n;
    pin x = cal(n);
    int ans = (x.fs * 2 - 1) % 1000;
    string s = to_string(ans);

    if (s.length() == 1) s = "00" + s;
    else if (s.length() == 2) s = "0" + s;
    cout << "Case #" << caseN << ": " << s << "\n";
}

int main(void) {
    fastio();
    cin >> t;
    for (int i = 1; i <= t; i++) solve(i);
    return 0;
}