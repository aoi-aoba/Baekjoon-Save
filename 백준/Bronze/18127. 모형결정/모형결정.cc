// 모형결정
#include <bits/stdc++.h>
#define fastio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
using namespace std;

int main(void) {
    fastio();
    ll a, b;
    cin >> a >> b;
    ll minCristal = ((b + 1) * (2 + b * (a - 2))) / 2;
    cout << minCristal;
    return 0;
}