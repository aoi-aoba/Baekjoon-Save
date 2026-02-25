// PIZZA ALVOLOC

#include <bits/stdc++.h>
#define ll long long
#define fastio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

typedef pair<ll, ll> Point; // point P(x, y)

// 신발끈 공식을 활용한 CCW 알고리즘 행렬식 판별
ll ccw(Point p1, Point p2, Point p3) {
    ll ret = (p1.first * p2.second + p2.first * p3.second + p3.first * p1.second)
            - (p2.first * p1.second + p3.first * p2.second + p1.first * p3.second);
    if (ret < 0) return -1; // CW
    else if (ret > 0) return 1; // CCW
    else return 0;
}

int main(void) {
    fastio();
    
    ll x1, y1, x2, y2, x3, y3, x4, y4;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;
    
    Point a = {x1, y1}, b = {x2, y2}, c = {x3, y3}, d = {x4, y4};
    
    if (ccw(a, b, c) * ccw(a, b, d) < 0) cout << 1;
    else cout << 0;
    
    return 0;
}