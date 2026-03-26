// 배고파(Hard)
#include <bits/stdc++.h>
#define fastio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
#define fs first
#define sc second
#define pii pair<int, int>
using namespace std;

ll n, m;

void jaoba22() {
    cin >> n;
    map<ll, pii> ma;
    for (int i = 0; i <= 60; i++)
        for (int j = 0; j <= i; j++) {
            ll tmp = (1ll << i) + (1ll << j);
            ma[tmp] = pii(j, i);
        }

    map<ll, pii>::iterator itr, lwr, upr;
    for (int i = 0; i < n; i++) {
        cin >> m;
        if ((itr = ma.find(m)) != ma.end()) // if exists,
            cout << itr->sc.fs << " " << itr->sc.sc << '\n';
        else {
            lwr = ma.upper_bound(m);
            if (lwr != ma.begin()) {
                upr = lwr--;
                if (abs(lwr->fs-m) <= abs(upr->fs-m))
                    cout << lwr->sc.fs << ' ' << lwr->sc.sc << '\n';
                else cout << upr->sc.fs << ' ' << upr->sc.sc << '\n';
            } else cout << "0 0\n"; 
        }
    }
}

int main(void) {
    fastio();
    jaoba22();
    return 0;
}