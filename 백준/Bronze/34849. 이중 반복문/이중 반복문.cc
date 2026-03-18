// 이중 반복문
#include <bits/stdc++.h>
#define fastio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

int input;

int main(void) {
    fastio();
    cin >> input;
    if (input <= 10000) cout << "Accepted";
    else cout << "Time limit exceeded";
    return 0;
}