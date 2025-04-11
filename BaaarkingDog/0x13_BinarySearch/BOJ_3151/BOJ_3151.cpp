/*
10
2 -5 2 3 -4 7 -4 0 1 -6


*/


#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> level;

void input();
void solve();

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    input();
    solve();

    return 0;
}

void input() {
    cin >> N;
    for(int i = 0; i < N; i++) {
        int inp; cin >> inp;
        level.push_back(inp);
    }
    sort(level.begin(), level.end());
}

void solve() {
    long long ans = 0LL;
    for(int i = 0; i < N; i++) {
        for(int j = i + 1; j < N - 1; j++) {
            int target = level[i] + level[j];

            auto lo = lower_bound(level.begin() + j + 1, level.end(), -target);
            auto hi = upper_bound(level.begin() + j + 1, level.end(), -target);

            ans += hi - lo;
        }
    }
    cout << ans;
}