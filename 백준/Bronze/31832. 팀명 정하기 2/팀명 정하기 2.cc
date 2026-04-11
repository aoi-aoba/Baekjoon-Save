// 팀명 정하기 2
#include <bits/stdc++.h>
#define fastio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define ll long long
using namespace std;

bool ck1(string s) {
    ll bl = 0, sl = 0;
    for (char c : s) {
        if ('A' <= c && c <= 'Z') bl++;
        if ('a' <= c && c <= 'z') sl++;
    } return bl <= sl;
}

bool ck2(string s) {
    return s.length() <= 10;
}

bool ck3(string s) {
    for (char c : s)
        if (c < '0' || c > '9') return true;
    return false;
}

int main(void) {
    fastio();
    ll n;
    string s;
    cin >> n;
    for (ll i = 0; i < n; i++) {
        cin >> s;
        if (ck1(s) && ck2(s) && ck3(s)) {
            cout << s;
            return 0;
        }
    }
    return 0;
}