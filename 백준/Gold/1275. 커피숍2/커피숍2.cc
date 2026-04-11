#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
using namespace std;

ll stinit(vector<ll> &arr, vector<ll> &tree, int node, int start, int end) {
    if (start == end) return tree[node] = arr[start];
    // 노드가 리프 노드인 경우 배열의 그 원소를 가져야 함
    int mid = (start + end) / 2;
    // 구간 합을 구하는 경우
    return tree[node] = stinit(arr, tree, node * 2, start, mid)
                        + stinit(arr, tree, node * 2 + 1, mid + 1, end);
}

// 합을 구한 left~right, 노드가 담당하는 구간 start~end
ll stsum(vector<ll> &tree, int node, int start, int end, int left, int right) {
    // case 1: [start, end] 앞과 뒤에 [left, right]가 있는 경우 겹치지 않음
    if (left > end || right < start) return 0;
    // case 2: [start, end]가 [left, right]에 포함됨
    if (left <= start && end <= right) return tree[node];
    // case 3(교집합이 left, right)인 경우, case 4(나머지)
    int mid = (start + end) / 2;
    return stsum(tree, node * 2, start, mid, left, right)
            + stsum(tree, node * 2 + 1, mid + 1, end, left, right);
}

// 수 변경
void stupdate(vector<ll> &tree, int node, int start, int end, int index, ll diff) {
    if (index < start || index > end) return; // [start, end]에 index가 없음
    tree[node] = tree[node] + diff;

    if (start != end) {
        int mid = (start + end) / 2;
        stupdate(tree, node * 2, start, mid, index, diff);
        stupdate(tree, node * 2 + 1, mid + 1, end, index, diff);
    }
}

int n, q, x, y, a;
ll b;

int main(void) {
    fastio;
    cin >> n >> q;
    
    vector<ll> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    vector<ll> tree(4 * n);
    stinit(arr, tree, 1, 0, n - 1);

    while (q--) {
        cin >> x >> y >> a >> b;
        if (x > y) swap(x, y);
        // 0-base index
        cout << stsum(tree, 1, 0, n - 1, x - 1, y - 1) << "\n";

        ll diff = b - arr[a - 1];
        arr[a - 1] = b;
        stupdate(tree, 1, 0, n - 1, a - 1, diff);
    }

    return 0;
}