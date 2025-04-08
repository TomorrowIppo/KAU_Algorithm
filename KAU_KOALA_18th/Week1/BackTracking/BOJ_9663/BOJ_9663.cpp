#include <bits/stdc++.h>
#define MAX 15

using namespace std;

void solve();
void test();
void n_queen(int x);
bool check(int step);

int n, total = 0;
int col[MAX];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    //test();
    solve();
    
    return 0;
}

void solve() {
    cin >> n;
    n_queen(0); // 0번째 col부터 시작
    cout << total << '\n';
}

void test() {
    int t;
    cin >> t;
    
    while(t--) {
        // Init
        for(int i = 0; i < MAX; i++) col[i] = 0;
        total = 0;
        
        solve();
    }
}

void n_queen(int x) {
    if(x == n) total++;
    else {
        for(int i = 0; i < n; i++) {    // 0 ~ n-1행의 퀸을 의미
            col[x] = i; // (i, x)에 퀸을 배치
            if(check(x)) {  // 유효하면 그 다음 열에 대한 연산 진행, 아니면 다음 행(i+1, x)에 대해 체크
                n_queen(x + 1);
            }
        }
    }
}

bool check(int step) {
    for(int i = 0; i < step; i++)
        if(abs(col[step] - col[i]) == step - i || col[i] == col[step])
            return false;
    
    return true;
}
