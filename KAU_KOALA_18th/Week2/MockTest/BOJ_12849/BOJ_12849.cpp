#include <bits/stdc++.h>
#define MOD 1000000007

using namespace std;

int d;
long long dp[8], nxt[8];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    dp[0] = 1;
    
    cin >> d;
    for(int i = 0; i < d; i++) {
        nxt[0] = dp[1] + dp[2];
        nxt[1] = dp[0] + dp[2] + dp[3];
        nxt[2] = dp[0] + dp[1] + dp[3] + dp[4];
        nxt[3] = dp[1] + dp[2] + dp[4] + dp[5];
        nxt[4] = dp[2] + dp[3] + dp[5] + dp[6];
        nxt[5] = dp[3] + dp[4] + dp[7];
        nxt[6] = dp[4] + dp[7];
        nxt[7] = dp[5] + dp[6];
        
        // 모듈러 연산
        for(int i = 0; i < 8; i++)
            dp[i] = nxt[i] % MOD;
    }
    cout << dp[0];
    
    return 0;
}
