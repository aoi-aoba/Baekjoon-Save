// 서강근육맨
#include <bits/stdc++.h>
#define fastio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
using namespace std;

int n;
vector<ll> v;

int main(void) {
    fastio();
    cin >> n;
    for (int i = 0; i < n; i++) {
        ll input; cin >> input;
        v.push_back(input);
    }

    sort(v.begin(), v.end());

    ll ans = -1;
    if (n % 2 == 1) {
        ans = v.back();
        v.pop_back();
    }

    int tot_size = v.size();
    for (int i = 0; i < (tot_size - 1) / 2; i++) {
        ll tmp = v[i] + v[tot_size - 1 - i];
        if (tmp > ans) ans = tmp;
    }

    cout << ans;
    return 0;
}