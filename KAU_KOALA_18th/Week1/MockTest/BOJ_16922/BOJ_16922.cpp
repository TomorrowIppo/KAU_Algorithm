/*
 1, 5, 10, 50의 덧셈으로 만들어지는 경우 중 중복제거를 하면 됨
 */
#include <bits/stdc++.h>

using namespace std;

int n, cnt = 0;
bool vis[1001];
vector<int> item = {1, 5, 10, 50};

void solve();
void bt(int level, int idx, int total);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    solve();
    
    return 0;
}

void solve() {
    cin >> n;
    bt(0, 0, 0);
    cout << cnt << '\n';
}

// 중복조합
void bt(int level, int idx, int total) {
    if(level == n) {
        if(!vis[total]) { vis[total] = true; cnt++;}   // 만들어진 조합의 합이 없는 경우
        return;
    } else {
        for(int i = idx; i < 4; i++) {
            bt(level + 1, i, total + item[i]);
        }
    }
}
