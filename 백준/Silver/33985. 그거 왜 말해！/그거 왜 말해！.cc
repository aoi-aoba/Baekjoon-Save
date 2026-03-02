// 그거 왜 말해!
#include <bits/stdc++.h>
#define fastio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

// 연산을 원하는 만큼 할 수 있다는 점에 착안하자
// 문자열은 무조건 A로 시작, B로 끝나야 함

int main(void) {
    fastio();
    int n;
    string t;
    cin >> n >> t;

    cout << (t.front() == 'A' && t.back() == 'B' ? "Yes" : "No");
    return 0;
}