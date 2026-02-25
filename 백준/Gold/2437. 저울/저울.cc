// 저울

#include <bits/stdc++.h>
#define fastio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

int n, sum = 0, arr[1010];

int main(void) {
    fastio();

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr+1010);
    
    for (int item : arr) {
        if (sum + 2 <= item) break;
        sum += item;
    }
    cout << sum + 1;

    return 0;
}