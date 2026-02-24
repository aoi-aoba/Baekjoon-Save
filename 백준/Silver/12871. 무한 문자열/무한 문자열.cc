#include <bits/stdc++.h>
#define fastio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

int main(void) {
    fastio();
    string sa, sb;
    cin >> sa >> sb;
    
    if (sa + sb == sb + sa) cout << 1;
    else cout << 0;

    return 0;
}