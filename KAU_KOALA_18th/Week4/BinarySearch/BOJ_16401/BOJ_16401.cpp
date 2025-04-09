#include <bits/stdc++.h>

using namespace std;

void solve();
int getCnt(int len, int N, int M, vector<int>& arr);

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    solve();

    return 0;
}

void solve() {
    int M, N;
    cin >> M >> N;

    vector<int> snack;
    for(int i = 0; i < N; i++) {
        int inp;
        cin >> inp;
        snack.push_back(inp);
    }
    sort(snack.begin(), snack.end());

    size_t left = 1, right = snack[N - 1];
    int ret = 0;
    while(left <= right) {
        size_t mid = (left + right) / 2;

        if(getCnt(mid, N, M, snack) >= M) {
            ret = mid;
            left = mid + 1;
        } else right = mid - 1;
    }
    cout << ret;
}

int getCnt(int len, int N, int M, vector<int>& arr) {
    int cnt = 0;

    for(int i = 0; i < N; i++) {
        cnt += arr[i] / len;
    }
    return cnt;
}