// 사각지대
#include <bits/stdc++.h>
#define fastio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define PI 3.1415926535897932
using namespace std;

double w, h, r;

int main(void) {
    fastio();
    cin >> w >> h >> r;
    cout << w * h - PI * r * r * 0.25;
    return 0;
}