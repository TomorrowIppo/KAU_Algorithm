#include <bits/stdc++.h>
#define MAX 100001

using namespace std;

int arr[2][MAX];
int dp[2][MAX];

void solve();

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    solve();
    
    return 0;
}

void solve() {
    int T;
    cin >> T;
    
    while(T--) {
        // input
        int n;
        cin >> n;
        
        for(int i = 0; i < 2; i++)
            for(int j = 1; j <= n; j++)
                cin >> arr[i][j];
        
        // DP
        dp[0][1] = arr[0][1];
        dp[1][1] = arr[1][1];
        
        for(int i = 2; i <= n; i++) {
            dp[0][i] = arr[0][i] + max(dp[1][i - 2], dp[1][i - 1]);
            dp[1][i]=  arr[1][i] + max(dp[0][i - 2], dp[0][i - 1]);
        }
        
        int ans = max(dp[0][n], dp[1][n]);
        cout << ans << '\n';
    }
}
