// 사토르 마방진
#include <bits/stdc++.h>
#define fastio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

int n;
string brd[100];
bool check = 1;

int main(void) {
    fastio();
    cin >> n;
    for (int r = 0; r < n; r++)
        cin >> brd[r];

    for (int r = 0; r < n; r++)
        for (int c = r + 1; c < n; c++)
            if (brd[r][c] != brd[c][r])
                check = 0;
    
    if (check) cout << "YES";
    else cout << "NO";
    return 0;
}