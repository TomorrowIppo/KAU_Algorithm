#include <bits/stdc++.h>
#define MAX 16

using namespace std;

int n, m, k;
int dp[MAX][MAX];

void test_print() {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            cout << dp[i][j] << ' ';
        }
        cout << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m >> k;
    
    int k_row = -1, k_col = -1, cnt = 1;
    bool flag = false;
    dp[1][1] = 1;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            if(cnt == k) { k_row = i; k_col = j; flag = true;}
            if(i + 1 < n + 1) dp[i + 1][j] += dp[i][j];
            if(j + 1 < m + 1) dp[i][j + 1] += dp[i][j];
            cnt++;
        }
    }
    if(flag) {
        cout << dp[k_row][k_col]*dp[n-k_row+1][m-k_col+1] << '\n';  // (1, 1) to (k_row, k_col) x (k_row, k_col) to (n, m)
    } else {
        cout << dp[n][m] << '\n';
    }
    //test_print();
    
    return 0;
}
