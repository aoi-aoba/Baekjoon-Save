// 내려가기
#include <bits/stdc++.h>
#define fastio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

int n;
int preM[3] = {0, 0, 0}; // 최대
int prem[3] = {0, 0, 0}; // 최소

int main(void) {
    fastio();
    cin >> n;

    for (int i = 0; i < n; i++) {
        int n1, n2, n3;
        cin >> n1 >> n2 >> n3;
        
        int curM[3], curm[3];
        curM[0] = n1 + max(preM[0], preM[1]);
        curM[1] = n2 + max({preM[0], preM[1], preM[2]});
        curM[2] = n3 + max(preM[1], preM[2]);

        curm[0] = n1 + min(prem[0], prem[1]);
        curm[1] = n2 + min({prem[0], prem[1], prem[2]});
        curm[2] = n3 + min(prem[1], prem[2]);

        for (int j = 0; j < 3; j++) {
            preM[j] = curM[j];
            prem[j] = curm[j];
        }
    }
    
    cout << max({preM[0], preM[1], preM[2]}) << ' ' << min({prem[0], prem[1], prem[2]});
    return 0;
}