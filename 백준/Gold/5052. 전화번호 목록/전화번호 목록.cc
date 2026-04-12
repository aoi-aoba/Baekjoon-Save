// 전화번호 목록
#include <bits/stdc++.h>
#define fastio() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0)
using namespace std;

int toIdx(char ch) {
    return ch - '0';
}

struct Trie {
    Trie* child[10];
    bool isEnd, hasChild;

    Trie() : isEnd(false), hasChild(false) {
        memset(child, 0, sizeof(child));
    } // nullptr 초기화

    ~Trie() { // memory leak 방지
        for (int i = 0; i < 10; i++) 
            if (child[i]) delete child[i];
    }

    bool insert(const char* key) {
        // 문자열 삽입 끝(\0)인데 자식이 있다면 이미 누군가의 접두어
        if (*key == '\0') {
            isEnd = true;
            return !hasChild;
        }

        // 삽입 중인데 누군가 끝인 번호가 있으면 접두어
        if (isEnd) return false;

        int nxt = *key - '0'; // 숫자로 바꾸고
        if (!child[nxt]) { // 해당 숫자로 가는 길 없으면
            child[nxt] = new Trie(); // 새로 만들어서
            hasChild = true; // 자식 있으니 true
        }

        return child[nxt] -> insert(key + 1);
        // 문자열 포인터에 1을 더해 다음 글자 들고 자식 노드로 이동
    }
};

int t, n;
string s;

int main(void) {
    fastio();
    cin >> t;

    while (t--) {
        Trie* root = new Trie();
        cin >> n;

        vector<string> v(n);
        for (int i = 0; i < n; i++) cin >> v[i];
        sort(v.begin(), v.end());

        bool isConsist = true;
        for (int i = 0; i < n; i++) {
            if (isConsist && !root->insert(v[i].c_str())) 
                isConsist = false;
        }

        if (isConsist) cout << "YES\n";
        else cout << "NO\n";

        delete root;
    }
    
    return 0;
}