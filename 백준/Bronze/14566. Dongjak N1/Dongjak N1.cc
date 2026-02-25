// Dongjak N1

#include <bits/stdc++.h>
#define fastio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

int main(void) {
    fastio();

    int n;
    cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());

    map<int, int> mp;
    for (int i = 1; i < n; i++) mp[a[i] - a[i-1]]++;
    cout << mp.begin() -> first << " " << mp.begin() -> second;

    return 0;
}