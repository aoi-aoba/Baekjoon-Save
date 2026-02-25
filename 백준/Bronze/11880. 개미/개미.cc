// 개미

#include <bits/stdc++.h>
#define ll long long
#define fastio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

int main(void) {
    fastio();
    ll t, a, b, c;
    cin >> t;
    
    for (int i = 0; i < t; i++) {
        cin >> a >> b >> c;
        ll n1 = (a + b) * (a + b) + c * c;
        ll n2 = (a + c) * (a + c) + b * b;
        ll n3 = (b + c) * (b + c) + a * a;
        cout << min({n1, n2, n3}) << '\n';
    }
    
    return 0;
}