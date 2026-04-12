// 접두사 찾기 (with prefix)
#include <bits/stdc++.h>
#define fastio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

const int ALPHA_SIZE = 26;

int getIdx(char ch) {
    return ch - 'a';
}

struct Trie {
    Trie* child[ALPHA_SIZE];

    Trie() { memset(child, 0, sizeof(child)); }

    void insert(const char* key) {
        if (*key == '\0') return;

        int nxt = getIdx(*key);
        if (!child[nxt]) // 자식 없으면 생성
            child[nxt] = new Trie();

        child[nxt] -> insert(key + 1);
    }
    
    bool find(const char* key) {
        // 끝까지 무사히 도착하면 접두사
        if (*key == '\0') return true;
        int nxt = getIdx(*key);
        if (!child[nxt]) return false; // 끊기면 접두사 아님
        return child[nxt] -> find(key + 1);
    }
};

int n, m, ans = 0;
string s;

int main(void) {
    fastio();
    cin >> n >> m;

    Trie* root = new Trie();
    while (n--) {
        cin >> s;
        root->insert(s.c_str());
    }

    while (m--) {
        cin >> s;
        if (root->find(s.c_str())) ans++;
    }

    cout << ans;
    return 0;
}