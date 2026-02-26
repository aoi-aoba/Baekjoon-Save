#include <bits/stdc++.h>
#define fastio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

string s;
string leftChars = "QAZWSXEDCRFVTGBY";
string rightChars = "UHNIJMOKPL";
int lft = 0, rht = 0, wild = 0;

int main(void) {
    fastio();
    getline(cin, s);

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') {
            wild++;
            continue;
        }
        bool Continue = false;
        if (s[i] <= 'Z') wild++;
        for (char ch : leftChars) {
            if (s[i] == ch || s[i] - 32 == ch) {
                lft++;
                Continue = true;
                break;
            }
        }
        if (Continue) continue;
        for (char ch : rightChars) {
            if (s[i] == ch || s[i] - 32 == ch) {
                rht++;
                break;
            }
        }
    }

    if (lft > rht) {
        int diff = lft - rht;
        rht += min(wild, diff);
        wild -= min(wild, diff);
    } else {
        int diff = rht - lft;
        lft += min(wild, diff);
        wild -= min(wild, diff);
    }

    rht += wild / 2;
    lft += wild - wild / 2;

    cout << lft << " " << rht;
    return 0;
}