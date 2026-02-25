// 회전하는 큐

#include <bits/stdc++.h>
#define fastio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

int n, m, lft, rht, cnt = 0;
deque<int> dq;

int main(void) {
    fastio();
    cin >> n >> m;
	for(int i = 1; i <= n; i++) dq.push_back(i);
	
	while (m--) {
		int num;
		cin >> num;
		
        // 뽑으려는 수의 위치가 왼쪽과 오른쪽 중 어디에 더 가까운가?
		for(int i = 0; i < dq.size(); i++) {
			if (dq[i] == num) {
				lft = i;
				rht = dq.size()-i;
				break;
			}
		}
		
        // 이동 횟수가 더 적은 방향으로 push, pop 실행
		if(lft <= rht){
			while (true) {
				if (dq.front() == num) break;
				dq.push_back(dq.front());
				dq.pop_front();
				cnt++;
			}
			dq.pop_front();
		}
		
        // push, pop 횟수보다 이동 횟수가 더 높음
		else {
			cnt++;
			while (true) {
				if(dq.back() == num) break;
				dq.push_front(dq.back());
				dq.pop_back();
				cnt++;
			}
			dq.pop_back();
		}
	}
	
	cout << cnt;
	return 0;
}