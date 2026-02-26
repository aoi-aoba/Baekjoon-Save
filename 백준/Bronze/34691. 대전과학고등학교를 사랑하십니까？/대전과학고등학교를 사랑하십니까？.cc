// 대전과학고등학교를 사랑하십니까?
#include <bits/stdc++.h>
#define fastio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

string answer(string prob) {
    if (prob == "animal") return "Panthera tigris";
    else if (prob == "tree") return "Pinus densiflora";
    else return "Forsythia koreana";
}

string input;

int main(void) {
    fastio();
    cin >> input;
    while (input != "end") {
        cout << answer(input) << '\n';
        cin >> input;
    }

    return 0;
}