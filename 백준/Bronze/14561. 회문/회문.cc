#include <bits/stdc++.h>
#define fastio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define li long long int
using namespace std;

int n;
li a, b;

int main(void) {
    fastio();
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        vector<int> v;
        bool flag = false;

        while (true) {
            v.push_back(a % b);
            a /= b;
            if (a == 0) break;
        }

        vector<int>::iterator left, right;
        left = v.begin(), right = v.end() - 1;

        while (left <= right) {
            if (*left == *right) {
                left++, right--;
                continue;
            } else {
                flag = true;
                break;
            }
        }

        if (flag) cout << "0\n";
        else cout << "1\n";
    }

    return 0;
}