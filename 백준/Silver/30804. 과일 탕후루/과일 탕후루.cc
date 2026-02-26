// 과일 탕후루
#include <bits/stdc++.h>
#define fastio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

int n, fruits[202020];

int main(void) {
    fastio();
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> fruits[i];

    unordered_map<int, int> fruit_cnt;
    int lft = 0, ans = 0;

    // 오른쪽을 확장해나가면서 map에 개수를 관리
    for (int rht = 0; rht < n; rht++) {
        fruit_cnt[fruits[rht]]++;

        // 과일 개수가 2개를 초과한다면 왼쪽을 줄이는 방식으로 연장
        while (fruit_cnt.size() > 2) {
            fruit_cnt[fruits[lft]]--;
            if (fruit_cnt[fruits[lft]] == 0)
                fruit_cnt.erase(fruits[lft]);
            lft++;
        }

        ans = max(ans, rht - lft + 1);
    }

    cout << ans;
    return 0;
}